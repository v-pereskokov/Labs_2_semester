#include <windows.h>
#include "Line.h"
#include "Triangle.h"

LRESULT CALLBACK WindowProcess(HWND, UINT, WPARAM, LPARAM);
wchar_t className[] = L"Фигуры";
#define ID_TIMER 1
Triangle tr(900, 150, 20, 1, 3, "top", 190, RGB(255, 255, 0));
Line line(300, 200, 9, 1, 5, "right", 150, RGB(255, 255, 255));

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
		line.clear(hWindow, hdc, rect);
		tr.clear(hWindow, hdc, rect);
		line.move(rect);
		tr.move(rect);
		line.paint(hdc);
		tr.paint(hdc);
		ReleaseDC(hWindow, hdc);
		break;
	default:
		return DefWindowProc(hWindow, uMessage, wParameter, lParameter);
	}
	return 0;
}