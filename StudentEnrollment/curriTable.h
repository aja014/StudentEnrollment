#pragma once
#include <iostream>
#include "coorxy.h"

#define gotoxy coorxy

using namespace std;



void horizontal_line(int gx, int gy, int l, char a)
{
	for (int i = 0; i < l; i++)
	{
		gotoxy(gx + i, gy); std::cout << a;
	}
}
void vertical_line(int gx, int gy, int h, char a)
{
	for (int i = 0; i < h; i++)
	{
		gotoxy(gx, gy + i); std::cout << a;
	}
}

#define hl horizontal_line
#define vl vertical_line

void tablec()
{

	hl(3, 5, 114, 196);
	hl(3, 7, 114, 196);
	hl(3, 9, 114, 196);
	hl(3, 11, 114, 196);
	hl(3, 13, 114, 196);
	hl(3, 15, 114, 196);
	hl(3, 17, 114, 196);
	hl(3, 19, 114, 196);
	hl(3, 21, 114, 196);
	hl(3, 23, 114, 196);

	gotoxy(5, 0); cout << "SCHOOL CURRICULUM";
	gotoxy(113, 0); cout << "help";
	hl(3, 1, 114, 196);
	hl(3, 3, 114, 196);//Search bar
	vl(3, 2, 1, 179);
	vl(116, 2, 1, 179);

	vl(3, 6, 19, 179);
	vl(116, 6, 19, 179);
	vl(10, 6, 19, 179);// NO
	vl(35, 6, 19, 179);// YEAR LEVEL
	vl(50, 6, 19, 179);// SUBJECT CODE
	vl(90, 6, 19, 179);// SUBJECT DESCRIPTIO //SUBJECT UNIT
	vl(100, 6, 19, 179);//PRE REQUIST
	hl(3, 25, 114, 196);
	gotoxy(5, 6); cout << "NO"; gotoxy(15, 6); cout << "YEAR LEVEL"; gotoxy(36, 6); cout << " SUBJECT CODE";
	gotoxy(60, 6); cout << " SUBJECT DESCRIPTION"; gotoxy(91, 6); cout << " CREDITS"; gotoxy(104, 6); cout << "PRE-REQ.";


	gotoxy(60, 26); cout << string(15, char(205));	gotoxy(60, 28); cout << string(15, char(205)); gotoxy(60, 27); cout << string(1, char(186)); gotoxy(75, 27); cout << string(1, char(186));
	gotoxy(60, 26); cout << string(1, char(201));	gotoxy(60, 28); cout << string(1, char(200));	gotoxy(75, 26); cout << string(1, char(187));	gotoxy(75, 28); cout << string(1, char(188));

	gotoxy(80, 26); cout << string(15, char(205));	gotoxy(80, 28); cout << string(15, char(205)); gotoxy(80, 27); cout << string(1, char(186)); gotoxy(95, 27); cout << string(1, char(186));
	gotoxy(80, 26); cout << string(1, char(201));	gotoxy(80, 28); cout << string(1, char(200));	gotoxy(95, 26); cout << string(1, char(187));	gotoxy(95, 28); cout << string(1, char(188));

	gotoxy(100, 26); cout << string(15, char(205));	gotoxy(100, 28); cout << string(15, char(205)); gotoxy(100, 27); cout << string(1, char(186)); gotoxy(115, 27); cout << string(1, char(186));
	gotoxy(100, 26); cout << string(1, char(201));	gotoxy(100, 28); cout << string(1, char(200));	gotoxy(115, 26); cout << string(1, char(187));	gotoxy(115, 28); cout << string(1, char(188));

	gotoxy(62, 27); cout << "ADD SUBJECT"; gotoxy(85, 27); cout << "DELETE"; gotoxy(106, 27); cout << "BACK";

	gotoxy(5, 2); cout << "SEARCH YEAR: " << char(179); gotoxy(45, 2); cout << char(179) << "SEARCH SEMESTER:" << char(179);

}
