#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <Coorxy.h>
#include <string>
#include <sstream>

using namespace std;

void vw() {

	string find;
	coorxy(5, 9); cout << "Enter the name : "; getline(cin, find);


	fstream view;
	view.open("list.txt", ios::in);
	if (view.is_open()) {
		string line;
		int y = 15;
		int y1 = 10;
		while (getline(view, line)) {
			coorxy(5, y); cout << line << endl;

			size_t found = line.find(find);

			if (found != string::npos) {
				coorxy(5, y1); cout << line;
				y1++;
			}
			y++;
		}
		view.close();
	}

	coorxy(0, 29); system("pause");
	system("cls");
}