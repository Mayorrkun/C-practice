#include "Window.h"
#include"WindowsMessageMap.h"
#include<sstream>

using namespace std;

Window::Window(int width, int height, const char* name):
	width(width),height(height),hInstance(GetModuleHandle(nullptr))
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.style = CS_OWNDC;
	wc.hInstance = hInstance;
	wc.lpszClassName = windowName; 

	RegisterClass(&wc);

	RECT winRect;
	winRect.left = 100;
	winRect.right = width + winRect.left;
	winRect.top = 100;
	winRect.bottom = height + winRect.top;
	AdjustWindowRect(&winRect, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

	hWnd = CreateWindow(
		windowName, name,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,NULL,NULL,
		CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, hInstance, this
	);
	//  winRect.right - winRect.left, winRect.bottom - winRect.top,

	ShowWindow(hWnd, SW_SHOWDEFAULT);
}

Window::~Window() {
	UnregisterClass(windowName, hInstance);
	DestroyWindow(hWnd);
}

optional<int> Window::ProcessMessages() {
	MSG msg = {};
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		if (msg.message == WM_QUIT)
			return msg.wParam;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return{};
}

LRESULT __stdcall Window::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	static WindowsMessageMap mm;
	OutputDebugString((mm(msg, lParam, wParam) +"\n").c_str());

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(69);
		return 0;

	case WM_KEYDOWN:
	{
		if (wParam == 'F')
				{
					SetWindowText(hWnd,"PERSONA CHANGE");
				}
				return 0;
		}
		
	case WM_KEYUP : 
	{
		SetWindowText(hWnd, "ORPHEUS TELLOS");
		return 0;
	}
		
	case WM_CHAR:{	
		static string title;
		title.push_back((char)wParam);
		SetWindowText(hWnd, title.c_str());
		return 0;
	}
	

	case WM_LBUTTONDOWN: {
		const POINTS pt = MAKEPOINTS(lParam);
				ostringstream oss;
				oss << "(" << pt.x << "," << pt.y << ")";
				SetWindowText(hWnd, oss.str().c_str());

				return 0;
	}
		
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}