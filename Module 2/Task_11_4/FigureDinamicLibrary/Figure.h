#pragma once
#include <string>
#ifdef FIGUREDINAMICLIBRARY_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif

namespace Figure
{
	class Figure {
	protected:
		unsigned side_count;
		std::string name;
		double a, b, c, d;
		double A, B, C, D;
	public:
		FIGURELIBRARY_API Figure(unsigned side_count, std::string name, double a, double b, double c, double d, double A, double B, double C, double D);
		FIGURELIBRARY_API Figure();
		FIGURELIBRARY_API unsigned get_side_count();
		FIGURELIBRARY_API std::string get_name();
		FIGURELIBRARY_API double get_a();
		FIGURELIBRARY_API double get_b();
		FIGURELIBRARY_API double get_c();
		FIGURELIBRARY_API double get_d();
		FIGURELIBRARY_API double get_A();
		FIGURELIBRARY_API double get_B();
		FIGURELIBRARY_API double get_C();
		FIGURELIBRARY_API double get_D();
	};
}