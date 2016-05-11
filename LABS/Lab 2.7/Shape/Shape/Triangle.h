#pragma once

#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double lenght = 100, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _lenght(lenght) {}

	void getRotateOfShape(double rotate, double rotateAngle) {
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
		if (_x0 > rect.right - _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 > rect.right + _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left - _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left + _lenght * cos(_rotate * PI / 180) / 2 ||
			_x0 < rect.left - _lenght * sin(_rotate * PI / 180) / 2 ||
			_x0 < rect.left + _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 < rect.top - _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 < rect.top + _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 > rect.bottom - _lenght * sin(_rotate * PI / 180) / 2 ||
			_y0 > rect.bottom + _lenght * sin(_rotate * PI / 180) / 2) {
			_shapeSpeed = -_shapeSpeed;
			_rotateAngle = -_rotateAngle;
		}
		rotate();
	}

	void paint(HDC hdc) {
		_brush = CreateSolidBrush(_color);
		draw(hdc, _point);
		DeleteObject(_brush);
	}

	void clear(HWND hWindow, HDC hdc, RECT rect) {
		_brush = CreateSolidBrush(RGB(0, 0, 0));
		draw(hdc, _point);
		DeleteObject(_brush);
	}

	~Triangle() = default;

private:
	void rotate() {
		_rotate += _rotateAngle;
		_dots[0].x = _x0 - _lenght * cos((45 + _rotate) * PI / 180) / 2;
		_dots[0].y = _y0 - _lenght * sin((45 + _rotate) * PI / 180) / 2;
		_dots[1].x = _x0 - _lenght * cos((45 - 90 + _rotate) * PI / 180) / 2;
		_dots[1].y = _y0 - _lenght * sin((45 - 90 + _rotate) * PI / 180) / 2;
		_dots[2].x = _x0 - _lenght * cos((45 - 180 + _rotate) * PI / 180) / 2;
		_dots[2].y = _y0 - _lenght * sin((45 - 180 + _rotate) * PI / 180) / 2;
	}

	void draw(HDC hdc, POINT _point) {
		BeginPath(hdc);
		Polyline(hdc, _dots, 3);
		CloseFigure(hdc);
		EndPath(hdc);
		SelectObject(hdc, _brush);
		SetPolyFillMode(hdc, WINDING);
		FillPath(hdc);
	}

private:
	double _lenght;
	double _angle;
	POINT _dots[3];
	HBRUSH _brush;
};
