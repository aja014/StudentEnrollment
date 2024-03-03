#pragma once
#include <iostream>
#include "Coorxy.h"

using namespace std;



void buttonxy(int w, int x,int y, int z) { // choices buton // Buttonxy(x position, y position, width, length)


	coorxy(w, x); cout << string(1, char(201)) << string(y, char(205)) << string(1, char(187)); // Upper line
	coorxy(w, x + z+1); cout << string(1, char(200)) << string(y, char(205)) << string(1, char(188)); // lower Line

	for (int i = 0; i < z; i++) {
		coorxy(w, x + 1 + i); cout << string(1, char(186)); // left line
		coorxy(w + y +1 , x +1 + i); cout << string(1, char(186)); // right line
	}
}

void buttonxy2(int w,int x, int y, int z, int a) { // choosing button // Buttonxy(x position, y position, width, length, 1 = ENTER / 2 = selection)

	//coorxy(w-1, x-1); cout << string(1, char(218)); // Upper left corner
	//coorxy(w+y+2, x - 1); cout << string(1, char(191)); // Upper right corner
	//coorxy(w-1, x + z + 2); cout << string(1, char(192)); // Down left corner
	//coorxy(w + y + 2, x + z + 2); cout << string(1, char(217)); // Down right corner

	//coorxy(w, x); cout << string(y+2, char(220)); // Upper line
	//coorxy(w, x + z + 1); cout << string(y+2, char(223)); // down line

	//for (int i = 0; i < z; i++) {
	//	coorxy(w, x+i+1); cout << string(1, char(219)); // left line
	//	coorxy(w+y+1, x+i+1); cout << string(1, char(219)); // right line
	//}

	if (a == 1) {

		coorxy(w - 1, x - 1); cout << string(1, ' '); // Upper left corner
		coorxy(w + y + 2, x - 1); cout << string(1, ' '); // Upper right corner
		coorxy(w - 1, x + z + 2); cout << string(1, ' '); // Down left corner
		coorxy(w + y + 2, x + z + 2); cout << string(1, ' '); // Down right corner

		coorxy(w, x); cout << string(y + 2, char(220)); // Upper line
		coorxy(w, x + z + 1); cout << string(y + 2, char(223)); // down line

		for (int i = 0; i < z; i++) {
			coorxy(w, x + i + 1); cout << string(1, char(219)); // left line
			coorxy(w + y + 1, x + i + 1); cout << string(1, char(219)); // right line
		}

		//coorxy(w + 1, x + 1); cout << string(y, char(176)); // upper line shaddow

		//for (int i = 0; i < z; i++) {
		//	coorxy(w + 1, x + 1 + i); cout << string(1, char(176)); // left line shadow
		//}
	}
	else if (a == 2) { // Selection


		coorxy(w - 1, x - 1); cout << string(1, char(218)); // Upper left corner
		coorxy(w + y + 2, x - 1); cout << string(1, char(191)); // Upper right corner
		coorxy(w - 1, x + z + 2); cout << string(1, char(192)); // Down left corner
		coorxy(w + y + 2, x + z + 2); cout << string(1, char(217)); // Down right corner


		//erase
		//coorxy(w - 1, x - 1); cout << string(1, ' '); // Upper left corner
		//coorxy(w + y + 2, x - 1); cout << string(1, ' '); // Upper right corner
		//coorxy(w - 1, x + z + 2); cout << string(1, ' '); // Down left corner
		//coorxy(w + y + 2, x + z + 2); cout << string(1, ' '); // Down right corner
	}
}

void pressedbutton(int w, int x, int y, int z) {
	coorxy(w, x); cout << string(y + 2, char(220)); // Upper line
	coorxy(w+1, x+1); cout << string(y, char(176)); // upper line shaddow

	for (int i = 0; i < z; i++) {
		coorxy(w + 1, x + 1 + i); cout << string(1, char(176)); // left line shadow
		coorxy(w, x + i + 1); cout << string(1, char(219)); // left line
	}
}