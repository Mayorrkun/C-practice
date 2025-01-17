#include"Window.h"
#include<iostream>

using namespace std;

int __stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPreviousInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	Window window(900, 600, "Holy shit it Works");

	while (true) {
		if (const auto msgCode = Window::ProcessMessages())
			return *msgCode;
	}
}