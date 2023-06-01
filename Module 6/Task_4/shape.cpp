#include<vector>
#include<cmath>
#include<algorithm>
#include"shape.h"


Line::Line(double line_length) : length(line_length) {
        type = ShapeType::LINE;
        X.push_back(0); Y.push_back(0); Z.push_back(0);		 //вершина (0,0,0)
        X.push_back(length); Y.push_back(0); Z.push_back(0); //вершина(length, 0, 0)
 }

double Line::getLength() const { return length; }
double Line::getWidth() const { return 0.0; }
double Line::getHeight() const { return 0.0; }
double Line::getArea() const { return 0.0; }
double Line::getSurfaceArea() const { return 0.0; }
double Line::getVolume() const { return 0.0; }

void Line::shift(double x, double y, double z) {
    for (auto& iter : X) {
	iter += x;
}
for (auto& iter : Y) {
	iter += y;
}
for (auto& iter : Z) {
	iter += z;
}
}
void Line::scaleX(double scale)  {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(X.begin(), X.end(), scaleCoord);
}
void Line::scaleY(double scale)  {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(Y.begin(), Y.end(), scaleCoord);
}   
void Line::scaleZ(double scale)  {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(Z.begin(), Z.end(), scaleCoord);
}
void Line::scale(double scale)  {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(X.begin(), X.end(), scaleCoord);
    std::for_each(Y.begin(), Y.end(), scaleCoord);
    std::for_each(Z.begin(), Z.end(), scaleCoord);
};

Rectangle::Rectangle(double len, double wid) : length(len), width(wid) {
    type = ShapeType::RECTANGLE;
    X.push_back(0); Y.push_back(0); Z.push_back(0); //вершина (0,0,0)
    X.push_back(length); Y.push_back(0); Z.push_back(0); //вершина (lenght,0,0)
    X.push_back(length); Y.push_back(width); Z.push_back(0); //вершина (lenght,width,0)
    X.push_back(0); Y.push_back(width); Z.push_back(0); //вершина (0,width,0)
 }

double Rectangle::getLength() const { return length; }
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return 0.0; }
double Rectangle::getArea() const { return length * width; }
double Rectangle::getSurfaceArea() const { return 0.0; }
double Rectangle::getVolume() const { return 0.0; }

void Rectangle::shift(double x, double y, double z) {
    for (auto& iter : X) {
        iter += x;
    }
    for (auto& iter : Y) {
        iter += y;
    }
    for (auto& iter : Z) {
        iter += z;
    }
}
void Rectangle::scaleX(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(X.begin(), X.end(), scaleCoord);
}
void Rectangle::scaleY(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(Y.begin(), Y.end(), scaleCoord);
}
void Rectangle::scaleZ(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(Z.begin(), Z.end(), scaleCoord);
}
void Rectangle::scale(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(X.begin(), X.end(), scaleCoord);
    std::for_each(Y.begin(), Y.end(), scaleCoord);
    std::for_each(Z.begin(), Z.end(), scaleCoord);
};


Parallelepiped::Parallelepiped(double len, double wid, double hgt) : length(len), width(wid), height(hgt) {
    type = ShapeType::PARALLELEPIPED;
    X.push_back(0); Y.push_back(0); Z.push_back(0); //вершина (0,0,0)
    X.push_back(length); Y.push_back(0); Z.push_back(0); //вершина (lenght,0,0)
    X.push_back(length); Y.push_back(width); Z.push_back(0); //вершина (lenght,width,0)
    X.push_back(0); Y.push_back(width); Z.push_back(0); //вершина (0,width,0)

    X.push_back(0); Y.push_back(0); Z.push_back(height); //вершина (0,0,hight)
    X.push_back(length); Y.push_back(0); Z.push_back(height); //вершина (lenght,0,hight)
    X.push_back(length); Y.push_back(width); Z.push_back(height); //вершина (lenght,width,hight)
    X.push_back(0); Y.push_back(width); Z.push_back(height); //вершина (0,width,hight)
 }

double Parallelepiped::getLength() const { return length; }
double Parallelepiped::getWidth() const { return width; }
double Parallelepiped::getHeight() const { return height; }
double Parallelepiped::getArea() const { return 2 * (length * width + length * height + width * height); }
double Parallelepiped::getSurfaceArea() const { return 2 * (length * width + length * height + width * height); }
double Parallelepiped::getVolume() const { return length * width * height; }

void Parallelepiped::shift(double x, double y, double z) {
    for (auto& iter : X) {
        iter += x;
    }
    for (auto& iter : Y) {
        iter += y;
    }
    for (auto& iter : Z) {
        iter += z;
    }
}
void Parallelepiped::scaleX(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(X.begin(), X.end(), scaleCoord);
}
void Parallelepiped::scaleY(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(Y.begin(), Y.end(), scaleCoord);
}
void Parallelepiped::scaleZ(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(Z.begin(), Z.end(), scaleCoord);
}
void Parallelepiped::scale(double scale) {
    auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
    std::for_each(X.begin(), X.end(), scaleCoord);
    std::for_each(Y.begin(), Y.end(), scaleCoord);
    std::for_each(Z.begin(), Z.end(), scaleCoord);
};


Circle::Circle(double rad) : radius(rad) {
    type = ShapeType::CIRCLE;
    X.push_back(0); Y.push_back(0); Z.push_back(0); //центр окружности
}

double Circle::getLength() const { return 0.0; }
double Circle::getWidth() const { return 0.0; }
double Circle::getHeight() const { return 0.0; }
double Circle::getArea() const { return 3.14159 * radius * radius; }
double Circle::getSurfaceArea() const { return 0.0; }
double Circle::getVolume() const { return 0.0; }

void Circle::shift(double x, double y, double z) {}
void Circle::scale(double scale) {
    radius *= scale;
}



Cylinder::Cylinder(double rad, double hgt) : radius(rad), height(hgt) {
    type = ShapeType::CYLINDER;
    X.push_back(0); Y.push_back(0); Z.push_back(0); //центр окружности основания
}

double Cylinder::getLength() const { return 0.0; }
double Cylinder::getWidth() const  { return 0.0; }
double Cylinder::getHeight() const { return height; }
double Cylinder::getArea() const { return 3.14159 * radius * radius; }
double Cylinder::getSurfaceArea() const { return 2 * 3.14159 * radius * (radius + height); }
double Cylinder::getVolume() const { return 3.14159 * radius * radius * height; }

void Cylinder::shift(double x, double y, double z) {
    for (auto& iter : X) {
        iter += x;
    }
    for (auto& iter : Y) {
        iter += y;
    }
    for (auto& iter : Z) {
        iter += z;
    }
}
void Cylinder::scaleZ(double scale) {
    height *= scale;
}
void Cylinder::scale(double scale) {
    height *= scale;
    radius *= scale;
}

