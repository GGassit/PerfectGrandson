#pragma once

#undef CALLBACK

class Callback;

class CallbackManager : public Singleton<CallbackManager>
{
public:
	std::vector<Callback*> callbacks = {};

	void RegisterCallback(Callback* item)
	{
		callbacks.push_back(item);
	}

	void RemoveCallback(Callback* item)
	{
		callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), item), callbacks.end());
	}

	void Invoke(const std::string& period);
};

class Callback
{
public:
	const std::string functionName = "";
	const std::string period = "Default";
	const bool disposable = false;
	bool invoked = false;

	Callback() = default;

	Callback(const std::string& functionName, const std::string& period, bool disposable = false)
		: functionName(functionName), period(period), disposable(disposable)
	{
		CallbackManager::Get()->RegisterCallback(this);
	}

	Callback(const std::string& period, bool disposable = false)
		: functionName(std::string(XOR("Internal Callback"))), period(period), disposable(disposable)
	{
		CallbackManager::Get()->RegisterCallback(this);
	}

	bool operator==(const Callback& other) const
	{
		return functionName == other.functionName;
	}

	virtual void Invoker() = 0;
};

class GlobalFunctionCallback : public Callback
{
public:
	std::function<void()> function = {};

	GlobalFunctionCallback() = default;

	GlobalFunctionCallback(const std::string& functionName, const std::string& period, std::function<void()> function, bool disposable = false)
		: function(function), Callback(functionName, period, disposable) {}

	void Invoker() override
	{
		function();
	}
};

void CallbackManager::Invoke(const std::string& period)
{
	for (auto& item : callbacks)
	{
		if (item->period == period)
		{
			item->Invoker();
			item->invoked = true;
		}
	}

	callbacks.erase(std::remove_if(callbacks.begin(), callbacks.end(), [](Callback* item) { return item->disposable && item->invoked; }), callbacks.end());
}

#define CALLBACK(functionName, period) \
	void functionName();\
	namespace { GlobalFunctionCallback functionName##CallbackItem(#functionName, period, functionName); }\
	void functionName()

#define	DISPOSABLE_CALLBACK(functionName, period) \
	void functionName();\
	namespace { GlobalFunctionCallback functionName##CallbackItem(#functionName, period, functionName, true); }\
	void functionName()
