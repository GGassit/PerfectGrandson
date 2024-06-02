#pragma once

namespace NaUtils
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
}

#include "NaTime.h"
#include "NaFile.h"
#include "NaPath.h"