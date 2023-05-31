#pragma once
#include<string>
#include<vector>

enum class shapeType {
	Line, Rectangle, Parallelepiped, Point
};

class Shape
{
protected:
	std::vector<double> X;
	std::vector<double> Y;
	std::vector<double> Z;
	double lenght = 0;
	double width = 0;
	double hight = 0;
	double volume = 0;
	double square = 0;
	double surface_square = 0;
	shapeType type = shapeType::Point;
public:
	Shape();
	Shape(shapeType Line, double length);
	Shape(shapeType Rectangle, double lenght, double width);
	Shape(shapeType Parallelepiped, double lenght, double width, double hight);
	Shape(std::vector<double> X, std::vector<double> Y, std::vector<double> Z, shapeType type);
	std::vector<double> get_X();
	std::vector<double> get_Y();
	std::vector<double> get_Z();
	shapeType get_type();
};