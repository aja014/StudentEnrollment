#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <Coorxy.h>
#include <string>

using namespace std;

void vw() {
Q:
	fstream view;
	view.open("list.txt", ios::in);
	if (view.is_open()) {
		string line;
		int y = 9;
		while (getline(view, line)) {
			coorxy(5, y); cout << line << endl;
			y++;
		}
		view.close();
	}
	coorxy(5, 15); system("pause");
	system("cls");
}