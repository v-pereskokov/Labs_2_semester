#include <windows.h>
#include "Shape.h"
#include "Line.h"
#include "Triangle.h"
#include "Parallelogram.h"

LRESULT CALLBACK WindowProcess(HWND, UINT, WPARAM, LPARAM);
wchar_t className[] = L"Фигуры";
#define ID_TIMER 1
Triangle tr(900, 400, 2, 5, 7, "right", 190, RGB(146, 255, 200));
Line line(700, 200, 45, 9, 11, "bottom", 150, RGB(255, 255, 255));


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR pCommandLine, int nCommandShow)
{
	HWND hwnd; 
	MSG message;
	WNDCLASSEX windowClass;
					
	windowClass.hInstance = hInstance; 
	windowClass.lpszClassName = className; 
	windowClass.lpfnWndProc = WindowProcess;
	windowClass.style = 0; 
	windowClass.cbSize = sizeof(WNDCLASSEX); 
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszMenuName = NULL; 
	windowClass.cbClsExtra = 0; 
	windowClass.cbWndExtra = 0;
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	if (!RegisterClassEx(&windowClass)) return 0;
	hwnd = CreateWindow(
		className, 
		NULL,
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		HWND_DESKTOP,
		NULL, 
		hInstance,
		NULL); 

	ShowWindow(hwnd, nCommandShow);
	UpdateWindow(hwnd);
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

LRESULT CALLBACK WindowProcess(HWND hWindow, UINT uMessage, WPARAM wParameter, LPARAM lParameter) {
	HDC hdc;
	RECT rect;
	Shape *shapes[2];
	shapes[0] = new Line(200, 150, 2, 5, 7, "left", 190, RGB(255, 255, 0));
	shapes[1] = new Line(300, 200, 45, 9, 11, "left", 150, RGB(255, 255, 255));

	GetClientRect(hWindow, &rect);
	switch (uMessage)
	{
	case WM_CREATE:
		SetTimer(hWindow, ID_TIMER, 1, NULL);
		break;
	case WM_DESTROY: 
		KillTimer(hWindow, ID_TIMER);
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		hdc = GetDC(hWindow);
		for (std::size_t i = 0; i < 2; ++i) {
			dynamic_cast<Line*>(shapes[i])->clear(hWindow, hdc, rect);
			dynamic_cast<Line*>(shapes[i])->move(rect);
			dynamic_cast<Line*>(shapes[i])->paint(hdc);
		}
		line.clear(hWindow, hdc, rect);
		line.move(rect);
		line.paint(hdc);
		tr.clear(hWindow, hdc, rect);
		tr.move(rect);
		tr.paint(hdc);
		ReleaseDC(hWindow, hdc);
		break;
	default:
		return DefWindowProc(hWindow, uMessage, wParameter, lParameter);
	}
	for (std::size_t i = 0; i < 2; ++i) {
		delete shapes[i];
	}
	return 0;
}