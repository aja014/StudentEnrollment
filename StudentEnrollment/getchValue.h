#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

int getchVal(char x[], int l) { // 101 is up, 111 is down
	//x[32];

	int num =1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72||a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			return 111;
			break;
		}
		else if (a == 8 && z >= 1) {
			cout << "\b \b";
			x[--z] = '\0';
		}
		else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') {
			if (num == 1) {
				//cout << string(20, ' ');
				for (int u = 0; u < 32; u++) {
					x[u] = '\0';
				}
				num = 0;
			}
			if (l >= 2 && l <=11) { // age
				if ((a >= '0' && a <= '9')) {
					if (l ==2  && z < 2) { // age and bday
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 11 && z < 11) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l==4 && z < 4) { // byear and zip
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 12 && z < 11) { // gnumber
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

