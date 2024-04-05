#include <iostream>
#include <fstream>
#include <Coorxy.h>
#include <string>
#include <vector>

using namespace std;

void addemp() {

	// out - write
	// app - to update
	// in - to read

	string name, address, phone;
	vector <string> fname;


	coorxy(5, 9); cout << "Enter your first name : "; getline(cin, name); fname.push_back(name);
	coorxy(5, 10); cout << "Enter your middle name : "; getline(cin, name); fname.push_back(name);
	coorxy(5, 11); cout << "Enter your last name : "; getline(cin, name); fname.push_back(name);
	coorxy(5, 12); cout << "Enter your Address : "; getline(cin, address);
	coorxy(5, 13); cout << "Enter your Phone number : "; getline(cin, phone);


	// formt it - still here
	 
	fstream list;
	list.open("list.txt", ios::app);
	if (list.is_open()) {
		string line;
		list << fname[0] + "\t" + fname[1] + "\t" + fname[2] + "\t|\t" + address + "\t\t|\t\t" + phone << endl;
		list.close();
	}


	system("cls");
}