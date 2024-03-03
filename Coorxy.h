#pragma once
#include <Windows.h>

void coorxy(int x, int y) {
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void font1(int x, int y, int z) {
	static CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE buffer = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(buffer, 0, &font);
	font.FontWeight = x;
	font.dwFontSize.X = y;
	font.dwFontSize.Y = z;
	SetCurrentConsoleFontEx(buffer, 0, &font);
}
