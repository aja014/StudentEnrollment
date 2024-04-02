#pragma once
#include <Windows.h>

//console related functions

void coorxy(int x, int y) {
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

void hdc(int x) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	if (x == 1) {
		cursorInfo.bVisible = FALSE; // Set cursor visibility to false
	}
	else if (x == 0) {
		cursorInfo.bVisible = TRUE; // Set cursor visibility to true
	}
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
