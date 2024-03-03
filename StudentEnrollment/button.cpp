#include <iostream>
#include "Coorxy.h"
#include "button.h"
#include "Table.h"
#include "getchValue.h"
#include <conio.h>
#include <string> // for conversion	
#include <cstring> // for copying value
//#include "Delay.h"
#define gc getchcout
//#include "enrollment.cpp"

using namespace std;

int menu(int x) {
	system("cls");

	char a;

	if (x == 1) {
		table();
		char  fname[32] = "", mname[32] = "", lname[32] = "", age[32] = "", gender[32] = "", lrn[32] = ""
			, bmonth[32] = "", bday[32] = "", byear[32] = "", barangay[32] = "", municipality[32] = ""
			, province[32] = "", postalzip[32] = "", gfname[32] = "", gmname[32] = "", glname[32] = ""
			, gcnum[32] = "", grelation[32] = "";
		int poolingnum[32];

		int counter = 1,n;
	
		Q:
		switch (counter) {
		case 1:
			coorxy(19, 7);  n = getchVal(fname,0);
			coorxy(19, 7); cout << string(20, ' ');
			coorxy(19, 7); getchcout(fname);
			if (n == 101) counter = 18;
			else counter++;
			goto Q;
			break;
		case 2:
			coorxy(57, 7);  n = getchVal(mname,0);
			coorxy(57, 7); cout << string(20, ' ');
			coorxy(57, 7); getchcout(mname);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 3:
			coorxy(93, 7); n = getchVal(lname,0);
			coorxy(93, 7); cout << string(20, ' ');
			coorxy(93, 7); getchcout(lname);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 4:
			coorxy(12, 9); n = getchVal(age,2);
			coorxy(12, 9); cout << string(20, ' ');
			coorxy(12, 9); getchcout(age);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 5:
			coorxy(15, 11); n = getchVal(gender,0);
			coorxy(15, 11); cout << string(20, ' ');
			coorxy(15, 11); getchcout(gender);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 6:
			coorxy(56, 11); n = getchVal(lrn, 12);
			coorxy(56, 11); cout << string(20, ' ');
			coorxy(56, 11); getchcout(lrn);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 7:
			coorxy(26, 13); n = getchVal(bmonth, 0);
			coorxy(26, 13); cout << string(20, ' ');
			coorxy(26, 13); getchcout(bmonth);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 8:
			coorxy(56, 13); n = getchVal(bday, 2);
			coorxy(56, 13); cout << string(20, ' ');
			coorxy(56, 13); getchcout(bday);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 9:
			coorxy(93, 13); n = getchVal(byear, 4);
			coorxy(93, 13); cout << string(20, ' ');
			coorxy(93, 13); getchcout(byear);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 10:
			coorxy(29, 15); n = getchVal(barangay, 0);
			coorxy(29, 15); cout << string(20, ' ');
			coorxy(29, 15); getchcout(barangay);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 11:
			coorxy(33, 17); n = getchVal(municipality, 0);
			coorxy(33, 17); cout << string(20, ' ');
			coorxy(33, 17); getchcout(municipality);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 12:
			coorxy(29, 19); n = getchVal(province, 0);
			coorxy(29, 19); cout << string(20, ' ');
			coorxy(29, 19); getchcout(province);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 13:
			coorxy(38, 21); n = getchVal(postalzip, 4);
			coorxy(38, 21); cout << string(20, ' ');
			coorxy(38, 21); getchcout(postalzip);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 14:
			coorxy(31, 23); n = getchVal(gfname,0);
			coorxy(31, 23); cout << string(17, ' ');
			coorxy(31, 23); getchcout(gfname);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 15:
			coorxy(65, 23); n = getchVal(gmname, 0);
			coorxy(65, 23); cout << string(15, ' ');
			coorxy(65, 23); getchcout(gmname);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 16:
			coorxy(97, 23); n = getchVal(glname, 0);
			coorxy(97, 23); cout << string(17, ' ');
			coorxy(97, 23); getchcout(glname);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 17:
			coorxy(35, 25); n = getchVal(gcnum,11);
			coorxy(35, 25); cout << string(17, ' ');
			coorxy(35, 25); getchcout(gcnum);
			if (n == 101) counter--;
			else counter++;
			goto Q;
			break;
		case 18:
			coorxy(29, 27); n = getchVal(grelation, 0);
			coorxy(29, 27); cout << string(30, ' ');
			coorxy(29, 27); getchcout(grelation);
			if (n == 101) counter--;
			else counter = 1;
			break;
		}
		system("cls");

		cout << "Name : "; getchcout(fname); cout << " "; getchcout(mname); cout << " "; getchcout(lname); cout << " \n";
		cout << "Age : ";  getchcout(age); cout << endl;
		cout << "Gender : ";  getchcout(gender); cout << endl;
		cout << "Lrn : "; getchcout(lrn); cout << endl;
		cout << "Birthdate : "; getchcout(bmonth); cout << " "; getchcout(bday); cout << " "; getchcout(byear); cout << " \n";
		cout << "barangay : "; gc(barangay); cout << endl;
		cout << "municipality : "; gc(municipality); cout << endl;
		cout << "province : "; gc(province); cout << endl;
		cout << "postal/zip : "; gc(postalzip); cout << endl;
		cout << "Guardian : "; gc(gfname); cout << " "; gc(gmname); cout << " "; gc(glname); cout << endl;
		cout << "Guardian contact number: "; gc(gcnum); cout << endl;
		cout << "Guardian relation : "; gc(grelation); cout << endl;

		coorxy(0, 29); system("pause");
		system("cls");
	}
	else if (x == 2) {
		int num = 1;

		coorxy(18, 7); cout << "Search";
		coorxy(19, 13); cout << "Back";

		for (int i = 0; i < 11;) {
			buttonxy(10, 5 + i, 20, 3);
			i += 6;
		}

		buttonxy2(10, 5, 20, 3, 2);

		for (int i = 0;;) {

			coorxy(0, 0);  a = _getch();

			coorxy(35, 7); cout << string(15, ' ') << flush;

			if (a == 72)num--;
			else if (a == 80)num++;

			if (num < 1) num = 2;
			else if (num > 2) num = 1;

			if (a == 13) {
				if (num == 2) {
					buttonxy2(10, 11, 20, 3, 1);
					Sleep(200);
					system("cls");
					break;
					return 0;
				}
				else {
					buttonxy2(10, 5, 20, 3, 1);
					Sleep(200);
					buttonxy(10, 5, 20, 3);
					coorxy(35, 7); cout << "Not yet done";
				}
			}

			for (int i = 0; i < 25; i++) { // erase selection
				coorxy(9, 4 + i); cout << string(1, ' ');
				coorxy(32, 4 + i); cout << string(1, ' ');
			}

			switch (num) {
			case 1: buttonxy2(10, 5, 20, 3, 2);
				break;
			case 2: buttonxy2(10, 11, 20, 3, 2);
				break;
			}
		}

	}
	else if (x == 3) {
		char a;
		int num = 1;
		coorxy(19, 7); cout << "Back";
		buttonxy(10, 5, 20, 3);
		buttonxy2(10, 5, 20, 3, 2);
		
		do {
			coorxy(0,0); a = _getch();
		} while (a != 13);

		buttonxy2(10, 5, 20, 3, 1);
		Sleep(200);

	}
	system("cls");
	return 0;
}

//int main() {
//
//	font1(600, 10, 20);
//
//
//	char user[] = "user1", upass[] = "upass1";
//	char admin[] = "admin1", apass[] = "apass1";
//	char username[32], password[32], a;
//
//	//int num = 0;
//	int num = 1;
//	int ld = 0;
//	int access = 0;
//
//	coorxy(55, 4); cout << string(7, char(220));
//	Sleep(100);
//	for (int i = 0; i < 3; i++) {
//		Sleep(100);
//		coorxy(58, 2 + i); cout << char(219);
//		coorxy(57 + i, 15); cout << char(220);
//	}
//	Sleep(100);
//	coorxy(59, 2); cout << string(3, char(220));
//	Sleep(100);
//	coorxy(59, 3); cout << string(3, char(223));
//	Sleep(100);
//	coorxy(55, 5); cout << char(221);
//	Sleep(100);
//	coorxy(61, 5); cout << char(222);
//	Sleep(100);
//	coorxy(53, 6); cout << char(222);
//	Sleep(100);
//	coorxy(63, 6); cout << char(221);
//	Sleep(100);
//	coorxy(54, 7); cout << string(9, char(223));
//	Sleep(100);
//	coorxy(55, 7); cout << char(219);
//	Sleep(100);
//	coorxy(61, 7); cout << char(219);
//	Sleep(100);
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(54 + ld, 5); cout << char(220);
//		ld += 8;
//	}
//	for (int i = 0; i < 10; i++) {
//		Sleep(100);
//		coorxy(55, 8 + i); cout << char(221);
//		coorxy(61, 8 + i); cout << char(222);
//	}
//	for (int i = 0; i < 9; i++) {
//		Sleep(100);
//		coorxy(54 + i, 14); cout << char(254);
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(41 + ld, 8); cout << string(2, char(220));
//		ld += 33;
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(43 + ld, 8); cout << char(219);
//		ld += 30;
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(44 + ld, 8); cout << string(11, char(223));
//		ld += 18;
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(40 + ld, 9); cout << char(219);
//		coorxy(40 + ld, 10); cout << char(219);
//		ld += 36;
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(41 + ld, 10); cout << string(14, char(220));
//		ld += 21;
//	}
//	ld = 0;
//	for (int i = 0; i < 7; i++) {
//		Sleep(100);
//		coorxy(41, 11 + i); cout << char(219);
//		coorxy(75, 11 + i); cout << char(219);
//	}
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(57, 16 + i); cout << char(221);
//		coorxy(59, 16 + i); cout << char(222);
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(44 + ld, 12); cout << string(8, char(177));
//		coorxy(44 + ld, 13); cout << string(8, char(177));
//		coorxy(44 + ld, 15); cout << string(8, char(177));
//		coorxy(44 + ld, 16); cout << string(8, char(177));
//		ld += 21;
//		coorxy(57, 10 + i); cout << string(3, char(177));
//	}
//	ld = 0;
//	for (int i = 0; i < 2; i++) {
//		Sleep(100);
//		coorxy(26+ld, 11); cout << string(15, char(220));
//		coorxy(25, 12); cout << char(219);
//		coorxy(91, 12); cout << char(219);
//		coorxy(26+ld, 13); cout << string(15, char(223));
//		ld += 50;
//	}
//	ld = 0;
//	for (int i = 0; i < 5; i++) {
//		Sleep(100);
//		coorxy(27, 13 + i); cout << char(219);
//		coorxy(89, 13 + i); cout << char(219);
//	}
//
//	Sleep(100);
//	coorxy(57, 9); cout << string(3, char(220));
//	Sleep(100);
//	coorxy(57, 12); cout << string(3, char(223));
//	Sleep(100);
//	coorxy(44, 18); cout << string(11, char(223));
//	Sleep(100);
//	coorxy(62, 18); cout << string(11, char(223));
//	Sleep(100);
//	coorxy(43, 18); cout << char(219);
//	Sleep(100);
//	coorxy(73, 18); cout << char(219);
//	Sleep(100);
//	coorxy(41, 18); cout << string(35, char(223));
//
//	for (int i = 0; i < 14; i++) {
//		Sleep(100);
//		coorxy(27+i, 17); cout << char(219);
//		coorxy(89-i, 17); cout << char(219);
//	}
//	for (int i = 0; i < 9; i++) {
//		Sleep(100);
//		coorxy(30 + i, 14); cout << char(177);
//		coorxy(30 + i, 15); cout << char(177);
//		coorxy(86 - i, 14); cout << char(177);
//		coorxy(86 - i, 15); cout << char(177);
//	}
//
//	coorxy(38, 27); cout << "BSIT Student Enrollment Management System";
//	coorxy(45, 22); system("pause"); ////////////// OPENING 
//	coorxy(45, 22); cout << string(40, ' ');
//
//	coorxy(42, 20); cout << "Username :";
//	coorxy(53, 19); cout << char(218) <<string(20, char(196)) << char(191);
//	coorxy(53, 20); cout << char(179);
//	coorxy(74, 20); cout << char(179);
//	coorxy(53, 21); cout << char(192) <<string(20, char(196)) << char(217);
//
//	coorxy(42, 23); cout << "Password :";
//	coorxy(53, 22); cout << char(218) << string(20, char(196)) << char(191);
//	coorxy(53, 23); cout << char(179);
//	coorxy(74, 23); cout << char(179);
//	coorxy(53, 24); cout << char(192) << string(20, char(196)) << char(217);
//
//	Usr: // Login security system
//	coorxy(55, 20);
//	for (int i = 0;;) { // Login security for username
//		a = _getch();
//		if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9' || a == ' ') {
//			if (i < 19) {
//				cout << a;
//				username[i] = a;
//				++i;
//				//num++;
//			}
//		}
//		else if (a == 8 && i >= 1) {
//			cout << "\b \b";
//			username[--i] = '\0';
//			//num--;
//		}
//		else if (a == 13) {
//			username[i] = '\0';
//			//if (strcmp(username, user) == 0) {
//			break;
//			/*}
//			else {
//				i = 0;
//				coorxy(55, 20); cout << string(19, ' ');
//				goto Usr;
//			}*/
//		}
//	}
//	coorxy(55, 23);
//	for (int i = 0;;) { // login security for password
//		a = _getch();
//		if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9' || a == ' ') {
//			if (i < 19) {
//				cout << "*";
//				password[i] = a;
//				++i;
//			}
//		}
//		else if (a == 8 && i >= 1) {
//			cout << "\b \b";
//			password[--i] = '\0';
//		}
//		else if (a == 13) {
//			password[i] = '\0';
//			if ((strcmp(username, user) == 0 && strcmp(password, upass) == 0)|| strcmp(username, admin) == 0 && strcmp(password, apass) == 0) { // For logging in
//				if (strcmp(username, admin) == 0 && strcmp(password, apass) == 0) {
//					access = 1; // admin access
//				}
//				break;
//
//			}
//			else {
//				i = 0;
//				//coorxy(40, 10); cout << "wrong password";
//				coorxy(55, 20); cout << string(19, ' ');
//				coorxy(55, 23); cout << string(19, ' ');
//				goto Usr;
//			}
//		}
//	}
//
//
//	//coorxy(45, 25); system("pause");
//	system("cls");
//
//	for (int i = 0; i < 24;) {
//		buttonxy(10, 3 + i, 25, 3);
//		i += 6;
//	}
//
//	buttonxy2(10, 3, 25, 3,2);
//
//	for (int i = 0;;) {
//
//		coorxy(14, 5); cout << "Student Registration";
//		coorxy(13, 11); cout << "Curriculum Management";
//		coorxy(15, 17); cout << "Student Enrollment";
//		coorxy(21, 23); cout << "Exit";
//
//		for (int i = 0; i < 24;) {
//			buttonxy(10, 3 + i, 25, 3);
//			i += 6;
//		}
//		coorxy(0, 0); char  a = _getch();
//
//
//		if (a == 72) num--;
//		else if (a == 80) num++;
//
//		else if (a == 13) { // PRESSING ENTER KEY
//
//
//			//for (int i = 0; i < 25; i++) { // erase selection animation
//			//	coorxy(9, 4 + i); cout << string(1, 'x');
//			//	coorxy(37, 4 + i); cout << string(1, 'x');
//			//}
//
//			if (num == 4) { // Exit Pressed button function
//				buttonxy2(10, 21, 25, 3, 1);
//				Sleep(250);
//				system("cls");
//
//				int exit = 0;
//				int num = 1;
//				
//
//				for (int i = 0; i < 26;) {
//					buttonxy(45+i, 11, 12, 1);
//					i += 17;
//				}
//
//				buttonxy2(45, 11, 12, 1, 2);
//				coorxy(55, 9); cout << "Are you sure?";
//				coorxy(50, 12); cout << "Yes";
//				coorxy(68, 12); cout << "No";
//
//				char a;
//				for (int i = 0;;) {
//				coorxy(0, 0); a =_getch();
//
//					if (a == 75)num--; // arrow key function
//					else if (a == 77)num++;
//
//					if (num < 1)num = 1;
//					else if (num > 2) num = 2;
//
//					if (a == 13) { // exit confirmation
//						if (num == 2) {
//							buttonxy2(62, 11, 12, 1,1);
//							Sleep(200);
//							system("cls");
//							break;
//						}
//						else {
//							exit = 1;
//							buttonxy2(45, 11, 12, 1, 1);
//							Sleep(200);
//							system("cls");
//							break;
//						}
//					}
//
//					for (int i = 0;i<5;) { //erasing selection animation
//						coorxy(43, 10+i); cout << string(40, ' ');
//						i += 4;
//						
//					}
//					switch (num) { // Exit selection animation
//					case 1:buttonxy2(45, 11, 12, 1,2);
//						break;
//					case 2:buttonxy2(62, 11, 12, 1, 2);
//						break;
//					}
//
//				}
//				if (exit == 1) { // exit
//					break;
//				}
//			}
//			else {
//
//			switch (num) { // Pressed button animation
//			case 1: buttonxy2(10, 3, 25, 3, 1);
//					Sleep(200);
//					break;
//			case 2: buttonxy2(10, 9, 25, 3, 1);
//					Sleep(200);
//					break;
//			case 3: buttonxy2(10, 15, 25, 3, 1);
//					Sleep(200);
//					break;
//			default:
//					break;
//				}
//			system("cls");
//			menu(num); // Options when entered part 2
//			//switch (num) { // Options when entered part 1 *error*
//			//case 1: enrollment();
//			//	break;
//			//} 
//			}
//		}
//		
//
//		if (num < 1) num = 4;
//		else if (num > 4) num = 1;
//
//		for (int i = 0; i < 25; i++) { // erase selection
//			coorxy(9, 2 + i); cout << string(1, ' ');
//			coorxy(37, 2 + i); cout << string(1, ' ');
//		}
//
//
//		switch (num) { // Selection bar
//		case 1: buttonxy2(10, 3, 25, 3,2);
//			break;
//		case 2:buttonxy2(10, 9, 25, 3,2);
//			break;
//		case 3:buttonxy2(10, 15, 25, 3,2);
//			break;
//		case 4:buttonxy2(10, 21, 25, 3,02);
//			break;
//		}
//	}
//
//
//
//
//	//coorxy(0, 29); system("pause");
//}

//int main() {
//	
//	char user[] = "user1", upass[] = "upass1";
//	char username[32],password[32],a;
//	int num = 0;
//
//	coorxy(42, 20); cout << "Username :";
//	coorxy(53, 19); cout << char(218) <<string(20, char(196)) << char(191);
//	coorxy(53, 20); cout << char(179);
//	coorxy(74, 20); cout << char(179);
//	coorxy(53, 21); cout << char(192) <<string(20, char(196)) << char(217);
//
//	coorxy(42, 23); cout << "Password :";
//	coorxy(53, 22); cout << char(218) << string(20, char(196)) << char(191);
//	coorxy(53, 23); cout << char(179);
//	coorxy(74, 23); cout << char(179);
//	coorxy(53, 24); cout << char(192) << string(20, char(196)) << char(217);
//
//	Usr:
//	coorxy(55, 20);
//	for (int i = 0;;) { // Login security for username
//		 a = _getch();
//		if (a >= 'a' && a <= 'z' || a>='A' && a<='Z'|| a>='0' && a<='9' || a == ' ') {
//			if (i < 19) {
//			cout << a;
//			username[i] = a;
//			++i;
//			num++;
//			}
//		}
//		else if (a == 8 && i>=1) {
//			cout << "\b \b";
//			username[--i] = '\0';
//			num--;
//		}
//		else if (a == 13) {
//			username[i] = '\0';
//			//if (strcmp(username, user) == 0) {
//			break;
//			/*}
//			else {
//				i = 0;
//				coorxy(55, 20); cout << string(19, ' ');
//				goto Usr;
//			}*/
//		}
//	}
//	coorxy(55, 23);
//	for (int i = 0;;) { // login security for password
//		a = _getch();
//		if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9' || a == ' ') {
//			if (i < 19) {
//				cout << "*";
//				password[i] = a;
//				++i;
//			}
//		}
//		else if (a == 8 && i >= 1) {
//			cout << "\b \b";
//			password[--i] = '\0';
//		}
//		else if (a == 13) {
//			password[i] = '\0';
//			if (strcmp(username, user) == 0 && strcmp(password, upass) == 0) {
//				break;
//			}
//			else {
//				i = 0;
//				coorxy(40, 10); cout << "wrong password";
//				coorxy(55, 20); cout << string(19, ' ');
//				coorxy(55, 23); cout << string(19, ' ');
//				goto Usr;
//			}
//		}
//	}
//	coorxy(40, 10);
//	for (int i = 0; i < num; i++) {
//		cout << username[i];
//	}
//
//	coorxy(0, 29); system("pause");
//}

//int main() { // NOW YOURE AT MOVING THE GETCH EVERYTIME YOU PRESS ARROW KEYS // APPLY IT TO MAIN!!! TANG"INGAAA
//
//	/*char fname[32],mname[32],lname[32];
//	char age[32];
//	int counter = 1;
//	int n =0;*/
//
//	menu(1);
//		
//	
//	
//	/*coorxy(40, 11); cout << "first name:";
//	coorxy(40, 12); cout << "middle name:";
//	coorxy(40, 13); cout << "last name:";
//	coorxy(40, 14); cout << "age:"; */
//	//Q:
//	//switch (counter) {
//	//case 1:
//	//	coorxy(53, 11);  n = getchVal(fname);
//	//	coorxy(53, 11); cout << string(20, ' ');
//	//	coorxy(53, 11); getchcout(fname);
//	//	if (n == 101) counter = 4;
//	//	else counter++;
//	//	goto Q;
//	//	break;
//	//case 2:
//	//	coorxy(53, 12);  n = getchVal(mname);
//	//	coorxy(53, 12); cout << string(20, ' ');
//	//	coorxy(53, 12); getchcout(mname);
//	//	if (n == 101) counter--;
//	//	else counter++;
//	//	goto Q;
//	//	break;
//	//case 3:
//	//	coorxy(53, 13); n = getchVal(lname);
//	//	coorxy(53, 13); cout << string(20, ' ');
//	//	coorxy(53, 13); getchcout(lname);
//	//	if (n == 101) counter--;
//	//	else counter++;
//	//	goto Q;
//	//	break;
//	//case 4:
//	//	coorxy(53, 14); n = getchVal(age);
//	//	coorxy(53, 14); cout << string(20, ' ');
//	//	coorxy(53, 14); getchcout(age);
//	//	if (n == 101) counter--;
//	//	else counter = 1;
//	//	//goto Q;
//	//	break;
//
//	//}
//
//	/*char a;
//	for (int i = 0;;) {
//		a = _getch();
//
//		if (a == -32) {
//			a = _getch();
//			if (a == 72) choice = 4;
//			else if (a == 80) choice++;
//		}
//		else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') {
//			switch (choice) {
//			case 1:
//				fnamesize = getchVal(fname);
//				break;
//			case 2:
//				fnamesize = getchVal(fname);
//				break;
//			case 3:
//				fnamesize = getchVal(fname);
//				break;
//			case 4:
//				fnamesize = getchVal(fname);
//				choice = 1;
//				break;
//			}
//		}
//	}*/
//
//	
//	// Youre at Erasing the previous array after letter is pressed
//	
//	//Q:
//	//switch (choice) { // if up 101, if down 111
//	//case 1:
//	//	coorxy(53, 11);
//	//	do {
//	//		a = _getch();
//	//		switch (a)
//	//		{
//	//		case -32:
//	//			a = _getch();
//	//			if (a == 72) choice = 4;
//	//			else if (a == 80) choice++;
//	//			break;
//	//		/*	break;
//	//		case 72:
//	//			choice = 4;
//	//			break;
//	//		case 80:
//	//			choice++;
//	//			break;*/
//	//		default:
//	//			cout << string(20, ' ');
//	//			coorxy(53, 11); fnamesize = getchVal(fname);
//	//			choice++;
//	//			a = 80;
//	//			break;
//	//		}
//	//	} while (a != 72 && a != 80);
//	//	coorxy(80, 11); cout << string(20, ' ');
//	//	coorxy(80, 11); getchcout(fname, fnamesize);
//
//	//	goto Q;
//	//	break;
//
//	//	/*if (fnamesize == 101) choice = 4;
//	//	else choice++;*/
//	//	//coorxy(53, 11); fnamesize = getchVal(fname);
//	//	//coorxy(53, 11); cout << string(20, ' ');
//	//	//coorxy(53, 11); getchcout(fname, fnamesize);
//	//case 2:
//
//	//	coorxy(53, 12);
//	//	do {
//	//		a = _getch();
//	//		switch (a)
//	//		{
//	//		case 72:
//	//			choice--;
//	//			break;
//	//		case 80:
//	//			choice++;
//	//			break;
//	//		case 13:
//	//			cout << string(20, ' ');
//	//			coorxy(53, 12); mnamesize = getchVal(mname);
//	//			choice++;
//	//			a = 80;
//	//		}
//	//	} while (a != 72 && a != 80);
//	//	coorxy(80, 12); cout << string(20, ' ');
//	//	coorxy(80, 12); getchcout(mname, mnamesize);
//
//
//	//	goto Q;
//	//	break;
//
//	//	//coorxy(53, 12); mnamesize = getchVal(mname);
//	//	////coorxy(53, 12); cout << string(20, ' ');
//	//	////coorxy(53, 12); getchcout(mname, mnamesize);
//	//	//if (mnamesize == 101) choice--;
//	//	//else choice++;
//	//	//goto Q;
//	//	//break;
//	//case 3:
//
//	//	coorxy(53, 13);
//	//	do {
//	//		a = _getch();
//	//		switch (a)
//	//		{
//	//		case 72:
//	//			choice--;
//	//			break;
//	//		case 80:
//	//			choice++;
//	//			break;
//	//		case 13:
//	//			cout << string(20, ' ');
//	//			coorxy(53, 13); lnamesize = getchVal(lname);
//	//			choice++;
//	//			a = 80;
//	//		}
//	//	} while (a != 72 && a != 80);
//	//	coorxy(80, 13); cout << string(20, ' ');
//	//	coorxy(80, 13); getchcout(lname, lnamesize);
//
//	//	goto Q;
//	//	break;
//
//	//	//coorxy(53, 13); lnamesize = getchVal(lname);
//	//	////coorxy(53, 13); cout << string(20, ' ');
//	//	////coorxy(53, 13); getchcout(lname, lnamesize);
//	//	//if (lnamesize == 101) choice--;
//	//	//else choice++;
//
//	//	//goto Q;
//	//	//break;
//	//case 4:
//
//	//	coorxy(53, 14);
//	//	do {
//	//		a = _getch();
//	//		switch (a)
//	//		{
//	//		case 72:
//	//			choice--;
//	//			break;
//	//		case 80:
//	//			choice=1;
//	//			break;
//	//		case 13:
//	//			cout << string(20, ' ');
//	//			coorxy(53, 14); agesize = getchVal(age);
//	//			choice=1;
//	//			coorxy(80, 14); cout << string(20, ' ');
//	//			coorxy(80, 14); getchcout(age, agesize);
//	//			a = 80;
//	//		}
//	//	} while (a != 72 && a != 80);
//	//	
//	//	goto Q;
//
//	//	//break;
//	//	//coorxy(53, 14); agesize = getchVal(age);
//	//	////coorxy(53, 14); cout << string(20, ' ');
//	//	////coorxy(53, 14); getchcout(age, agesize);
//	//	//if (agesize == 101) {
//	//	//	choice--;
//	//	//	goto Q;
//	//	//}
//	//	//else break;
//	//}
//	/*coorxy(40, 20); getchcout(fname);
//	coorxy(40, 21); getchcout(mname);
//	coorxy(40, 22); getchcout(lname);
//	coorxy(40, 23); getchcout(age);
//
//	coorxy(46, 13);
//
//	coorxy(0, 29); system("pause");*/
//}

int main() { // DO THE POOLING NUMBER AND ENTER SELECTION ANIMATION

	system("cls");
	string students[10][19]; // Global variable
	string finder; // Local variable
	int i; // student counter // Global variable
	int poolnum = 20240000; // pooling num // Global variable
	string searchpool[32]; // local variable
	
		table();
		char fname[32] = "", mname[32] = "", lname[32] = "", age[32] = "", gender[32] = "", lrn[32] = "" // local variable
			, bmonth[32] = "", bday[32] = "", byear[32] = "", barangay[32] = "", municipality[32] = ""
			, province[32] = "", postalzip[32] = "", gfname[32] = "", gmname[32] = "", glname[32] = ""
			, gcnum[32] = "", grelation[32] = "";

		char d; // local variable

		int counter = 0, n; // local variable

		int exit=0; // local variable
		for (i = 0;;) {
			Q:


			switch (counter) {
			case 0:

				
				coorxy(31, 2);
				for (int j = 0;;) {
					d = _getch();
					if (d == -32) {
						d = _getch();
						if (d == 72 || d == 75) {
							counter = 20;
							break;
						}
						else if (d == 80 || d == 77) {
							counter++;
							break;
						}
					}
					else if (d == 8 && j >= 1) {
						cout << "\b \b";
						searchpool[--j] = '\0';
					}
					else if ((d >= '0' && d <= '9') && j < 8) {
						cout << d;
						searchpool[j] = d;
						++j;
					}
					else if (d == 13) {
						//counter++;
						searchpool[j] = '\0';

						for (int k = 0; k < 8; k++) { // converting string array searchpoolnum[32] to single value finder
							finder += searchpool[k];

						}
						for (int k = 0; k < 10; k++) { // pooling number finder
							if (students[k][0] == finder && students[k][0] != "") {
								i = k;
								coorxy(1, 4); cout << "         ";
								coorxy(1, 4); cout << "found";
								finder = "";
								coorxy(19, 6); cout << students[k][1]; // youre here at displaying if found and puting value on varialble - done
								coorxy(57, 6); cout << students[k][2];
								coorxy(93, 6); cout << students[k][3];
								coorxy(18, 8); cout << students[k][4];
								coorxy(18, 10); cout << students[k][5];
								coorxy(56, 10); cout << students[k][6];
								coorxy(26, 12); cout << students[k][7];
								coorxy(56, 12); cout << students[k][8];
								coorxy(93, 12); cout << students[k][9];
								coorxy(29, 14); cout << students[k][10];
								coorxy(33, 16); cout << students[k][11];
								coorxy(29, 18); cout << students[k][12];
								coorxy(31, 20); cout << students[k][13];
								coorxy(65, 20); cout << students[k][14];
								coorxy(97, 20); cout << students[k][15];
								coorxy(35, 22); cout << students[k][16];
								coorxy(29, 24); cout << students[k][17];
								
								strcpy_s(fname, sizeof(fname), students[k][1].c_str()); // this is for storing the information of saved students to char variabale
								strcpy_s(mname, sizeof(mname), students[k][2].c_str());
								strcpy_s(lname, sizeof(lname), students[k][3].c_str());
								strcpy_s(age, sizeof(age), students[k][4].c_str());
								strcpy_s(gender, sizeof(gender), students[k][5].c_str());
								strcpy_s(lrn, sizeof(lrn), students[k][6].c_str());
								strcpy_s(bmonth, sizeof(bmonth), students[k][7].c_str());
								strcpy_s(bday, sizeof(bday), students[k][8].c_str());
								strcpy_s(byear, sizeof(byear), students[k][9].c_str());
								strcpy_s(barangay, sizeof(barangay), students[k][10].c_str());
								strcpy_s(municipality, sizeof(municipality), students[k][11].c_str());
								strcpy_s(province, sizeof(province), students[k][12].c_str());
								strcpy_s(gfname, sizeof(gfname), students[k][13].c_str());
								strcpy_s(gmname, sizeof(gmname), students[k][14].c_str());
								strcpy_s(glname, sizeof(glname), students[k][15].c_str());
								strcpy_s(gcnum, sizeof(gcnum), students[k][16].c_str());
								strcpy_s(grelation, sizeof(grelation), students[k][17].c_str());
								coorxy(31, 2);

								break;
							}
							else { // removing the variables value and display - done
								coorxy(19, 6); cout << string(20, ' '); // fname
								coorxy(57, 6); cout << string(20, ' '); // mname
								coorxy(93, 6); cout << string(20, ' '); // lname
								coorxy(18, 8); cout << string(20, ' '); // age
								coorxy(18, 10); cout << string(20, ' '); // gender
								coorxy(56, 10); cout << string(20, ' '); // lrn
								coorxy(26, 12); cout << string(20, ' '); // bmonth
								coorxy(56, 12); cout << string(20, ' '); // bday
								coorxy(93, 12); cout << string(20, ' '); // byear
								coorxy(29, 14); cout << string(30, ' '); // barangay
								coorxy(33, 16); cout << string(30, ' '); // municipality
								coorxy(29, 18); cout << string(30, ' '); // province
								coorxy(31, 20); cout << string(17, ' '); // guardian first name
								coorxy(65, 20); cout << string(15, ' '); // guardian middle name
								coorxy(97, 20); cout << string(17, ' '); // guardian last name
								coorxy(35, 22); cout << string(17, ' '); // guardian contact number
								coorxy(29, 24); cout << string(30, ' '); // guardian relation

								for (int o = 0; o < 1; o++) {
									fname[o] = '\0';
									mname[o] = '\0';
									lname[o] = '\0';
									age[o] = '\0';
									gender[o] = '\0';
									lrn[o] = '\0';
									bmonth[o] = '\0';
									bday[o] = '\0';
									byear[o] = '\0';
									barangay[o] = '\0';
									municipality[o] = '\0';
									province[o] = '\0';
									gfname[o] = '\0';
									gmname[o] = '\0';
									glname[o] = '\0';
									gcnum[o] = '\0';
									grelation[o] = '\0';
								}

								coorxy(1, 4); cout << "not found";
								// You have business here if not found - done

								int cn = 0; // counter finder of student who don't have pooling num - done
								while (students[cn][0] != "") {
									cn++;
									i = cn;
								}
							}
						//break;
						}


						coorxy(31, 2); cout << string(8, ' ');
						j = 0;
						finder = "";
						counter = 0;
						goto Q;
					}
				}


				break;
			case 1:
				coorxy(19, 6); n = getchVal(fname, 0);
				coorxy(19, 6); cout << string(20, ' ');
				coorxy(19, 6); getchcout(fname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 2:
				coorxy(57, 6); n = getchVal(mname, 0);
				coorxy(57, 6); cout << string(20, ' ');
				coorxy(57, 6); getchcout(mname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 3:
				coorxy(93, 6); n = getchVal(lname, 0);
				coorxy(93, 6); cout << string(20, ' ');
				coorxy(93, 6); getchcout(lname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 4:
				coorxy(18, 8); n = getchVal(age, 2);
				coorxy(18, 8); cout << string(20, ' ');
				coorxy(18, 8); getchcout(age);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 5:
				coorxy(18, 10); n = getchVal(gender, 0);
				coorxy(18, 10); cout << string(20, ' ');
				coorxy(18, 10); getchcout(gender);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 6:
				coorxy(56, 10); n = getchVal(lrn, 12);
				coorxy(56, 10); cout << string(20, ' ');
				coorxy(56, 10); getchcout(lrn);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 7:
				coorxy(26, 12); n = getchVal(bmonth, 0);
				coorxy(26, 12); cout << string(20, ' ');
				coorxy(26, 12); getchcout(bmonth);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 8:
				coorxy(56, 12); n = getchVal(bday, 2);
				coorxy(56, 12); cout << string(20, ' ');
				coorxy(56, 12); getchcout(bday);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 9:
				coorxy(93, 12); n = getchVal(byear, 4);
				coorxy(93, 12); cout << string(20, ' ');
				coorxy(93, 12); getchcout(byear);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 10:
				coorxy(29, 14); n = getchVal(barangay, 0);
				coorxy(29, 14); cout << string(30, ' ');
				coorxy(29, 14); getchcout(barangay);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 11:
				coorxy(33, 16); n = getchVal(municipality, 0);
				coorxy(33, 16); cout << string(30, ' ');
				coorxy(33, 16); getchcout(municipality);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 12:
				coorxy(29, 18); n = getchVal(province, 0);
				coorxy(29, 18); cout << string(30, ' ');
				coorxy(29, 18); getchcout(province);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			/*case 13:
				coorxy(38, 21); n = getchVal(postalzip, 4);
				coorxy(38, 21); cout << string(20, ' ');
				coorxy(38, 21); getchcout(postalzip);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;*/
			case 13:
				coorxy(31, 20); n = getchVal(gfname, 0);
				coorxy(31, 20); cout << string(17, ' ');
				coorxy(31, 20); getchcout(gfname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 14:
				coorxy(65, 20); n = getchVal(gmname, 0);
				coorxy(65, 20); cout << string(15, ' ');
				coorxy(65, 20); getchcout(gmname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 15:
				coorxy(97, 20); n = getchVal(glname, 0);
				coorxy(97, 20); cout << string(17, ' ');
				coorxy(97, 20); getchcout(glname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 16:
				coorxy(35, 22); n = getchVal(gcnum, 11);
				coorxy(35, 22); cout << string(17, ' ');
				coorxy(35, 22); getchcout(gcnum);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 17:
				coorxy(29, 24); n = getchVal(grelation, 0);
				coorxy(29, 24); cout << string(30, ' ');
				coorxy(29, 24); getchcout(grelation);
				if (n == 101) counter--;
				else counter++;
				break;
			case 18:
				coorxy(42, 27); cout << "<<";
				coorxy(62, 27); cout << ">>";
				char a;
				a = _getch();
				if (a == -32) {
					a = _getch();
					coorxy(42, 27); cout << "  ";
					coorxy(62, 27); cout << "  ";
					if (a == 72 || a == 75) counter--;
					else if (a == 80 || a == 77) counter++;
				}
				else if (a == 13) {
					coorxy(42, 27); cout << "  ";
					coorxy(62, 27); cout << "  ";
					coorxy(43, 27); cout << "<<";
					coorxy(61, 27); cout << ">>";
					Sleep(100);
				
					students[i][1] = fname;
					students[i][2] = mname;
					students[i][3] = lname;
					students[i][4] = age;
					students[i][5] = gender;
					students[i][6] = lrn;
					students[i][7] = bmonth;
					students[i][8] = bday;
					students[i][9] = byear;
					students[i][10] = barangay;
					students[i][11] = municipality;
					students[i][12] = province;
					//students[i][13] = postalzip;
					students[i][13] = gfname;
					students[i][14] = gmname;
					students[i][15] = glname;
					students[i][16] = gcnum;
					students[i][17] = grelation;
					coorxy(43, 27); cout << "  ";
					coorxy(61, 27); cout << "  ";
					int key = 0;
					for (int m = 1; m < 18; m++) { // checking if students have pool number & complete information - done
						if (students[i][0] == "") {
							if (students[i][m] == "") {
								key = 0;
								break;
							}
							else {
								key = 1;
							}
						}
						/*else {
							key = 1;
						}*/
					}
					//key = 1;
					if (key == 1) {
						if (students[i][0] == "") { // making student number - done
							key = 0;
							poolnum++;
							string pn = to_string(poolnum);
							students[i][0] = pn; 
							// Pooling number table
							coorxy(3, 27); cout << char(179) << " Pooling num : " << students[i][0];  // number
							n = 0;
							coorxy(28, 27); cout << char(179);
							for (int j = 0; j < 2; j++) {
								coorxy(3, 26 + n); cout << string(26, char(196));
								n += 2;
							}
							i++;
						}

						for (int o = 0; o < 1; o++) { // erasing char variables
							fname[o] = '\0';
							mname[o] = '\0';
							lname[o] = '\0';
							age[o] = '\0';
							gender[o] = '\0';
							lrn[o] = '\0';
							bmonth[o] = '\0';
							bday[o] = '\0';
							byear[o] = '\0';
							barangay[o] = '\0';
							municipality[o] = '\0';
							province[o] = '\0';
							gfname[o] = '\0';
							gmname[o] = '\0';
							glname[o] = '\0';
							gcnum[o] = '\0';
							grelation[o] = '\0';
						}
						system("cls"); // do the when updating, the system will clear
						table();

					}
					
				}
			break;
			case 19:
				coorxy(67, 27); cout << "<<";
				coorxy(87, 27); cout << ">>";
				char b;
				b = _getch();
				if (b == -32) {
					b = _getch();
					coorxy(67, 27); cout << "  ";
					coorxy(87, 27); cout << "  ";
					if (b == 72 || b == 75) counter--;
					else if (b == 80 || b == 77) counter++;
				}
				else if (b == 13) {
					
					coorxy(67, 27); cout << "  ";
					coorxy(87, 27); cout << "  ";
					coorxy(68, 27); cout << "<<";
					coorxy(86, 27); cout << ">>";
					Sleep(100);
					if (students[i][0] != "") {
						poolnum--; // Youre here with the problem of spamming "delete" - done
						for (int k = 0; k < 18; k++) {
							students[i][k] = "\0";
						}
					}
					// youre here deleting the char fname values - done
					for (int o = 0; o < 1; o++) {
						fname[o] = '\0';
						mname[o] = '\0';
						lname[o] = '\0';
						age[o] = '\0';
						gender[o] = '\0';
						lrn[o] = '\0';
						bmonth[o] = '\0';
						bday[o] = '\0';
						byear[o] = '\0';
						barangay[o] = '\0';
						municipality[o] = '\0';
						province[o] = '\0';
						gfname[o] = '\0';
						gmname[o] = '\0';
						glname[o] = '\0';
						gcnum[o] = '\0';
						grelation[o] = '\0';
					}
					n = 0;
					coorxy(3, 27); cout << string(20, ' ') ;
					coorxy(28, 27); cout << ' ';
					for (int x = 0; x < 2; x++) {
						coorxy(3, 26 + n); cout << string(26, ' ');
						n += 2;
					}
					// youre here about finding empty pooling number when deleting
					int cn = 0; // counter
					while (students[cn][0] != "") {
						cn++;
						i = cn;
					}

					coorxy(68, 27); cout << "  ";
					coorxy(86, 27); cout << "  ";
					system("cls");
					table();
				}
				break;

			case 20:
				coorxy(92, 27); cout << "<<";
				coorxy(112, 27); cout << ">>";
				char c;
				c = _getch();
				if (c == -32) {
					c = _getch();
					coorxy(92, 27); cout << "  ";
					coorxy(112, 27); cout << "  ";
					if (c == 72 || c == 75) counter--;
					else if (c == 80 || c == 77) counter=0;
				}
				else if (c == 13) {
					coorxy(92, 27); cout << "  ";
					coorxy(112, 27); cout << "  ";
					coorxy(93, 27); cout << "<<";
					coorxy(111, 27); cout << ">>";
					Sleep(100);
					system("cls");
					exit = 1;
				}
				break;
			}
			if (exit == 1) break;
		}
		system("cls");


		coorxy(0, 29); system("pause");
}

