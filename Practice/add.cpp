#include <iostream>
#include <fstream>
#include <Coorxy.h>
#include <string>

using namespace std;

void addemp() {

	// app - to update
	// in - to read

	string name, address, phone;


	coorxy(5, 9); cout << "Enter your name : "; getline(cin, name);
	coorxy(5, 10); cout << "Enter your Address : "; getline(cin, address);
	coorxy(5, 11); cout << "Enter your Phone number : "; getline(cin, phone);


	// formt it
	 
	fstream add;
	add.open("list.txt", ios::app | ios::in);
	if (add.is_open()) {
		string line;
		while (getline(add, line));
		add.clear();
		add.seekp(0, ios::end);
		add << endl << name + "\t|\t" + address + "\t|\t" + phone;
		add.close();
	}


	system("cls");
}