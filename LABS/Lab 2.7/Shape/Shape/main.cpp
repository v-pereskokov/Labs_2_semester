#include <windows.h>
#include "Shape.h"
#include "Line.h"
#include "Triangle.h"
#include "Parallelogram.h"

LRESULT CALLBACK WindowProcess(HWND, UINT, WPARAM, LPARAM);
wchar_t className[] = L"Фигуры";
#define ID_TIMER 1
Line line1(700, 200, 45, 8, 10, "bottom", 150, RGB(255, 250, 250));
Line line2(600, 460, 90, 12, 8, "right", 150, RGB(255, 228, 196));
Line line3(200, 250, 120, 2, 6, "left", 150, RGB(178, 34, 34));
Triangle tr1(900, 400, 90, 2, 7, "right", 190, RGB(255, 218, 185));
Triangle tr2(500, 200, 30, 3, 6, "top", 190, RGB(238, 130, 238));
Triangle tr3(350, 350, 55, 5, 11, "left", 190, RGB(255, 140, 0));
Parallelogram par1(600, 300, 90, 2, 9, "right", 190, 100, 60, RGB(238, 213, 210));
Parallelogram par2(300, 150, 0, 5, 4, "top", 190, 100, 60, RGB(240, 255, 240));
Parallelogram par3(400, 530, 20, 7, 13, "left", 190, 100, 60, RGB(255, 192, 203));
Shape *shapes[] = {&par1, &par2, &par3, &line1, &line2, &line3, &tr1, &tr2, &tr3};
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
		for (std::size_t i = 0; i < 9; ++i) {
			shapes[i]->clear(hWindow, hdc, rect);
			shapes[i]->move(rect);
			shapes[i]->paint(hdc);
		}
		ReleaseDC(hWindow, hdc);
		break;
	default:
		return DefWindowProc(hWindow, uMessage, wParameter, lParameter);
	}
	return 0;
}
