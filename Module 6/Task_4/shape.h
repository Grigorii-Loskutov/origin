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
	double lenght;
	double width;
	double hight;
	double volume;
	double square;
	double surface_square;
	shapeType type;
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

	void Line(double lenght);
	/*Shape Rectangle(double lenght, double width);
	Shape Parallelepiped(double lenght, double width, double hight);*/
};