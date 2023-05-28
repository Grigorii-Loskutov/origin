#include<vector>
#include"shape.h"
#include<cmath>
Shape::Shape() {
	Shape({ 0 }, { 0 }, { 0 }, shapeType::Point);
}

Shape::Shape(std::vector<double> X, std::vector<double> Y, std::vector<double> Z, shapeType type) {
	this->X = X;
	this->Y = Y;
	this->Z = Z;
	this->type = type;
	switch (type)
	{
	case shapeType::Line:
		square = 0;
		volume = 0;
		surface_square = 0;
		break;
	case shapeType::Rectangle:
		lenght = sqrt(pow(X[0] - X[1], 2) + pow(Y[0] - Y[1], 2) + pow(Z[0] - Z[1], 2));
		width = sqrt(pow(X[1] - X[2], 2) + pow(Y[1] - Y[2], 2) + pow(Z[1] - Z[2], 2));
		square = lenght * width;
		volume = 0;
		surface_square = 0;
		break;
	case shapeType::Parallelepiped:
		lenght = sqrt(pow(X[0] - X[1], 2) + pow(Y[0] - Y[1], 2) + pow(Z[0] - Z[1], 2));
		width = sqrt(pow(X[1] - X[2], 2) + pow(Y[1] - Y[2], 2) + pow(Z[1] - Z[2], 2));
		hight = sqrt(pow(X[0] - X[3], 2) + pow(Y[0] - Y[3], 2) + pow(Z[0] - Z[3], 2));
		square = 0;
		volume = lenght * width;
		surface_square = lenght * width * 2 + width * hight * 2 + lenght * hight * 2;
		break;
	case shapeType::Point:
		square = 0;
		volume = 0;
		surface_square = 0;
		break;
	default:
		break;
	}

}

shapeType Shape::get_type(){
	return this->type;
}

std::vector<double> Shape::get_X() {
	return this->X;
}

std::vector<double> Shape::get_Y() {
	return this->Y;
}

std::vector<double> Shape::get_Z() {
	return this->Z;
}



Line::Line() :Line(1) {}
Line::Line(double lenght) {
	X.push_back(0); Y.push_back(0); Z.push_back(0);		 //вершина (0,0,0)
	X.push_back(lenght); Y.push_back(0); Z.push_back(0); // вершина (length,0,0)
	lenght = lenght;
	width = 0;
	hight = 0;
	square = 0;
	volume = 0;
	surface_square = 0;
	type = shapeType::Line;
}

Rectangle::Rectangle() :Rectangle(1, 1) {}
Rectangle::Rectangle(double lenght, double width) {
	X.push_back(0); Y.push_back(0); Z.push_back(0); //вершина (0,0,0)
	X.push_back(lenght); Y.push_back(0); Z.push_back(0); //вершина (lenght,0,0)
	X.push_back(lenght); Y.push_back(width); Z.push_back(0); //вершина (lenght,width,0)
	X.push_back(0); Y.push_back(width); Z.push_back(0); //вершина (0,width,0)
	lenght = lenght;
	width = width;
	hight = 0;
	square = lenght * width;
	volume = 0;
	surface_square = 0;
	type = shapeType::Rectangle;
}

Parallelepiped::Parallelepiped():Parallelepiped(1,1,1){}
Parallelepiped::Parallelepiped(double lenght, double width, double hight) {

	X.push_back(0); Y.push_back(0); Z.push_back(0); //вершина (0,0,0)
	X.push_back(lenght); Y.push_back(0); Z.push_back(0); //вершина (lenght,0,0)
	X.push_back(lenght); Y.push_back(width); Z.push_back(0); //вершина (lenght,width,0)
	X.push_back(0); Y.push_back(width); Z.push_back(0); //вершина (0,width,0)

	X.push_back(0); Y.push_back(0); Z.push_back(hight); //вершина (0,0,hight)
	X.push_back(lenght); Y.push_back(0); Z.push_back(hight); //вершина (lenght,0,hight)
	X.push_back(lenght); Y.push_back(width); Z.push_back(hight); //вершина (lenght,width,hight)
	X.push_back(0); Y.push_back(width); Z.push_back(hight); //вершина (0,width,hight)
	lenght = lenght;
	width = width;
	hight = hight;
	square = 0;
	volume = lenght * width * hight;
	surface_square = lenght * width * 2 + width * hight * 2 + lenght * hight * 2;
	type = shapeType::Parallelepiped;
}
