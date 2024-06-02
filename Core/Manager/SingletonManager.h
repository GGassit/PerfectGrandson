#pragma once
#include <unordered_map>
#include <functional>
#include <string>

// SingleInstanceManager class
class SingletonManager
{
public:
	class Item
	{
	public:
		const std::string typeName;
		void* instance;
		std::function<void(void*)> deleter;
		bool destructionIgnore = false;

		template <typename T>
		Item(const std::string& typeName, T* instance, bool nonparticipationInDestruction)
			: typeName(typeName), instance(instance), deleter([](void* ptr) { delete static_cast<T*>(ptr); }), destructionIgnore(nonparticipationInDestruction)
		{
		}

		bool IsCreated() const
		{
			return instance != nullptr;
		}

		void Free()
		{
			if (instance)
			{
				deleter(instance);
				instance = nullptr;
			}
		}
	};
public:
	std::unordered_map<std::string, Item> instances;

	template <bool destructionIgnore = false, typename T, typename... Args>
	T* Create(Args&&... args)
	{
		const std::string typeName = typeid(T).name();
		T* newInstance = new T(std::forward<Args>(args)...);
		instances.emplace(typeName, Item(typeName, newInstance, destructionIgnore));
		return newInstance;
	}

	template <typename T, typename... Args>
	T* Get(Args&&... args)
	{
		const std::string typeName = typeid(T).name();
		auto it = instances.find(typeName);
		if (it != instances.end())
		{
			return static_cast<T*>(it->second.instance);
		}

		return Create<false, T, Args...>(std::forward<Args>(args)...);
	}

	template <typename T>
	void Destroy()
	{
		const std::string typeName = typeid(T).name();
		auto it = instances.find(typeName);
		if (it != instances.end())
		{
			it->second.Free();
			instances.erase(it);
		}
	}

	template <typename T>
	const Item& GetItem() const
	{
		const std::string typeName = typeid(T).name();
		auto it = instances.find(typeName);
		if (it != instances.end())
		{
			return it->second;
		}

		static const Item emptyItem("", nullptr);
		return emptyItem;
	}

	void DestroyAll()
	{
		for (auto& instance : instances)
		{
			if (instance.second.destructionIgnore)
				continue;
			instance.second.Free();
		}
	}
};

inline SingletonManager singletonManager = SingletonManager();

template <typename T, bool destructionIgnore = false>
class Singleton
{
public:
	template <typename... Args>
	static T* Get(Args&&... args)
	{
		return singletonManager.Get<T>(std::forward<Args>(args)...);
	}

	template <typename... Args>
	static T* Create(Args&&... args)
	{
		return singletonManager.Create<destructionIgnore, T>(std::forward<Args>(args)...);
	}

	static void Destroy()
	{
		singletonManager.Destroy<T>();
	}

	static bool IsCreated()
	{
		return singletonManager.GetItem<T>().IsCreated();
	}

	static bool IsDestroyed()
	{
		return !IsCreated();
	}
};

#define SINGLETON_ACTIVATE(T, ...) namespace __Singleton_Helper_Namespace_::ActivateInstance::__Helper__##T { T* singleton = T::Create(__VA_ARGS__); }

#define SINGLETON_ACTIVATE_FAST(T, ...) namespace __Singleton_Helper_Namespace_::ActivateInstance::__Helper__##T { T* singleton = Singleton<T>::Create(__VA_ARGS__); }