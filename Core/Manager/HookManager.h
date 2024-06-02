#pragma once

class HookManager : public Singleton<HookManager>
{
public:
	class Item
	{
	private:
		void* target = nullptr;
		void* detour = nullptr;
		void** original = nullptr;

	public:
		bool hooked = false;
		std::string hookName = std::string();

		Item() = default;

		Item(std::string name, void* detour, void** original) : hookName(name), detour(detour), original(original)
		{
			HookManager::Get()->RegisterItem(this);
		}

		bool Hook(void* target)
		{
			this->target = target;
			MH_STATUS status = MH_CreateHook(target, detour, original);
			if (status != MH_OK)
			{
				//Console::Get()->AddMessage(Message(NaUtils::Format(XOR("Fail to create the hook at %s, because %s !"), hookName.c_str(), MH_StatusToString(status)), ImVec4(0.8f, 0.0f, 0.0f, 1.f)));
				return false;
			}
			status = MH_EnableHook(target);
			if (status != MH_OK)
			{
				return false;
			}
			hooked = true;
			return true;
		}

		bool UnHook()
		{
			MH_STATUS status = MH_DisableHook(target);
			if (status != MH_OK)
			{
				return false;
			}
			status = MH_RemoveHook(target);
			if (status != MH_OK)
			{
				return false;
			}
			return true;
		}
	};
public:
	std::vector<Item*> items = {};

	void RegisterItem(Item* item)
	{
		items.push_back(item);
	}

	bool UnhookAll()
	{
		for (const auto& item : items)
		{
			if (!item->UnHook())
			{
				return false;
			}
		}
		return true;
	}

	~HookManager() { UnhookAll(); }
};
SINGLETON_ACTIVATE(HookManager);

#define RAW_HOOK(_returnType, _funcName, ...) \
	_returnType _funcName(__VA_ARGS__);             \
	using _funcName##Fn = decltype(&_funcName);     \
	inline _funcName##Fn o##_funcName = nullptr;    \
	inline HookManager::Item hi##_funcName = HookManager::Item(#_funcName, _funcName, reinterpret_cast<void **>(&o##_funcName)); \

#define HOOK(_returnType, _funcName, ...) \
		RAW_HOOK(_returnType, _funcName, __VA_ARGS__) \
		inline _returnType _funcName(__VA_ARGS__)