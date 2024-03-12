#pragma once
#include "Coorxy.h"
#include <iostream>

using namespace std;

void table() {

	int n = 0;
	int space = 0;
	for (int i = 0; i < 5; i++) { // Name to birth date table
		coorxy(3, 5 + n); cout << string(114, char(196));
		n += 2;
		coorxy(4, 11); cout << string(112, char(196));
		coorxy(3, 25); cout << string(114, char(196));
	}
	for (int j = 0; j < 19; j++) {
		coorxy(3, 6 + j); cout << string(1, char(179));
		coorxy(116, 6 + j); cout << string(1, char(179));
	}
	n = 0;
	for (int i = 0; i < 3; i++) { // Address table
		coorxy(16, 15 + n); cout << string(100, char(196));
		n += 2;
		coorxy(4, 19); cout << string(112, char(196)); //

		for (int j = 0; j < 11; j++) {
			coorxy(15, 14 + j); cout << char(179);
		}
	}
	n = 0;
	for (int i = 0; i < 3; i++) { // Guardian Table
		coorxy(16, 19 + n); cout << string(100, char(196));
		n += 2;
	}
	for (int i = 0; i < 6; i++) {
		coorxy(15, 17 + i); cout << char(179);
	}
	n = 0;
	for (int i = 0; i < 2; i++) { // search bar
		coorxy(3, 1+n); cout << string(38, char(196));
		n += 2;
	}


	coorxy(3, 2); cout << char(179) << " Search Pooling number " << char(179) << " :"; coorxy(40, 2); cout << char(179);
	coorxy(5, 6); cout << "First name " << char(179) << ":";
	coorxy(40, 6); cout << char(179) << " Middle name " << char(179) << ":";
	coorxy(78, 6); cout << char(179) << " Last name " << char(179) << ":";
	coorxy(8, 8); cout << "Age    " << char(179) << ":";
	coorxy(6, 10); cout << "Gender   " << char(179) << ":"; coorxy(47, 10); cout << char(179) << " LRN " << char(179) << ":";
	coorxy(4, 12); cout << "Birth date " << char(179);
	coorxy(17, 12); cout << "Month " << char(179) << ":";
	coorxy(47, 12); cout << char(179) << " Day " << char(179) << ":";
	coorxy(83, 12); cout << char(179) << " Year " << char(179) << ":";
	coorxy(6, 14); cout << "Address ";
	coorxy(17, 14); cout << "Barangay " << char(179) << ":";
	coorxy(17, 16); cout << "Municipality "; cout << char(179) << ":";
	coorxy(17, 18); cout << "Province " << char(179) << ":";
	//coorxy(17, 21); cout << "Postal / Zip code " << char(179) << ":"; // youre at guardian
	coorxy(6, 20); cout << "Guardian";
	coorxy(17, 20); cout << "First name " << char(179) << ":";
	coorxy(48, 20); cout << char(179) << " Middle name " << char(179) << ":";
	coorxy(82, 20); cout << char(179) << " Last name " << char(179) << ":";
	coorxy(17, 22); cout << "Contact number " << char(179) << ":";
	coorxy(17, 24); cout << "Relation " << char(179) << ":";
	coorxy(48, 27); cout << "ADD/UPDATE";
	coorxy(75, 27); cout << "DELETE";
	coorxy(101, 27); cout << "BACK";

	n = 0;
	for (int i = 0; i < 3; i++) {
		buttonxy(45+n, 26,14,1);
		n += 25;
	}
}

void pooltable() {
	for (int i = 0; i < 95; i++)
	{
		coorxy(15 + i, 4); cout << char(220);
		coorxy(15 + i, 24); cout << char(220);
		for (int j = 0; j < 85; j++)
		{
			coorxy(20 + j, 3); cout << char(220);
			coorxy(20 + j, 25); cout << char(220);
		}
	}
	//short horizontal lines
	for (int i = 0; i < 8; i++)
	{
		coorxy(12 + i, 7); cout << char(220);
		coorxy(105 + i, 7); cout << char(220);
		for (int j = 0; j < 9; j++)
		{
			coorxy(12 + j, 21); cout << char(220);
			coorxy(104 + j, 21); cout << char(220);
		}
	}
	//short vertical lines
	for (int i = 0; i < 4; i++)
	{
		coorxy(20, 4 + i); cout << char(219);
		coorxy(104, 4 + i); cout << char(219);
		coorxy(20, 22 + i); cout << char(219);
		coorxy(104, 22 + i); cout << char(219);
	}
	//long vertical lines
	for (int j = 0; j < 20; j++)
	{
		coorxy(15, 5 + j); cout << char(219);
		coorxy(109, 5 + j); cout << char(219);
		for (int i = 0; i < 14; i++)
		{
			coorxy(12, 8 + i); cout << char(219);
			coorxy(112, 8 + i); cout << char(219);
		}
	}
	//box
	coorxy(37, 10); cout << string(50, char(205)); coorxy(36, 10); cout << char(201);
	for (int i = 0; i < 7; i++)
	{
		coorxy(36, 11 + i); cout << char(186);
		coorxy(87, 11 + i); cout << char(186);
	}
	coorxy(87, 10); cout << char(187);
	coorxy(36, 18); cout << char(200);
	coorxy(37, 18); cout << string(50, char(205)); coorxy(87, 18); cout << char(188);
	//lines inside the box  
	coorxy(38, 12); cout << string(48, char(196));
	coorxy(38, 14); cout << string(48, char(196));
	coorxy(38, 16); cout << string(48, char(196));
	//contents
	coorxy(40, 11); cout << "What year do you want to enroll? :" << char(179);
	coorxy(40, 13); cout << "Enter what semester :" << char(179);
	coorxy(40, 15); cout << "Target Year/Semester code: " << char(179);
	coorxy(40, 17); cout << "Pooling num: " << char(179);
}