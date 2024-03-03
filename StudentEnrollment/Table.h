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
	//coorxy(0, 29); system("pause");
	//system("cls");

	


	//int n = 0;
	//int space = 0;
	//for (int i = 0; i < 3;i++) { // Name to birth date
	//	coorxy(3, 1+n); cout << string(114, char(196));
	//	n += 2;
	//	coorxy(4, 7); cout << string(112, char(196));
	//	for (int j = 0; j < 25; j++) {
	//		coorxy(3, 2 + j); cout << string(1, char(179));
	//		coorxy(116, 2 + j); cout << string(1, char(179));
	//	}
	//}
	//n = 0;
	//for (int i = 0; i < 3; i++) { // Address
	//	coorxy(16, 9 + n); cout << string(100,char(196));
	//	n += 2;
	//	coorxy(4, 15); cout << string(112, char(196));
	//	for (int j = 0; j < 7; j++) {
	//		coorxy(15, 8+j); cout << char(179);
	//	}
	//}


}