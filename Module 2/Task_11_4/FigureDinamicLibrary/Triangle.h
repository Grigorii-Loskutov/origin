#pragma once
#include <string>
#include "Figure.h"
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif

namespace Figure
{
	class Triangle :public Figure {
	public:
		FIGURELIBRARY_API Triangle();
		FIGURELIBRARY_API Triangle(std::string name, double a, double b, double c, double A, double B, double C);

	};
}