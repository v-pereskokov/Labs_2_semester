#pragma once

#include <windows.h>
#include <iostream>
#include <string>

const double PI = 3.14159265358979323846;

class Shape {
public:
	Shape(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", COLORREF color = WHITE_PEN)
		:_x0(x0), _y0(y0), _rotate(rotate), _rotateAngle(rotateAngle),
		_shapeSpeed(shapeSpeed), _way(way), _color(color) {}

	virtual void getRotateOfShape(double, double) = 0;

	virtual void move(RECT) = 0;

	virtual void paint(HDC) = 0;

	virtual void clear(HWND, HDC, RECT) = 0;

	~Shape() = default;

protected:
	virtual void rotate() = 0;

	virtual void draw(HDC hdc, POINT point) = 0;

protected:
	double _x0, _y0;
	double _rotate;
	double _rotateAngle;
	double _shapeSpeed;
	std::string _way;
	POINT _point;
	COLORREF _color;
};