#pragma once
#include <Windows.h>
#include<optional>
using namespace std;
class Window {
public:
	Window(int width, int height, const char* name);
	~Window();
	static optional<int> ProcessMessages();

private:
	static LRESULT __stdcall WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	int width;
	int height;
	HWND hWnd;
	const char* windowName = "Basic DirectX Tutorial";
	HINSTANCE hInstance;
};