#pragma once
#include <string>

#ifdef LEAVERLIBRARYDYNAMIC_EXPORTS
#define LEAVERLIBRARY_API __declspec(dllexport)
#else
#define LEAVERLIBRARY_API __declspec(dllimport)
#endif

namespace Leaver
{
	class Leaver
	{
	public:
		LEAVERLIBRARY_API std::string leaver (std::string name);
	};
}