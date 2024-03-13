#pragma once
#include <iostream>
#include "coorxy.h"
#include "curriTable.h"//change this header into tablec header

using namespace std;

#define vl vertical_line
#define hl horizontal_line

void page1()
{
	hl(3, 1, 115, 196);
	vl(3, 2, 1, 179);
	vl(117, 2, 1, 179);
	hl(3, 3, 115, 196);// Search bar

	coorxy(4, 2); cout << "SEARCH POOLING NUMBER" << char(179);

	//page 1

	hl(3, 7, 115, 196);
	hl(3, 9, 115, 196);
	hl(3, 11, 115, 196);
	hl(3, 13, 115, 196);
	/*hl(3, 15, 115, 196);
	hl(3, 17, 115, 196);
	hl(3, 19, 115, 196);
	hl(3, 21, 115, 196);
	hl(3, 23, 115, 196);
	hl(3, 25, 115, 196);*/

	coorxy(4, 6); cout << " Surname " << char(179); coorxy(40, 6); cout << char(179) << " Firstname " << char(179); coorxy(80, 6); cout << char(179) << " Middlename " << char(179);
	coorxy(4, 8); cout << " Age " << char(179); coorxy(20, 8); cout << char(179) << " Gender " << char(179); coorxy(60, 8); cout << char(179) << " LRN " << char(179);
	coorxy(4, 10); cout << " Address " << char(179); coorxy(4, 12); cout << " Year to enroll" << char(179); coorxy(50, 12); cout << char(179) << " Semester to Enroll " << char(179);
	//layout border
	hl(3, 5, 115, 196);
	vl(3, 6, 8, 179);
	vl(117, 6, 8, 179);
	//hl(3, 25, 115, 196);
	//buttons
	gotoxy(80, 16); cout << string(15, char(205));	gotoxy(80, 18); cout << string(15, char(205)); gotoxy(80, 17); cout << char(186); gotoxy(95, 17); cout << char(186);
	gotoxy(80, 16); cout << char(201);	gotoxy(80, 18); cout << char(200);	gotoxy(95, 16); cout << char(187);	gotoxy(95, 18); cout << char(188);
	gotoxy(100, 16); cout << string(15, char(205));	gotoxy(100, 18); cout << string(15, char(205)); gotoxy(100, 17); cout << char(186); gotoxy(115, 17); cout << char(186);
	gotoxy(100, 16); cout << char(201);	gotoxy(100, 18); cout << char(200);	gotoxy(115, 16); cout << char(187);	gotoxy(115, 18); cout << char(188);
	gotoxy(83, 17); cout << "ENROLL NOW"; gotoxy(106, 17); cout << "BACK";

}
void page2()
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
	gotoxy(70, 26); cout << string(15, char(205));	gotoxy(70, 28); cout << string(15, char(205)); gotoxy(70, 27); cout << char(186); gotoxy(85, 27); cout << char(186);
	gotoxy(70, 26); cout << char(201);	gotoxy(70, 28); cout << char(200);	gotoxy(85, 26); cout << char(187);	gotoxy(85, 28); cout << char(188);

	gotoxy(95, 26); cout << string(15, char(205));	gotoxy(95, 28); cout << string(15, char(205)); gotoxy(95, 27); cout << char(186); gotoxy(110, 27); cout << char(186);
	gotoxy(95, 26); cout << char(201);	gotoxy(95, 28); cout << char(200);	gotoxy(110, 26); cout << char(187);	gotoxy(110, 28); cout << char(188);

	gotoxy(76, 27); cout << "NEXT"; gotoxy(101, 27); cout << "BACK";

	coorxy(5, 6); cout << "NO"; coorxy(15, 6); cout << "YEAR LEVEL"; coorxy(36, 6); cout << " SUBJECT CODE";
	coorxy(65, 6); cout << " SUBJECT DESCRIPTION"; coorxy(106, 6); cout << "MARKS";
}
void page3()
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


	gotoxy(3, 26); cout << string(46, char(205));	gotoxy(3, 28); cout << string(46, char(205)); gotoxy(3, 27); cout << char(186); gotoxy(48, 27); cout << char(186);
	gotoxy(3, 26); cout << char(201);	gotoxy(3, 28); cout << char(200);	gotoxy(48, 26); cout << char(187);	gotoxy(48, 28); cout << char(188);
	coorxy(4, 27); cout << " TOTAL BILL :";
	gotoxy(80, 26); cout << string(15, char(205));	gotoxy(80, 28); cout << string(15, char(205)); gotoxy(80, 27); cout << char(186); gotoxy(95, 27); cout << char(186);
	gotoxy(80, 26); cout << char(201);	gotoxy(80, 28); cout << char(200);	gotoxy(95, 26); cout << char(187);	gotoxy(95, 28); cout << char(188);
	gotoxy(100, 26); cout << string(15, char(205));	gotoxy(100, 28); cout << string(15, char(205)); gotoxy(100, 27); cout << char(186); gotoxy(115, 27); cout << char(186);
	gotoxy(100, 26); cout << char(201);	gotoxy(100, 28); cout << char(200);	gotoxy(115, 26); cout << char(187);	gotoxy(115, 28); cout << char(188);
	gotoxy(84, 27); cout << "CONFIRM"; gotoxy(106, 27); cout << "BACK";
	coorxy(5, 4); cout << "NO"; coorxy(15, 4); cout << "YEAR LEVEL"; coorxy(36, 4); cout << " SUBJECT CODE";
	coorxy(65, 4); cout << " SUBJECT DESCRIPTION"; coorxy(103, 4); cout << "SUBJECT UNIT"; coorxy(85, 24); cout << "TOTAL UNITS";
}