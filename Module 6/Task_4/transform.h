#pragma once
#include"shape.h"
class transform
{
public:
	transform(const Shape& sh);
	//~transform() {}
	Shape shift(double x, double y, double z);
	Shape scaleX(double a);
	Shape scaleY(double d);
	Shape scaleZ(double e);
	Shape scale(double s);
	//� �� ������� rotate �� ������ ���
private:
	Shape shape;
};

