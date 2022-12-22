#pragma once
#include <string.h>
#include "Quadrangle.h"
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif

namespace Figure
{
	class Rhombus :public Quadrangle {
	public:
		FIGURELIBRARY_API Rhombus(double a, double A, double B);
	};
}