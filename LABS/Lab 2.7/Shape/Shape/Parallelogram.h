#pragma once

#include "Shape.h"

class Parallelogram : public Shape {
public:

	Parallelogram(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double edge1 = 10, double edge2 = 15, double alpha = 60, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _edge1(edge1), _edge2(edge2), _alpha(alpha) {}

	void getRotateOfShape(double rotateAngle, double rotate) {
		_rotate = rotate;
		_rotateAngle = rotateAngle;
	}

	~Parallelogram() = default;

private:
	bool check() {
		if (_alpha = 90 || _edge1 == _edge2)
			return false;
		return true;
	}

	void points() {

	}

private:
	double _edge1, _edge2;
	double _alpha;
	std::string error;
};
