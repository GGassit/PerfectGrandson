#pragma once

class NaPath
{
public:
	enum class Type { File, Directory, None };
private:
	static std::string GetSystemPath(const std::string& name)
	{
		char* buffer;
		size_t size;
		_dupenv_s(&buffer, &size, name.c_str());
		std::string path = buffer;
		free(buffer);
		return path;
	}
	fs::path path = "";
public:
	static NaPath GetCurrentPath() { return fs::current_path(); }
	static NaPath GetSystemDocumentsPath() { return fs::path(GetSystemPath("USERPROFILE")) / "Documents"; }
	static NaPath GetSystemAppDataPath() { return fs::path(GetSystemPath("APPDATA")); }
	static NaPath GetSystemLocalAppDataPath() { return fs::path(GetSystemPath("LOCALAPPDATA")); }
	static NaPath GetSystemTempPath() { return fs::temp_directory_path(); }

	Type type = Type::None;
	NaPath() = default;
	NaPath(const NaPath& other) : path(other.path), type(other.type) {}
	NaPath(const fs::path& path, Type type) : path(path), type(type) {}
	NaPath(const std::string& path, Type type) : path(path), type(type) {}
	NaPath(const fs::path& path) : path(path), type(fs::is_directory(path) ? Type::Directory : Type::File) {}
	NaPath(const std::string& path) : path(path), type(fs::is_directory(path) ? Type::Directory : Type::File) {}

	bool Exists() const { return fs::exists(path); }

	bool Create() const
	{
		if (type == Type::Directory)
			return fs::create_directories(path);
		else if (type == Type::File)
		{
			fs::path parent = path.parent_path();
			if (!fs::exists(parent))
				fs::create_directories(parent);
			std::ofstream file(path);
			return file.is_open();
		}
		return false;
	}

	bool Remove() const
	{
		if (!Exists())
			return false;
		return fs::remove(path);
	}

	bool Clear() const
	{
		if (!Remove())
			return false;
		return Create();
	}

	bool Rename(const NaPath& other)
	{
		if (!Exists())
			return false;
		fs::rename(path, other.path);
		path = other.path;
		return true;
	}

	NaFileReader OpenRead() const
	{
		if (type == Type::File)
			return NaFileReader(path);
		return NaFileReader();
	}

	NaFileWriter OpenWrite() const
	{
		if (type == Type::File)
			return NaFileWriter(path);
		return NaFileWriter();
	}

	operator fs::path() const { return path; }
	operator std::string() const { return path.string(); }
	operator const char* () const { return path.string().c_str(); }

	NaPath operator/(const NaPath& other) const { return path / other.path; }
	NaPath operator/(const fs::path& other) const { return path / other; }
	NaPath operator/(const std::string& other) const { return path / other; }
	NaPath operator/(const char* other) const { return path / other; }
};