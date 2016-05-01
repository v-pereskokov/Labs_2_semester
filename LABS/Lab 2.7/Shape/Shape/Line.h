#pragma once

#include "Shape.h"

class Line : public Shape {
public:
	Line(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double lenght = 10, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _lenght(lenght) {}

	void getRotateOfShape(double rotateAngle, double rotate) {
		_rotate = rotate;
		_rotateAngle = rotateAngle;
	}

	void move(RECT rect) {
		if (_way == "right")
			_x0 += _shapeSpeed;
		else if (_way == "left")
			_x0 -= _shapeSpeed;
		else if (_way == "top")
			_y0 -= _shapeSpeed;
		else if (_way == "bottom")
			_y0 += _shapeSpeed;
		if (_x0 > rect.right || _x0 < rect.left || _y0 < rect.top || _y0 > rect.bottom)
			_shapeSpeed = -_shapeSpeed;
		rotate();
	}

	void paint(HDC hdc) {
		pen = CreatePen(PS_SOLID, 1, _color);
		SelectObject(hdc, pen);
		draw(hdc, _point);
	}

	void clear(HWND hWindow, HDC hdc, RECT rect) {
		pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		SelectObject(hdc, pen);
		draw(hdc, _point);
	}

	~Line() = default;

private:
	void rotate() {
		_rotate += _rotateAngle;
		_angle = _rotate * PI / 180;
		_x1 = _x0 + _lenght * cos(_angle) / 2;
		_y1 = _y0 - _lenght * sin(_angle) / 2;
		_x2 = _x0 - _lenght * cos(_angle) / 2;
		_y2 = _y0 + _lenght * sin(_angle) / 2;
	}

	void draw(HDC hdc, POINT point) {
		MoveToEx(hdc, _x1, _y1, &point);
		LineTo(hdc, _x2, _y2);
	}

private:
	double _lenght;
	double _angle;
	double _x1, _y1;
	double _x2, _y2;
	HPEN pen;
};