#pragma once
#include <string.h>
#include "Rectangle_.h"
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif

namespace Figure
{
	class Parallelogram :public Quadrangle {
	public:
		FIGURELIBRARY_API Parallelogram(double a, double b, double A, double B);
	};
}