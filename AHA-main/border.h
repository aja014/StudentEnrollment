#pragma once
#include <iostream>
#include "Coorxy.h"

using namespace std;


void lborder()
{
	color(1);
	coorxy(9, 0); cout << string(102, char(220));
	for (int i = 0; i < 21; i++)
	{
		coorxy(0, 5 + i); cout << char(219);
		coorxy(119, 5 + i); cout << char(219);
	}
	for (int h = 0; h < 9; h++)
	{
		coorxy(0 + h, 4); cout << char(220);
		coorxy(111 + h, 4); cout << char(220);
		coorxy(1 + h, 25); cout << char(220);
		coorxy(110 + h, 25); cout << char(220);
	}
	coorxy(9, 29); cout << string(102, char(220));
	//inner box
	color(2);
	coorxy(4, 1); cout << string(112, char(220));
	for (int b = 0; b < 27; b++)
	{

		coorxy(4, 2 + b); cout << char(219);
		coorxy(115, 2 + b); cout << char(219);
	}
	
	coorxy(5, 28); cout << string(110, char(220));
	//vertical
	color(1);
	for (int j = 0; j < 4; j++)
	{
		coorxy(9, 1 + j); cout << char(219);
		coorxy(110, 1 + j); cout << char(219);
		coorxy(9, 26 + j); cout << char(219);
		coorxy(110, 26 + j); cout << char(219);
	}
	color(7);
}

void sborder()
{
	color(1);
	//outer box
	//slhori
	coorxy(20, 3); cout << string(85, char(220));
	for (int i = 0; i < 14; i++)
	{//slverti
		coorxy(12, 8 + i); cout << char(219);
		coorxy(112, 8 + i); cout << char(219);
	}
	for (int h = 0; h < 8; h++)
	{//shori
		coorxy(12 + h, 7); cout << char(220);
		coorxy(105 + h, 7); cout << char(220);
		coorxy(13 + h, 21); cout << char(220);
		coorxy(104 + h, 21); cout << char(220);
	}
	//slhori
	coorxy(20, 25); cout << string(85, char(220));
	//inner box
	color(2);
	//lhori
	coorxy(15, 4); cout << string(95, char(220));
	for (int b = 0; b < 20; b++)
	{
		//lverti
		coorxy(15, 5 + b); cout << char(219);
		coorxy(109, 5 + b); cout << char(219);
	}
	//lhori
	coorxy(16, 24); cout << string(93, char(220));
	//sverti
	color(1);
	for (int j = 0; j < 4; j++)
	{
		coorxy(20, 4 + j); cout << char(219);
		coorxy(104, 4 + j); cout << char(219);
		coorxy(20, 22 + j); cout << char(219);
		coorxy(104, 22 + j); cout << char(219);
	}
	color(7);
}

