#pragma once
#include<unordered_map>
#include<Windows.h>
#include<sstream>
using namespace std;

class WindowsMessageMap 
{
public:
	 WindowsMessageMap();

	string operator()(DWORD msg, LPARAM lParam, WPARAM wParam) const;

private:
	unordered_map<DWORD, string>map;

};