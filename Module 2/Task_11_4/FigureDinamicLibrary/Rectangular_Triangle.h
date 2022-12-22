#pragma once
#include <string.h>
#include"Triangle.h"
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif
namespace Figure
{
	class Rectangular_Triangle :public Triangle {
	public:
		FIGURELIBRARY_API Rectangular_Triangle(double a, double b, double c, double A, double B);
	};
}