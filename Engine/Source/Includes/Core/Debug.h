#pragma once
#include "../Export.h"
#include <string>

namespace neo
{
	class NEOENGINE_API Debug
	{
	public:
		static void Log(const std::string _string);
	};
}
