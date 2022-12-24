#pragma once
#include <string.h>
#include "Triangle.h"
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif
namespace Figure
{
	class Equilateral_Triangle :public Triangle {
	public:
		FIGURELIBRARY_API Equilateral_Triangle(double a);
	};
}