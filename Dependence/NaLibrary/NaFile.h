#pragma once
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

class NaFileBase
{
private:
	fs::path filePath;
public:
	NaFileBase(fs::path filePath) : filePath(filePath) {}
};

class NaFileReader : public NaFileBase
{
private:
	std::ifstream file = std::ifstream();
public:
	NaFileReader() : NaFileBase(fs::path()) {}
	NaFileReader(fs::path filePath) : NaFileBase(filePath)
	{
		file.open(filePath);
	}

	bool IsOpen()
	{
		return file.is_open();
	}

	void Close()
	{
		file.close();
	}

	~NaFileReader()
	{
		Close();
	}

	template <typename T>
	NaFileReader& operator>>(T& data)
	{
		file >> data;
		return *this;
	}
};

class NaFileWriter : public NaFileBase
{
private:
	std::ofstream file = std::ofstream();
public:
	NaFileWriter() : NaFileBase(fs::path()) {}
	NaFileWriter(fs::path filePath) : NaFileBase(filePath)
	{
		file.open(filePath);
	}

	bool IsOpen()
	{
		return file.is_open();
	}

	void Close()
	{
		file.close();
	}

	~NaFileWriter()
	{
		Close();
	}

	template <typename T>
	NaFileWriter& operator<<(T data)
	{
		file << data;
		return *this;
	}
};