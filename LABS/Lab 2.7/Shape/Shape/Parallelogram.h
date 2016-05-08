#pragma once

#include "Shape.h"

class Parallelogram : public Shape {
public:

	Parallelogram(double x0 = 100, double y0 = 150, double rotate = 0, double rotateAngle = 0,
		double shapeSpeed = 0, std::string way = "right", double edge1 = 10, double edge2 = 15, double alpha = 60, COLORREF color = WHITE_PEN)
		:Shape(x0, y0, rotate, rotateAngle, shapeSpeed, way, color), _edge1(edge1), _edge2(edge2), _alpha(alpha) {
		_diagonal1 = sqrt(pow(_edge1, 2) + pow(_edge2, 2) - 2 * _edge1 * _edge2 * cos((180 - _alpha) * PI / 180));
		_diagonal2 = sqrt(pow(_edge1, 2) + pow(_edge2, 2) - 2 * _edge1 * _edge2 * cos(_alpha * PI / 180));
		_height = _edge1 * sin(_alpha * PI / 180);
	}

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
		if (_x0 > rect.right ||
			_x0 < rect.left ||
			_y0 < rect.top ||
			_y0 > rect.bottom ) {
			_shapeSpeed = -_shapeSpeed;
			_rotateAngle = -_rotateAngle;
		}
		rotate();
	}

	void paint(HDC hdc) {
		if (isParallel()) {
			_brush = CreateSolidBrush(_color);
			draw(hdc, _point);
		}
	}

	void clear(HWND hWindow, HDC hdc, RECT rect) {
		_brush = CreateSolidBrush(RGB(0, 0, 0));
		draw(hdc, _point);
	}

	~Parallelogram() = default;

private:
	bool isParallel() {
		if (_alpha == 90 || _edge1 == _edge2)
			return false;
		return true;
	}

	void rotate() {
		_rotate += _rotateAngle;
		_alpha1 = (pow(_edge1, 2) + (pow(_diagonal2, 2) - pow(_diagonal2, 2)) / 4) / (_edge1 * _diagonal1);
		_gamma = acos((pow(_edge1, 2) + (pow(_diagonal2, 2) - pow(_diagonal1, 2)) / 4) / (_edge1 * _diagonal2));
		double beta1 = asin(_edge1 * sin(_alpha * PI / 180) / _diagonal1);
		double beta2 = 180 - _alpha1 - _gamma;
		_dots[0].x = _x0 - (_diagonal2 / 2) * cos((beta2 + _rotate) * PI / 180);
		_dots[0].y = _y0 - (_height / 2) * sin(_rotate * PI / 180);
		_dots[1].x = _x0 + (_diagonal1 / 2) * cos((beta1 + _rotate) * PI / 180);
		_dots[1].y = _y0 - (_height / 2) * sin(_rotate * PI / 180);
		_dots[2].x = _x0 + (_diagonal2 / 2) * cos((beta2 + _rotate) * PI / 180);
		_dots[2].y = _y0 + (_height / 2) * sin(_rotate * PI / 180);
		_dots[3].x = _x0 - (_diagonal1 / 2) * cos((beta1 + _rotate)* PI / 180);
		_dots[3].y = _y0 + (_height / 2) * sin(_rotate * PI / 180);
	}

	void draw(HDC hdc, POINT _point) {
		BeginPath(hdc);
		Polyline(hdc, _dots, 4);
		CloseFigure(hdc);
		EndPath(hdc);
		SelectObject(hdc, _brush);
		SetPolyFillMode(hdc, WINDING);
		FillPath(hdc);
		EndPath(hdc);
	}

private:
	double _edge1, _edge2, _gamma;
	double _alpha, _alpha1;
	POINT _dots[4];
	HBRUSH _brush;
	double _diagonal1, _diagonal2, _height;
};
