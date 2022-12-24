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
	class Isosceles_Triangle :public Triangle {
	public:
		FIGURELIBRARY_API Isosceles_Triangle(double a, double b, double A, double B);
	};
}