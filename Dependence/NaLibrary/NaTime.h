#pragma once

#include <filesystem>
#include <sstream>

class NaTime
{
private:
	int64_t timestamp = 0ll;
	static int64_t GetCurrentSystemTimestamp()
	{
		auto now = std::chrono::system_clock::now().time_since_epoch();
		return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
	}
public:
	NaTime() = default;
	NaTime(int64_t timestamp) : timestamp(timestamp) {}
	NaTime(const NaTime& time) : timestamp(time.timestamp) {}

	static NaTime Now()
	{
		return NaTime(GetCurrentSystemTimestamp());
	}

	static NaTime GetFileLastWriteTime(const std::filesystem::path& path)
	{
		return NaTime(std::filesystem::last_write_time(path).time_since_epoch().count() / 1000000);
	}

	int64_t GetTimestamp() const
	{
		return timestamp;
	}

	int64_t GetElapsedTime() const
	{
		return GetCurrentSystemTimestamp() - timestamp;
	}

	std::string ToString(std::string format = XOR("%d-%m-%Y %H:%M:%S")) const
	{
		if (timestamp == 0ll)
			return "";

		std::time_t tt = timestamp / 1000;
		std::tm tm;
		localtime_s(&tm, &tt);

		std::stringstream ss;
		char buffer[100];
		strftime(buffer, sizeof(buffer), format.c_str(), &tm);
		ss << buffer;
		return ss.str();
	}

	NaTime operator+(const NaTime& other) const
	{
		return NaTime(timestamp + other.timestamp);
	}

	NaTime operator-(const NaTime& other) const
	{
		return NaTime(timestamp - other.timestamp);
	}

	operator int64_t() const
	{
		return timestamp;
	}

	bool operator==(const NaTime& other) const
	{
		return timestamp == other.timestamp;
	}

	bool operator==(const int64_t& other) const
	{
		return timestamp == other;
	}
};

class NaTimeSpan
{
private:
	int64_t timespan = 0ll;
public:
	NaTimeSpan() = default;
	NaTimeSpan(int64_t timespan) : timespan(timespan) {}
	NaTimeSpan(const NaTime& start, const NaTime& end) : timespan(end - start) {}
	NaTimeSpan(const NaTimeSpan& timespan) : timespan(timespan.timespan) {}

	int64_t GetTimespan() const
	{
		return timespan;
	}

	float ToMilliseconds() const
	{
		return (float)timespan;
	}

	float ToSeconds() const
	{
		return (float)timespan / 1000.0f;
	}

	float ToMinutes() const
	{
		return (float)timespan / 60000.0f;
	}

	float ToHours() const
	{
		return (float)timespan / 3600000.0f;
	}

	float ToDays() const
	{
		return (float)timespan / 86400000.0f;
	}

	NaTimeSpan operator+(const NaTimeSpan& other) const
	{
		return NaTimeSpan(timespan + other.timespan);
	}

	NaTimeSpan operator-(const NaTimeSpan& other) const
	{
		return NaTimeSpan(timespan - other.timespan);
	}

	operator int64_t() const
	{
		return timespan;
	}

	bool operator==(const NaTimeSpan& other) const
	{
		return timespan == other.timespan;
	}

	bool operator==(const int64_t& other) const
	{
		return timespan == other;
	}
};