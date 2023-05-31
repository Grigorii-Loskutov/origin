#include "transform.h"
#include<vector>
#include<algorithm>


transform::transform(const Shape& sh)
{
	shape = sh;
}
Shape transform::shift(double x, double y, double z)
{
	std::vector<double> X_for_Shift = shape.get_X();
	std::vector<double> Y_for_Shift = shape.get_Y();
	std::vector<double> Z_for_Shift = shape.get_Z();
	for (auto& iter : X_for_Shift) {
		iter += x;
	}
	for (auto& iter : Y_for_Shift) {
		iter += y;
	}
	for (auto& iter : Z_for_Shift) {
		iter += z;
	}
	return Shape::Shape(X_for_Shift, Y_for_Shift, Z_for_Shift, shape.get_type());
}

Shape transform::scaleX(double scale)
{
	auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
	std::vector<double> Coord_for_Scale = shape.get_X();
	std::for_each(Coord_for_Scale.begin(), Coord_for_Scale.end(), scaleCoord);
	return Shape::Shape(Coord_for_Scale, shape.get_Y(), shape.get_Z(), shape.get_type());
}

Shape transform::scaleY(double scale)
{
	auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
	std::vector<double> Coord_for_Scale = shape.get_Y();
	std::for_each(Coord_for_Scale.begin(), Coord_for_Scale.end(), scaleCoord);
	return Shape::Shape(shape.get_X(), Coord_for_Scale, shape.get_Z(), shape.get_type());
}

Shape transform::scaleZ(double scale)
{
	auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
	std::vector<double> Coord_for_Scale = shape.get_Z();
	std::for_each(Coord_for_Scale.begin(), Coord_for_Scale.end(), scaleCoord);
	return Shape::Shape(shape.get_X(), shape.get_Y(), Coord_for_Scale, shape.get_type());
}

Shape transform::scale(double scale)
{
	auto scaleCoord = [scale](double& coord) { coord = coord * scale; };
	std::vector<double> X_for_Scale = shape.get_X();
	std::vector<double> Y_for_Scale = shape.get_Y();
	std::vector<double> Z_for_Scale = shape.get_Z();

	std::for_each(X_for_Scale.begin(), X_for_Scale.end(), scaleCoord);
	std::for_each(Y_for_Scale.begin(), Y_for_Scale.end(), scaleCoord);
	std::for_each(Z_for_Scale.begin(), Z_for_Scale.end(), scaleCoord);
	return Shape::Shape(X_for_Scale, Y_for_Scale, Z_for_Scale, shape.get_type());
}