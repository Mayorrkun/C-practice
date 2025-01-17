#pragma once
#include <Windows.h>
#include<optional>
#include"ChiliWin.h"

using namespace std;

class Window {
private:
	//singleton manages registration/cleanup of window class
	class WindowClass {
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "Chili Direct3D Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInstance;
	};

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