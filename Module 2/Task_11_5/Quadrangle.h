#pragma once
#include <string.h>
#include "Figure.h"
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif
namespace Figure
{
	class Quadrangle :public Figure {
	public:
		FIGURELIBRARY_API Quadrangle();
		FIGURELIBRARY_API Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D);

	};
}