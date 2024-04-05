#include <iostream>
#include <Coorxy.h>
#include <fstream>
#include <string>
#include <conio.h>

#include "add.cpp"
#include "list.cpp"

using namespace std;


int main() {


	// ios::app - Append/update
	// ios::in - Reading
	// ios::out - writing/creating

	int cntr = 1;
Q:
	coorxy(5, 5); cout << "[ ] Add Employee";
	coorxy(5, 6); cout << "[ ] See the list";
	coorxy(5, 7); cout << "[ ] Exit";

W:
	for (int a = 5; a <= 7; a++) {
		coorxy(6, a); cout << " ";
	}

	if (cntr == 1) {
		coorxy(6, 5); cout << "#";
	}else if (cntr == 2) {
		coorxy(6, 6); cout << "#";
	}else if (cntr == 3) {
		coorxy(6, 7); cout << "#";
	}
	
	switch (_getch()) {
	case 224:
		switch (_getch()) {
		case 72:
			if (cntr == 1) cntr = 3;
			else cntr--;
			break;
		case 80:
			if (cntr == 3) cntr = 1;
			else cntr++;
			break;
		}
		goto W;
		break;
	case 13:
		if (cntr == 1) {
			addemp();
		}
		else if (cntr == 2) {
			vw();
		}
		else if (cntr == 3) {
			// exit
			system("cls");
			exit(0);
		}
	default:
		goto Q;
		break;
	}




	//coorxy(0, 29); system("pause");
}