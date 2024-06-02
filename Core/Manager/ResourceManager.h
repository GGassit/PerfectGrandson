#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

class Resource
{
private:
	class CreateCallback : public Callback
	{
	public:
		Resource* resource = {};

		CreateCallback(Resource* resource) : resource(resource), Callback(resource->initializePeriod, true) {}

		void Invoker() override
		{
			resource->Create();
		}
	};
public:
	const std::string suffix = "";
	const int id = 0;
	const std::string initializePeriod = "";
	CreateCallback createCallback = CreateCallback(this);

	HRSRC info = nullptr;
	HGLOBAL handle = NULL;
	void* originalData = nullptr;
	size_t size = 0;

	Resource(const std::string& suffix, const int& id, const std::string& initializePeriod = XOR("Dll Initialize"));

	virtual bool Create()
	{
		HMODULE module = Application::Get()->internal.module;
		info = FindResourceA(module, MAKEINTRESOURCEA(id), suffix.c_str());
		if (!info)
			return false;
		handle = LoadResource(module, info);
		if (!handle)
			return false;
		originalData = LockResource(handle);
		size = SizeofResource(module, info);
		return true;
	}

	virtual void Release()
	{
		if (handle)
			FreeResource(handle);
		handle = NULL;
		originalData = nullptr;
		size = 0;
	}

	bool IsLoaded() const { return size > 0; }
};

class FontTTF : public Resource
{
public:
	FontTTF(const int& id) : Resource(XOR("ttf"), id) {}
};

class Image : public Resource
{
public:
	int width = 0;
	int height = 0;
	int channels = 0;
	ID3D11ShaderResourceView* shaderResourceView = nullptr;

	Image(const std::string& suffix, const int& id) : Resource(suffix, id, XOR("ImGui Frame")) { }

	bool Create() override
	{
		if (!Resource::Create())
			return false;

		stbi_uc* data = stbi_load_from_memory((stbi_uc*)originalData, size, &width, &height, &channels, 4);
		if (!data)
			return false;

		D3D11_TEXTURE2D_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.Width = width;
		desc.Height = height;
		desc.MipLevels = 1;
		desc.ArraySize = 1;
		desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.SampleDesc.Count = 1;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		desc.CPUAccessFlags = 0;

		ID3D11Texture2D* pTexture = NULL;
		D3D11_SUBRESOURCE_DATA subResource;
		subResource.pSysMem = data;
		subResource.SysMemPitch = desc.Width * 4;
		subResource.SysMemSlicePitch = 0;
		Application::Get()->renderer.device->CreateTexture2D(&desc, &subResource, &pTexture);

		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
		ZeroMemory(&srvDesc, sizeof(srvDesc));
		srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MipLevels = desc.MipLevels;
		srvDesc.Texture2D.MostDetailedMip = 0;
		Application::Get()->renderer.device->CreateShaderResourceView(pTexture, &srvDesc, &shaderResourceView);
		pTexture->Release();

		stbi_image_free(data);
		return true;
	}

	void Release() override
	{
		if (shaderResourceView)
			shaderResourceView->Release();
		shaderResourceView = nullptr;
		Resource::Release();
	}
};

class ImagePNG : public Image
{
public:
	ImagePNG(const int& id) : Image(XOR("png"), id) {}
};

class ResourceManager : public Singleton<ResourceManager>
{
public:
	std::vector<Resource*> resources = {};

	ResourceManager() {}

	~ResourceManager()
	{
		for (auto& resource : resources)
			resource->Release();
	}

	void Add(Resource* resource)
	{
		resources.push_back(resource);
	}
};
SINGLETON_ACTIVATE(ResourceManager);

Resource::Resource(const std::string& suffix, const int& id, const std::string& initializePeriod)
	: suffix(suffix), id(id), initializePeriod(initializePeriod), createCallback(this)
{
	ResourceManager::Get()->Add(this);
}