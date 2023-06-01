#pragma once

#include <vector>

enum class ShapeType {
    LINE,
    RECTANGLE,
    PARALLELEPIPED,
    CIRCLE,
    CYLINDER
};

class Shape {
protected:
    std::vector<double> X;
    std::vector<double> Y;
    std::vector<double> Z;
    ShapeType type;

public:
    Shape() = default;
    virtual ~Shape() = default;

    ShapeType getType() const { return type; }

    std::vector<double> get_X() const { return X; };
    std::vector<double> get_Y() const { return Y; };
    std::vector<double> get_Z() const { return Z; };

    /*virtual double getLength() const = 0;
    virtual double getWidth() const = 0;
    virtual double getHeight() const = 0;
    virtual double getArea() const = 0;
    virtual double getSurfaceArea() const = 0;
    virtual double getVolume() const = 0;

    virtual void shift(double x, double y, double z) = 0;
    virtual void scaleX(double scale) = 0;
    virtual void scaleY(double scale) = 0;
    virtual void scaleZ(double scale) = 0;
    virtual void scale(double scale) = 0;*/
};

class Line : public Shape {
private:
    double length = 0;
public:
    explicit Line(double line_length);

    double getLength() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getSurfaceArea() const;
    double getVolume() const;

    void shift(double x, double y, double z);
    void scaleX(double scale);
    void scaleY(double scale);
    void scaleZ(double scale);
    void scale(double scale);
};

class Rectangle : public Shape {
private:
    double length = 0;
    double width = 0;
public:
    explicit Rectangle(double len, double wid);

    double getLength() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getSurfaceArea() const;
    double getVolume() const;

    void shift(double x, double y, double z);
    void scaleX(double scale);
    void scaleY(double scale);
    void scaleZ(double scale);
    void scale(double scale);
};

class Parallelepiped : public Shape {
private:
    double length = 0;
    double width = 0;
    double height = 0;

public:
    explicit Parallelepiped(double len, double wid, double hgt);

    double getLength() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getSurfaceArea() const;
    double getVolume() const;

    void shift(double x, double y, double z);
    void scaleX(double scale);
    void scaleY(double scale);
    void scaleZ(double scale);
    void scale(double scale);
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double rad);

    double getLength() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getSurfaceArea() const;
    double getVolume() const;

    void shift(double x, double y, double z);
    void scale(double scale);
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    explicit Cylinder(double rad, double hgt);
    double getLength() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getSurfaceArea() const;
    double getVolume() const;

    void shift(double x, double y, double z);

    void scaleZ(double scale);
    void scale(double scale);
};