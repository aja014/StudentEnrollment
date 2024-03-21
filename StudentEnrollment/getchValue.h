#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

//int getchVal(char x[], int l) { // 101 is up, 111 is down
//	//x[32];
//
//	int num =1;
//	char a;
//
//	for (int z = 0;;) {
//		a = _getch();
//
//		if (a == -32) {
//			a = _getch();
//			if (a == 72||a == 75) return  101;
//			else if (a == 80 || a == 77) return 111;
//		}
//		else if (a == 13) {
//			x[z] = '\0';
//			return 111;
//			break;
//		}
//		else if (a == 8 && z >= 1) {
//			cout << "\b \b";
//			x[--z] = '\0';
//		}
//		else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') {
//			if (num == 1) {
//				//cout << string(20, ' ');
//				for (int u = 0; u < 32; u++) {
//					x[u] = '\0';
//				}
//				num = 0;
//			}
//			if (l >= 2 && l <=11) { // age
//				if ((a >= '0' && a <= '9')) {
//					if (l ==2  && z < 2) { // age and bday
//						cout << a;
//						x[z] = a;
//						++z;
//					}
//					else if (l == 11 && z < 11) { // gnumber
//						cout << a;
//						x[z] = a;
//						++z;
//					}
//					else if (l==4 && z < 4) { // byear and zip
//						cout << a;
//						x[z] = a;
//						++z;
//					}
//					else if (l == 12 && z < 11) { // gnumber
//						cout << a;
//						x[z] = a;
//						++z;
//					}
//				}
//			}
//			else {
//			cout << a;
//			x[z] = a;
//			++z;
//			}
//		}
//	}
//
//		
//	
//}

int getchVal(string& s, char t ,int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[100] = {};

	int num = 1;
	int nm = 1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0;j<z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && z <l) {
			
			// erasing previous string value
			if (num == 1) { 
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

int getchVal2(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[100] = {};

	int num = 1;
	int nm = 1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101; // arrow up
			else if (a == 80 || a == 77) return 110; // arrow down
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			return 111; // enter
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100; // backspace
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

int getchValc(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[50] = {};

	int num = 1;
	int nm = 1; // for curriculum erasing
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ')&& z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

int getchVale(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[50] = {};

	int num = 1;
	int nm = 1; // for curriculum erasing
	char a;

	for (int z = 0;;) {
		a = _getch();

		/*if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}*/
		if (a == 13 && z >=1) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			/*return 111;*/
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (/*((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') ||*/ (a >= '0' && a <= '1') /*|| a == ' ' */ && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
	return 0;
}


int getchValarr(string s[], int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[32] = {};

	int num = 1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s[j] = x[j];
				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && z >= 1) {
			cout << "\b \b";
			x[--z] = '\0';
		}
		else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') {

			// erasing previous string value
			if (num == 1) {
				for (int j = 0; j < 32; j++) {
					s[j] = '\0';
				}
				num = 0;
			}
			if (l >= 2 && l <= 11) { // age
				if ((a >= '0' && a <= '9')) {
					if (l == 2 && z < 2) { // age and bday
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 11 && z < 11) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 4 && z < 4) { // byear and zip
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 12 && z < 11) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 12 && z < 12) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

void getchcout(char x[]) { // x = array of letters  y is size of letters
	for (int z = 0;; z++) {
		if (x[z] >= 'a' && x[z] <= 'z' || x[z] >= 'A' && x[z] <= 'Z' || x[z] >= '0' && x[z] <= '9' || x[z] == ' ') {
			cout << x[z];
		}
		else {
			break;
		}

	}
}

void delarr(char x[]) { // deleting array
	for (int z = 0; z < 32; z++) {
		x[z] = '\0';
	}
}

