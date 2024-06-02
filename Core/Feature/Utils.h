#pragma once

namespace Utils
{
	std::string Format(std::string format, ...)
	{
		va_list args;
		va_start(args, format);
		char buffer[1024];
		vsnprintf(buffer, 1024, format.c_str(), args);
		va_end(args);
		return std::string(buffer);
	}

	std::string Join(std::vector<std::string> values, std::string separator)
	{
		std::string result;
		for (size_t i = 0; i < values.size(); i++)
		{
			result += values[i];
			if (i < values.size() - 1)
			{
				result += separator;
			}
		}
		return result;
	}

	bool TryParse(std::string value, int& result)
	{
		try
		{
			result = std::stoi(value);
			return true;
		}
		catch (std::exception)
		{
			return false;
		}
	}

	bool TryParse(std::string value, float& result)
	{
		try
		{
			result = std::stof(value);
			return true;
		}
		catch (std::exception)
		{
			return false;
		}
	}

	bool TryParse(std::string value, double& result)
	{
		try
		{
			result = std::stod(value);
			return true;
		}
		catch (std::exception)
		{
			return false;
		}
	}

	bool TryParse(std::string value, bool& result)
	{
		if (value == XOR("true") || value == XOR("1"))
		{
			result = true;
			return true;
		}
		else if (value == XOR("false") || value == XOR("0"))
		{
			result = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool TryParse(std::string value, ImVec4& result)
	{
		std::regex regex(XOR(R"(\((\d+\.\d+), (\d+\.\d+), (\d+\.\d+), (\d+\.\d+)\))"));
		std::smatch match;
		if (!std::regex_match(value, match, regex))
		{
			return false;
		}
		if (!TryParse(match[1].str(), result.x))
		{
			return false;
		}
		if (!TryParse(match[2].str(), result.y))
		{
			return false;
		}
		if (!TryParse(match[3].str(), result.z))
		{
			return false;
		}
		if (!TryParse(match[4].str(), result.w))
		{
			return false;
		}
		return true;
	}

	bool TryParse(std::string value, void*& result)
	{
		if (value == XOR("nullptr") || value == XOR("0") || value == XOR("NULL"))
		{
			result = nullptr;
			return true;
		}
		if (value.find(XOR("0x")) == 0)
		{
			try
			{
				result = (void*)std::stoull(value, nullptr, 16);
				return true;
			}
			catch (std::exception)
			{
				return false;
			}
		}
		else
		{
			return TryParse(XOR("0x") + value, result);
		}
		return false;
	}

	template<typename T>
	T RandomRange(T min, T max)
	{
		return min + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (max - min)));
	}

	template<typename T>
	class RandomWeightItem
	{
	public:
		RandomWeightItem(T value, float weight) : value(value), weight(weight) {}
		T value;
		float weight;
	};

	template<typename T>
	T RandomItem(std::vector<RandomWeightItem<T>> values)
	{
		float totalWeight = 0;
		for (auto& item : values)
		{
			totalWeight += item.weight;
		}
		float random = RandomRange<float>(0, totalWeight);
		for (auto& item : values)
		{
			if (random < item.weight)
			{
				return item.value;
			}
			random -= item.weight;
		}
		return values[values.size() - 1].value;
	}
}