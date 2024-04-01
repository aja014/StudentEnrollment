#pragma once
#include "Coorxy.h"
#include "border.h"
#include <iostream>

#define gotoxy coorxy

using namespace std;

void table() { // REGISTRATION TABLE

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
		coorxy(3, 1 + n); cout << string(38, char(196));
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
	coorxy(26, 27); cout << "HELP";

	coorxy(35, 0); cout << "- BSIT Student Enrollment Management System -";

	gotoxy(24, 4); color(8); cout << "Use Arrow keys to navigate and Enter key to choose and register your inputs"; color(7);


	gotoxy(3, 1); cout << char(218); gotoxy(40, 1); cout << char(191);
	gotoxy(3, 3); cout << char(192); gotoxy(40, 3); cout << char(217);

	gotoxy(3, 5); cout << char(218); gotoxy(116, 5); cout << char(191);
	gotoxy(3, 25); cout << char(192); gotoxy(116, 25); cout << char(217);

	n = 0;
	for (int i = 0; i < 4; i++) {
		buttonxy(20 + n, 26, 14, 1);
		n += 25;
	}
}

void pooltble() { // PAGE 2 REGISTRATION
	
	sborder();
	//box
	coorxy(37, 10); cout << string(50, char(196)); coorxy(36, 10); cout << char(218);
	for (int i = 0; i < 7; i++)
	{
		coorxy(36, 11 + i); cout << char(179);
		coorxy(87, 11 + i); cout << char(179);
	}
	coorxy(87, 10); cout << char(191);coorxy(36, 18); cout << char(192);
	coorxy(37, 18); cout << string(50, char(196)); coorxy(87, 18); cout << char(217);
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

void lstp()
{
	coorxy(87, 9); cout << char(191); coorxy(37, 9); cout << string(50, char(196)); coorxy(36, 9); cout << char(218);
	for (int i = 0; i < 8; i++)
	{
		coorxy(36, 10 + i); cout << char(179);
		coorxy(87, 10 + i); cout << char(179);
	}
	coorxy(36, 18); cout << char(192); coorxy(37, 18); cout << string(50, char(196)); coorxy(87, 18); cout << char(217);

	coorxy(46, 10); cout << "C O N G R A T U L A T I O N S !";
	coorxy(46, 15); cout << " you're successfully enrolled!";
	coorxy(58, 16); cout << " with";
	coorxy(50, 14); cout << string(22, char(196));
	
	buttonxy(53, 21, 14, 1);
	gotoxy(60, 22); cout << "OK";
	gotoxy(50, 20);
}

void horizontal_line(int gx, int gy, int l, int a)
{
	for (int i = 0; i < l; i++)
	{
		gotoxy(gx + i, gy); std::cout << char(a);
	}
}
void vertical_line(int gx, int gy, int h, int a)
{
	for (int i = 0; i < h; i++)
	{
		gotoxy(gx, gy + i); std::cout << char(a);
	}
}

#define hl horizontal_line
#define vl vertical_line

void tablec()//CURRICULUM TABLE
{

	int n;

	hl(2, 5, 117, 196);
	hl(2, 7, 117, 196);
	hl(2, 9, 117, 196);
	hl(2, 11, 117, 196);
	hl(2, 13, 117, 196);
	hl(2, 15, 117, 196);
	hl(2, 17, 117, 196);
	hl(2, 19, 117, 196);
	hl(2, 21, 117, 196);
	hl(2, 23, 117, 196);

	hl(2, 1, 89, 196);
	hl(2, 3, 89, 196);//Search bar
	vl(2, 2, 1, 179);
	vl(90, 2, 1, 179);

	vl(2, 6, 19, 179);
	vl(118, 6, 19, 179);
	vl(6, 6, 19, 179);// NO
	vl(26, 6, 19, 179);// YEAR LEVEL
	vl(41, 6, 19, 179);// SUBJECT CODE
	vl(90, 6, 19, 179);// SUBJECT DESCRIPTIO //SUBJECT UNIT
	vl(97, 6, 19, 179);//PRE REQUIST
	hl(3, 25, 115, 196);
	gotoxy(3, 6); cout << "NO"; gotoxy(10, 6); cout << "YEAR LEVEL"; gotoxy(27, 6); cout << " SUBJECT CODE";
	gotoxy(55, 6); cout << " SUBJECT DESCRIPTION"; gotoxy(92, 6); cout << "UNIT"; gotoxy(103, 6); cout << "PRE-REQ.";


	buttonxy(20, 26, 14, 1);
	coorxy(26, 27); cout << "HELP";

	color(8);
	buttonxy(45, 26, 14, 1);
	coorxy(48, 27); cout << "ADD/UPDATE";

	buttonxy(70, 26, 14, 1);
	coorxy(75, 27); cout << "DELETE";
	color(7);
	
	buttonxy(95, 26, 14, 1);
	coorxy(101, 27); cout << "BACK";

	gotoxy(5, 2); cout << "SEARCH YEAR: " << char(179); gotoxy(45, 2); cout << char(179) << "SEARCH SEMESTER:" << char(179);

	gotoxy(2, 1); cout << char(218); gotoxy(90, 1); cout << char(191);
	gotoxy(2, 3); cout << char(192); gotoxy(90, 3); cout << char(217);

	gotoxy(2, 5); cout << char(218); gotoxy(118, 5); cout << char(191);
	gotoxy(2, 25); cout << char(192); gotoxy(118, 25); cout << char(217);

	gotoxy(35, 0); cout << "- BSIT Student Enrollment Management System -";

	gotoxy(24, 4); color(8); cout << "Use Arrow keys to navigate and Enter key to choose and register your inputs"; color(7);



}

void page1()//ENROLLMENT PAGE 1
{
	lborder();

	hl(12, 3, 41, 196);
	vl(12, 4, 1, 179);
	vl(52, 4, 1, 179);
	hl(12, 5, 41, 196);// Search bar


	coorxy(13, 4); cout << "SEARCH POOLING NUMBER" << char(179) << ":";
	coorxy(38, 2); cout << "- BSIT Student Enrollment Management System -";
	//page 1
	hl(6, 9, 107, 196);
	hl(6, 11, 107, 196);
	hl(6, 13, 107, 196);
	hl(6, 15, 107, 196);
	//labels
	coorxy(7, 8); cout << " Surname " << char(179) << ":"; coorxy(40, 8); cout << char(179) << " Firstname " << char(179) << ":"; coorxy(77, 8); cout << char(179) << " Middlename " << char(179) << ":";
	coorxy(7, 10); cout << " Age " << char(179) << ":"; coorxy(30, 10); cout << char(179) << " Gender " << char(179) << ":"; coorxy(60, 10); cout << char(179) << " LRN " << char(179) << ":";
	coorxy(7, 12); cout << " Address " << char(179) << ":"; coorxy(7, 14); cout << " Year to enroll " << char(179) << ":"; coorxy(50, 14); cout << char(179) << " Semester to Enroll " << char(179) << ":";
	//layout border
	hl(6, 7, 107, 196);
	vl(6, 7, 8, 179);
	vl(112, 7, 8, 179);
	//buttons
	gotoxy(39, 18); cout << string(15, char(205));	gotoxy(39, 20); cout << string(15, char(205)); gotoxy(39, 19); cout << char(186); gotoxy(54, 19); cout << char(186);
	gotoxy(39, 18); cout << char(201);	gotoxy(39, 20); cout << char(200);	gotoxy(54, 18); cout << char(187);	gotoxy(54, 20); cout << char(188);
	gotoxy(64, 18); cout << string(15, char(205));	gotoxy(64, 20); cout << string(15, char(205)); gotoxy(64, 19); cout << char(186); gotoxy(79, 19); cout << char(186);
	gotoxy(64, 18); cout << char(201);	gotoxy(64, 20); cout << char(200);	gotoxy(79, 18); cout << char(187);	gotoxy(79, 20); cout << char(188);

	gotoxy(42, 19); cout << "ENROLL NOW"; gotoxy(70, 19); cout << "BACK";

	gotoxy(12, 3); cout << char(218); gotoxy(52, 3); cout << char(191);
	gotoxy(12, 5); cout << char(192); gotoxy(52, 5); cout << char(217);
	gotoxy(6, 7); cout << char(218); gotoxy(112, 7); cout << char(191);
	gotoxy(6, 15); cout << char(192); gotoxy(112, 15); cout << char(217);

	gotoxy(24, 6); color(8); cout << "Use Arrow keys to navigate and Enter key to register your inputs"; color(7);

}

void page2()//ENROLLMENT PAGE 2
{
	//page 2
		// rows
	hl(3, 3, 115, 196);
	hl(3, 7, 115, 196);
	hl(3, 9, 115, 196);// Labels
	hl(3, 11, 115, 196);
	hl(3, 13, 115, 196);
	hl(3, 15, 115, 196);
	hl(3, 17, 115, 196);
	hl(3, 19, 115, 196);
	hl(3, 21, 115, 196);
	hl(3, 23, 115, 196);
	// vertical lines
	vl(8, 6, 19, 179);//NO
	vl(35, 6, 19, 179);// YEAR LEVEL
	vl(50, 6, 19, 179);// SUBJECT CODE
	vl(100, 6, 19, 179);// SUBJECT DESCRIPTION 
	// layout border
	hl(3, 5, 115, 196);
	vl(3, 4, 21, 179);
	vl(117, 4, 21, 179);
	hl(3, 25, 115, 196);
	//buttons
	//gotoxy(70, 26); cout << string(15, char(205));	gotoxy(70, 28); cout << string(15, char(205)); gotoxy(70, 27); cout << char(186); gotoxy(85, 27); cout << char(186);
	//gotoxy(70, 26); cout << char(201);	gotoxy(70, 28); cout << char(200);	gotoxy(85, 26); cout << char(187);	gotoxy(85, 28); cout << char(188);

	gotoxy(95, 26); cout << string(15, char(205));	gotoxy(95, 28); cout << string(15, char(205)); gotoxy(95, 27); cout << char(186); gotoxy(110, 27); cout << char(186);
	gotoxy(95, 26); cout << char(201);	gotoxy(95, 28); cout << char(200);	gotoxy(110, 26); cout << char(187);	gotoxy(110, 28); cout << char(188);

	coorxy(35, 2); cout << "- BSIT Student Enrollment Management System -";
	gotoxy(101, 27); cout << "NEXT"; //gotoxy(98, 27); cout << "CLEAR MARK";

	coorxy(5, 6); cout << "NO"; coorxy(14, 6); cout << "PRE-REQUISITES"; coorxy(36, 6); cout << " SUBJECT CODE";
	coorxy(65, 6); cout << " SUBJECT DESCRIPTION"; coorxy(106, 6); cout << "MARKS";

	gotoxy(3, 3); cout << char(218); gotoxy(117, 3); cout << char(191);
	gotoxy(3, 25); cout << char(192); gotoxy(117, 25); cout << char(217);

}

void page3()//ENROLLMENT PAGE 3
{
	//page 3
		//rows
	hl(3, 1, 115, 196);
	hl(3, 5, 115, 196);
	hl(3, 7, 115, 196);
	hl(3, 9, 115, 196);
	hl(3, 11, 115, 196);
	hl(3, 13, 115, 196);
	hl(3, 15, 115, 196);
	hl(3, 17, 115, 196);
	hl(3, 19, 115, 196);
	hl(3, 21, 115, 196);
	hl(3, 23, 115, 196);
	// vertical lines
	vl(8, 4, 19, 179);//NO
	vl(35, 4, 19, 179);// YEAR LEVEL
	vl(50, 4, 19, 179);// SUBJECT CODE
	vl(100, 4, 22, 179);// SUBJECT DESCRIPTION 
	// layout border
	hl(3, 3, 115, 196);
	vl(3, 2, 24, 179);
	vl(117, 2, 24, 179);
	hl(3, 25, 115, 196);
	//buttons

	gotoxy(3, 26); cout << string(46, char(196));	gotoxy(3, 28); cout << string(46, char(196)); gotoxy(3, 27); cout << char(179); gotoxy(48, 27); cout << char(179);// button layout
	gotoxy(3, 26); cout << char(218); gotoxy(3, 28); cout << char(192);	gotoxy(48, 26); cout << char(191);/*lu*/ gotoxy(48, 28); cout << char(217);//ld// corners
	coorxy(4, 27); cout << " TOTAL BILL: " << char(158); gotoxy(25, 27); cout << char(179) << "PAYMENT: " << char(158);

	color(8);
	gotoxy(80, 26); cout << string(15, char(205));	gotoxy(80, 28); cout << string(15, char(205)); gotoxy(80, 27); cout << char(186); gotoxy(95, 27); cout << char(186);
	gotoxy(80, 26); cout << char(201);	gotoxy(80, 28); cout << char(200);	gotoxy(95, 26); cout << char(187);	gotoxy(95, 28); cout << char(188);
	gotoxy(84, 27); cout << "CONFIRM";
	color(7);

	gotoxy(100, 26); cout << string(15, char(205));	gotoxy(100, 28); cout << string(15, char(205)); gotoxy(100, 27); cout << char(186); gotoxy(115, 27); cout << char(186);
	gotoxy(100, 26); cout << char(201);	gotoxy(100, 28); cout << char(200);	gotoxy(115, 26); cout << char(187);	gotoxy(115, 28); cout << char(188);
	gotoxy(103, 27); cout << "MAIN MENU";

	gotoxy(29, 0); color(8); cout << "Use Arrow keys to navigate and Enter key to register your inputs"; color(7);


	coorxy(5, 4); cout << "NO"; coorxy(15, 4); cout << "YEAR LEVEL"; coorxy(36, 4); cout << " SUBJECT CODE";
	coorxy(65, 4); cout << " SUBJECT DESCRIPTION"; coorxy(103, 4); cout << "SUBJECT UNIT"; coorxy(85, 24); cout << "TOTAL UNITS";
	coorxy(35, 2); cout << "- BSIT Student Enrollment Management System -";

	coorxy(40, 29); color(8); cout << "Please enter the payment first before confirming"; color(7);

	gotoxy(3, 1); cout << char(218); gotoxy(117, 1); cout << char(191);
	gotoxy(3, 25); cout << char(192); gotoxy(117, 25); cout << char(217);
}

void openscen() { //OPENING SCENE
	int ld = 0;

	coorxy(55, 4); cout << string(7, char(220));
	Sleep(80);
	for (int i = 0; i < 3; i++) {
		Sleep(80);
		coorxy(58, 2 + i); cout << char(219);
		coorxy(57 + i, 15); cout << char(220);
	}
	Sleep(80);
	coorxy(59, 2); cout << string(3, char(220));
	Sleep(80);
	coorxy(59, 3); cout << string(3, char(223));
	Sleep(80);
	coorxy(55, 5); cout << char(221);
	Sleep(80);
	coorxy(61, 5); cout << char(222);
	Sleep(80);
	coorxy(53, 6); cout << char(222);
	Sleep(80);
	coorxy(63, 6); cout << char(221);
	Sleep(80);
	coorxy(54, 7); cout << string(9, char(223));
	Sleep(80);
	coorxy(55, 7); cout << char(219);
	Sleep(80);
	coorxy(61, 7); cout << char(219);
	Sleep(80);
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(54 + ld, 5); cout << char(220);
		ld += 8;
	}
	for (int i = 0; i < 10; i++) {
		Sleep(80);
		coorxy(55, 8 + i); cout << char(221);
		coorxy(61, 8 + i); cout << char(222);
	}
	for (int i = 0; i < 9; i++) {
		Sleep(80);
		coorxy(54 + i, 14); cout << char(254);
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(41 + ld, 8); cout << string(2, char(220));
		ld += 33;
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(43 + ld, 8); cout << char(219);
		ld += 30;
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(44 + ld, 8); cout << string(11, char(223));
		ld += 18;
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(40 + ld, 9); cout << char(219);
		coorxy(40 + ld, 10); cout << char(219);
		ld += 36;
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(41 + ld, 10); cout << string(14, char(220));
		ld += 21;
	}
	ld = 0;
	for (int i = 0; i < 7; i++) {
		Sleep(80);
		coorxy(41, 11 + i); cout << char(219);
		coorxy(75, 11 + i); cout << char(219);
	}
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		coorxy(57, 16 + i); cout << char(221);
		coorxy(59, 16 + i); cout << char(222);
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		color(3);//color
		coorxy(44 + ld, 12); cout << string(8, char(177));
		coorxy(44 + ld, 13); cout << string(8, char(177));
		coorxy(44 + ld, 15); cout << string(8, char(177));
		coorxy(44 + ld, 16); cout << string(8, char(177));
		ld += 21;
		coorxy(57, 10 + i); cout << string(3, char(177));
	}
	ld = 0;
	for (int i = 0; i < 2; i++) {
		Sleep(80);
		color(7);
		coorxy(26 + ld, 11); cout << string(15, char(220));
		coorxy(25, 12); cout << char(219);
		coorxy(91, 12); cout << char(219);
		coorxy(26 + ld, 13); cout << string(15, char(223));
		ld += 50;
	}
	ld = 0;
	for (int i = 0; i < 5; i++) {
		Sleep(80);
		coorxy(27, 13 + i); cout << char(219);
		coorxy(89, 13 + i); cout << char(219);
	}

	Sleep(80);
	coorxy(57, 9); cout << string(3, char(220));
	Sleep(80);
	coorxy(57, 12); cout << string(3, char(223));
	Sleep(80);
	coorxy(44, 18); cout << string(11, char(223));
	Sleep(80);
	coorxy(62, 18); cout << string(11, char(223));
	Sleep(80);
	coorxy(43, 18); cout << char(219);
	Sleep(80);
	coorxy(73, 18); cout << char(219);
	Sleep(80);
	coorxy(41, 18); cout << string(35, char(223));

	for (int i = 0; i < 14; i++) {
		Sleep(80);
		coorxy(27 + i, 17); cout << char(219);
		coorxy(89 - i, 17); cout << char(219);
	}
	for (int i = 0; i < 9; i++) {
		Sleep(80);
		color(3);// color 
		coorxy(30 + i, 14); cout << char(177);
		coorxy(30 + i, 15); cout << char(177);
		coorxy(86 - i, 14); cout << char(177);
		coorxy(86 - i, 15); cout << char(177);
	}
	color(7);
}

void menudes(int x, int y) { // MONITOR WITH DIPLOMA DESIGN

	int xx = x;
	int yy = y;

	for (int a = 0; a < 2; a++) { // Top right slant
		coorxy(xx, yy); cout << string(4, char(220));
		xx += 8;
		yy += 1;
	}
	xx = x;
	yy = y;
	xx += 4;
	yy += 1;
	for (int a = 0; a < 1; a++) { // top right slant
		coorxy(xx, yy); cout << string(4, char(223));
		xx += 8;
		yy += 1;
	}

	xx = x;
	yy = y;
	xx -= 9;
	yy += 1;
	for (int a = 0; a < 2; a++) {
		coorxy(xx, yy); cout << string(4, char(220));
		xx += 8;
		yy -= 1;
	}

	xx = x;
	yy = y;
	xx -= 5;
	yy += 1;
	for (int a = 0; a < 1; a++) {
		coorxy(xx, yy); cout << string(4, char(223));
		xx += 10;
		yy -= 1;
	}

	xx = x;
	yy = y;
	xx -= 9;
	yy += 1;
	coorxy(xx, yy); cout << string(4, char(220));
	coorxy(xx + 8, yy + 1); cout << string(5, char(220));

	xx = x;
	yy = y;
	xx -= 5;
	yy += 2;
	for (int a = 0; a < 2; a++) { // top left slant
		coorxy(xx, yy); cout << string(4, char(223));
		xx += 9;
	}
	xx -= 17;
	for (int a = 0; a < 2; a++) {
		coorxy(xx, yy + a); cout << char(219);
		coorxy(xx + 10, yy + a); cout << char(219);
	}
	xx = x;
	yy = y;
	xx -= 3;
	yy += 4;
	for (int a = 0; a < 2; a++) {
		coorxy(xx, yy); cout << string(2, char(223));
		xx += 7;
	}
	xx -= 12;
	//yy += 1;
	coorxy(xx, yy); cout << string(5, char(220));
	xx = x;
	yy = y;
	xx += 11;
	yy += 2;
	coorxy(xx, yy); cout << char(219);
	yy += 1;
	coorxy(xx, yy); cout << char(223);
	yy -= 1;
	xx -= 1;
	for (int a = 0; a < 2; a++) {
		coorxy(xx, yy); cout << char(220);
		xx += 2;
	}

	xx = x;
	yy = y;

	xx -= 13;
	yy -= 2;
	coorxy(xx, yy); cout << string(29, char(220));
	yy += 8;
	coorxy(xx, yy); cout << string(18, char(220));
	xx += 17;
	coorxy(xx, yy); cout << string(12, char(220));
	xx = x;
	yy = y;
	xx -= 13;
	yy -= 1;
	for (int a = 0; a < 8; a++) {
		coorxy(xx, yy + a); cout << char(219);
		coorxy(xx + 28, yy + a); cout << char(219);
	}
	xx = x;
	yy = y;
	yy += 7;
	xx -= 1;
	coorxy(xx, yy); cout << char(219);
	coorxy(xx + 5, yy); cout << char(219);
	coorxy(xx - 4, yy + 1); cout << string(14, char(223));
}
