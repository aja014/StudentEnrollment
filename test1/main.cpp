#include <iostream>
#include <fstream>
#include <sstream>
#include "Coorxy.h"
#include "button.h"
#include "Table.h" // Display table for Registration
#include "getchValue.h"
#include <conio.h>
#include <string> // for conversion	
#include <cstdio> // for deleting text file (database)
#include "help.h"
#include "border.h"

//#include "Delay.h"
#define gc getchcout
//#include "enrollment.cpp"

using namespace std;

// ifstream to read
// ofstream to write




void multival(string& v, string& w, string& x, string& y, string& z, int a, int b, int c) { // w x y z is the storage, a b is the position of gotoxy, c if erasing (1 == erase)

	hdc(0);
	if (c == 1) { // this is to erase
		v = "";
		coorxy(a + 28, b); cout << string(13, ' ');
		coorxy(a + 28, b); cout << v;
		w = "";
		coorxy(a + 43, b); cout << string(46, ' ');
		coorxy(a + 43, b); cout << w;
		x = "";
		coorxy(a + 92, b); cout << string(5, ' ');
		coorxy(a + 92, b); cout << x;
		y = "";
		coorxy(a + 99, b); cout << string(6, ' ');
		coorxy(a + 99, b); cout << y;
		z = "";
		coorxy(a + 107, b); cout << string(7, ' ');
		coorxy(a + 107, b); cout << y;
	}
	else {

		int localcounter = 1;
		int sm;

		//getting the values inside the line

	Q:
		switch (localcounter) {
		case 1:
			coorxy(a + 28, b); sm = getchValc(v, 'l', 13); // subject code
			coorxy(a + 28, b); cout << string(13, ' ');
			coorxy(a + 28, b); cout << v;
			if (sm == 111)localcounter++; // if getchvalc returned a value
			else if (sm == 100) goto Q; // if getchvalc returned empty/null
			goto Q;
			break;
		case 2:
			coorxy(a + 43, b); sm = getchValc(w, 'l', 37); // subject description
			coorxy(a + 43, b); cout << string(37, ' ');
			coorxy(a + 43, b); cout << w;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 3:
			coorxy(a + 92, b); sm = getchValc(x, 'l', 1); // subject credits
			coorxy(a + 92, b); cout << string(1, ' ');
			coorxy(a + 92, b); cout << x;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 4:
			coorxy(a + 99, b); sm = getchValc(y, 'l', 8);  // subject pre req 1
			coorxy(a + 99, b); cout << string(7, ' ');
			coorxy(a + 99, b); cout << y;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else {
				if (y != "" && y != "NONE") {
					localcounter++;
				}
				else {
					localcounter += 2;
				}
			}
			goto Q;
			break;
		case 5:
			coorxy(a + 109, b); sm = getchValc(z, 'l', 14); // subjecy pre req 2
			coorxy(a + 109, b); cout << string(7, ' ');
			coorxy(a + 109, b); cout << z;
			if (sm == 101) {
				localcounter--;
				goto Q;
			}
			else if (sm == 100) {
				goto Q;
			}
			else {
				//localcounter++;
				break;
			}
		}
	}


}

int menu(int x, int y) {

	system("cls");
	//char a;
	int acc = y;
	//variables for display
	int cx = 0; // x position
	int cy = 0; // y position


	if (x == 1) {



		string currentfile; // storage for filename

		string pooln, fname, mname, lname, age, gender, lrn, bmonth, bday, byear, barangay, municipality, province, gfname, gmname, glname, gcnum,
			grelation, year, sem,blnc;// Local varible storage for information

		string psdsub[9]; // passed subject
		string finder; // storage for searching pooling number
		string temppoolnum; // storage for conversion of int temppool to string
		string searchpool[32]; // array storage for searching
		string e; //local variable for targety

		char d; // local variable for getch in switching

		int temppool = 20240001;// variable for temporary pooling num (need for finding empty pool)
		int ext = 0; // variable for exit confirmation
		int exit = 0; // local variable
		int counter = 0; // local variable // counter 
		int n; // storage for returning value
		int i = 0; // student counter // local variable
		int racc = 0; // registration saving acces



		//finding the empty file - done

		temppool = 20240001;
		ext = 0;
		do {
			string tempfinder = to_string(temppool) + ".txt";
			ifstream newfile; // making new file and check if it exist
			newfile.open(tempfinder);
			if (newfile.is_open()) {
				temppool++;
				newfile.close();
			}
			else {
				temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
				currentfile = temppoolnum + ".txt";
				ext = 1;
				break;
			}
		} while (ext != 1);


		//H:

		table();


		if (acc != 1) { // display access table
			for (int a = 26; a <= 28; a++) {
				coorxy(20, a); cout << string(17, ' ');
			}
			for (int a = 1; a <= 3; a++) {
				coorxy(0, a); cout << string(50, ' ');
			}


			coorxy(71, 27); cout << string(15, ' ');
			coorxy(48, 27); cout << string(10, ' ');
			buttonxy(70, 26, 14, 1);
			coorxy(76, 27); cout << "ADD";
			coorxy(51, 27); cout << "HELP";
			coorxy(70, 2); cout << string(45, ' ');
		}




		for (i = 0;;) {
		Q:


			switch (counter) {
			case 0:
				if (acc == 1) {// if admin have the access
					coorxy(31, 2);
					for (int j = 0;;) {
						d = _getch();
						if (d == -32) {
							d = _getch();
							if (d == 72 || d == 75) {
								hdc(1); coorxy(42, 2); cout << "         "; hdc(0);
								counter = 21;
								break;
							}
							else if (d == 80 || d == 77) {
								hdc(1); coorxy(42, 2); cout << "         "; hdc(0);
								counter++;
								break;
							}
						}
						else if (d == 8 && j >= 1) {
							cout << "\b \b";
							searchpool[--j] = '\0';
						}
						else if ((d >= '0' && d <= '9') && j < 8) {
							hdc(1); coorxy(42, 2); cout << "         "; hdc(0);
							coorxy(31 + j, 2); cout << d;
							searchpool[j] = d;
							++j;
						}
						else if (d == 13) {
							//counter++;
							searchpool[j] = '\0';

							for (int k = 0; k < 8; k++) { // converting string array searchpoolnum[32] to single value finder
								finder += searchpool[k];

							}

							// Erasing display

							coorxy(19, 6); cout << string(15, ' ');
							coorxy(57, 6); cout << string(15, ' ');
							coorxy(93, 6); cout << string(15, ' ');
							coorxy(18, 8); cout << string(15, ' ');
							coorxy(18, 10); cout << string(15, ' ');
							coorxy(56, 10); cout << string(15, ' ');
							coorxy(26, 12); cout << string(15, ' ');
							coorxy(56, 12); cout << string(15, ' ');
							coorxy(93, 12); cout << string(15, ' ');
							coorxy(29, 14); cout << string(15, ' ');
							coorxy(33, 16); cout << string(15, ' ');
							coorxy(29, 18); cout << string(15, ' ');
							coorxy(31, 20); cout << string(15, ' ');
							coorxy(65, 20); cout << string(15, ' ');
							coorxy(97, 20); cout << string(15, ' ');
							coorxy(35, 22); cout << string(15, ' ');
							coorxy(29, 24); cout << string(15, ' ');

							// youre here at finding  - done

							string findtxt = finder + ".txt";
							ifstream loadfile(findtxt);
							if (loadfile.is_open()) { // if found, store the data
								currentfile = findtxt;
								string line;


								getline(loadfile, line);
								stringstream ss(line);
								getline(ss, pooln, '$');
								getline(ss, fname, '$');
								getline(ss, mname, '$');
								getline(ss, lname, '$');
								getline(ss, age, '$');
								getline(ss, gender, '$');
								getline(ss, lrn, '$');
								getline(ss, bmonth, '$');
								getline(ss, bday, '$');
								getline(ss, byear, '$');
								getline(ss, barangay, '$');
								getline(ss, municipality, '$');
								getline(ss, province, '$');
								getline(ss, gfname, '$');
								getline(ss, gmname, '$');
								getline(ss, glname, '$');
								getline(ss, gcnum, '$');
								getline(ss, grelation, '$');
								getline(ss, year, '$');
								getline(ss, sem, '$');
								getline(ss, blnc, '$');

								getline(loadfile, line);
								stringstream sl(line);
								for (int a = 0; a < 9; a++) {
									getline(sl, psdsub[a], '$');
								}


								/*while (getline(loadfile, line)) {
									stringstream ss(line);
									getline(ss, pooln, '$');
									getline(ss, fname, '$');
									getline(ss, mname, '$');
									getline(ss, lname, '$');
									getline(ss, age, '$');
									getline(ss, gender, '$');
									getline(ss, lrn, '$');
									getline(ss, bmonth, '$');
									getline(ss, bday, '$');
									getline(ss, byear, '$');
									getline(ss, barangay, '$');
									getline(ss, municipality, '$');
									getline(ss, province, '$');
									getline(ss, gfname, '$');
									getline(ss, gmname, '$');
									getline(ss, glname, '$');
									getline(ss, gcnum, '$');
									getline(ss, grelation, '$');
									getline(ss, year, '$');
									getline(ss, sem, '$');
									getline(ss, blnc, '$');
								}*/

								// displaying found datas - done

								coorxy(19, 6); cout << fname;
								coorxy(57, 6); cout << mname;
								coorxy(93, 6); cout << lname;
								coorxy(18, 8); cout << age;
								coorxy(18, 10); cout << gender;
								coorxy(56, 10); cout << lrn;
								coorxy(26, 12); cout << bmonth;
								coorxy(56, 12); cout << bday;
								coorxy(93, 12); cout << byear;
								coorxy(29, 14); cout << barangay;
								coorxy(33, 16); cout << municipality;
								coorxy(29, 18); cout << province;
								coorxy(31, 20); cout << gfname;
								coorxy(65, 20); cout << gmname;
								coorxy(97, 20); cout << glname;
								coorxy(35, 22); cout << gcnum;
								coorxy(29, 24); cout << grelation;


								loadfile.close();
								coorxy(42, 2); cout << "         ";
								coorxy(42, 2); cout << "found";
							}
							else { // if not found;


								// erasing display - done

								coorxy(19, 6); cout << string(15, ' ');
								coorxy(57, 6); cout << string(15, ' ');
								coorxy(93, 6); cout << string(15, ' ');
								coorxy(18, 8); cout << string(15, ' ');
								coorxy(18, 10); cout << string(15, ' ');
								coorxy(56, 10); cout << string(15, ' ');
								coorxy(26, 12); cout << string(15, ' ');
								coorxy(56, 12); cout << string(15, ' ');
								coorxy(93, 12); cout << string(15, ' ');
								coorxy(29, 14); cout << string(15, ' ');
								coorxy(33, 16); cout << string(15, ' ');
								coorxy(29, 18); cout << string(15, ' ');
								coorxy(31, 20); cout << string(15, ' ');
								coorxy(65, 20); cout << string(15, ' ');
								coorxy(97, 20); cout << string(15, ' ');
								coorxy(35, 22); cout << string(15, ' ');
								coorxy(29, 24); cout << string(15, ' ');


								pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "", // resetting variable values
									lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
									municipality = "", province = "", gfname = "", gmname = "",
									glname = "", gcnum = "", grelation = "", year = "", sem = "",blnc ="";

								for (int a = 0; a < 9; a++) {
									psdsub[a] = "";
								}



								// finding new empty pooling number - done

								temppool = 20240001; // temporary pooling number
								ext = 0; // confirmation exit
								do {
									string tempfinder = to_string(temppool) + ".txt";
									ifstream newfile; // making new file and check if it exist
									newfile.open(tempfinder);
									if (newfile.is_open()) {
										temppool++;
										newfile.close();
									}
									else {
										finder = to_string(temppool); // if it doesnt exist, it'll be as the current file;
										currentfile = finder + ".txt";
										ext = 1;
										break;
									}
								} while (ext != 1);
								coorxy(42, 2); cout << "not found";
							}


							coorxy(31, 2); cout << string(8, ' ');

							j = 0; // resetting the searchfinder
							temppoolnum = finder; // backuping the pooling num
							finder = ""; // resetting poolinf finder
							counter = 0;
							goto Q;
						}
					}
				}
				else {

					counter = 1;
				}
				break;
			case 1:
				coorxy(19, 6); n = getchVal(fname, 'l', 21);
				coorxy(19, 6); cout << string(21, ' ');
				coorxy(19, 6); cout << fname;//getchcout(fname);
				if (n == 101) {
					if (acc == 1) {
						counter--;
					}
					else counter = 21;
				}
				else counter++;
				goto Q;
				break;
			case 2:
				coorxy(57, 6); n = getchVal(mname, 'l', 21);
				coorxy(57, 6); cout << string(21, ' ');
				coorxy(57, 6); cout << mname; //getchcout(mname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 3:
				coorxy(93, 6); n = getchVal(lname, 'l', 23);
				coorxy(93, 6); cout << string(23, ' ');
				coorxy(93, 6); cout << lname; //getchcout(lname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 4:
				coorxy(18, 8); n = getchVal(age, 'n', 2);
				coorxy(18, 8); cout << string(2, ' ');
				coorxy(18, 8); cout << age; //getchcout(age);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 5:
				coorxy(18, 10); n = getchVal(gender, 'l', 29);
				coorxy(18, 10); cout << string(29, ' ');
				coorxy(18, 10); cout << gender; //getchcout(gender);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 6:
				coorxy(56, 10); n = getchVal(lrn, 'n', 12);
				coorxy(56, 10); cout << string(12, ' ');
				coorxy(56, 10); cout << lrn; //getchcout(lrn);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 7:
				coorxy(26, 12); n = getchVal(bmonth, 'l', 21);
				coorxy(26, 12); cout << string(21, ' ');
				coorxy(26, 12); cout << bmonth; //getchcout(bmonth);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 8:
				coorxy(56, 12); n = getchVal(bday, 'n', 2);
				coorxy(56, 12); cout << string(2, ' ');
				coorxy(56, 12); cout << bday; //getchcout(bday);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 9:
				coorxy(93, 12); n = getchVal(byear, 'n', 4);
				coorxy(93, 12); cout << string(4, ' ');
				coorxy(93, 12); cout << byear; //getchcout(byear);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 10:
				coorxy(29, 14); n = getchVal(barangay, 'l', 87);
				coorxy(29, 14); cout << string(87, ' ');
				coorxy(29, 14); cout << barangay; //getchcout(barangay);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 11:
				coorxy(33, 16); n = getchVal(municipality, 'l', 83);
				coorxy(33, 16); cout << string(83, ' ');
				coorxy(33, 16); cout << municipality; //getchcout(municipality);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 12:
				coorxy(29, 18); n = getchVal(province, 'l', 87);
				coorxy(29, 18); cout << string(87, ' ');
				coorxy(29, 18); cout << province; //getchcout(province);
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
				coorxy(31, 20); n = getchVal(gfname, 'l', 17);
				coorxy(31, 20); cout << string(17, ' ');
				coorxy(31, 20); cout << gfname;// getchcout(gfname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 14:
				coorxy(65, 20); n = getchVal(gmname, 'l', 17);
				coorxy(65, 20); cout << string(17, ' ');
				coorxy(65, 20); cout << gmname; //getchcout(gmname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 15:
				coorxy(97, 20); n = getchVal(glname, 'l', 19);
				coorxy(97, 20); cout << string(19, ' ');
				coorxy(97, 20); cout << glname; //getchcout(glname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 16:
				coorxy(35, 22); n = getchVal(gcnum, 'n', 11);
				coorxy(35, 22); cout << string(11, ' ');
				coorxy(35, 22); cout << gcnum; //getchcout(gcnum);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 17:
				coorxy(29, 24); n = getchVal(grelation, 'l', 87);
				coorxy(29, 24); cout << string(87, ' ');
				coorxy(29, 24); cout << grelation; //getchcout(grelation);
				if (n == 101) counter--;
				else counter = 19;
				break;
			case 18: // this is for help
				if (acc == 1) {
					hdc(1);
					coorxy(17, 27); cout << "<<";
					coorxy(37, 27); cout << ">>";
					char a;
					a = _getch();
					if (a == -32) {
						a = _getch();
						hdc(0);
						coorxy(17, 27); cout << "  ";
						coorxy(37, 27); cout << "  ";
						if (a == 72 || a == 75) counter--;
						else if (a == 80 || a == 77) counter++;
					}
					else if (a == 13) {

						coorxy(17, 27); cout << "  ";
						coorxy(37, 27); cout << "  ";
						coorxy(18, 27); cout << ">>";
						coorxy(36, 27); cout << "<<";
						psdbtn(20, 26, 14, 1);
						Sleep(100);
						system("cls");
						hp1();
						char hn1;
						hdc(1);
						coorxy(86, 26); cout << "<<";
						coorxy(107, 26); cout << ">>";
						buttonxy(90, 25, 14, 1);
						gotoxy(96, 26); cout << "BACK";
						do {
							hn1 = _getch();
						} while (hn1 != 13);
						coorxy(86, 26); cout << "  ";
						coorxy(107, 26); cout << "  ";
						coorxy(88, 26); cout << ">>";
						coorxy(105, 26); cout << "<<";
						psdbtn(90, 25, 14, 1);
						Sleep(100);
						system("cls");
						table();

						coorxy(26, 27); cout << "HELP";

						coorxy(19, 6); cout << fname;
						coorxy(57, 6); cout << mname;
						coorxy(93, 6); cout << lname;
						coorxy(18, 8); cout << age;
						coorxy(18, 10); cout << gender;
						coorxy(56, 10); cout << lrn;
						coorxy(26, 12); cout << bmonth;
						coorxy(56, 12); cout << bday;
						coorxy(93, 12); cout << byear;
						coorxy(29, 14); cout << barangay;
						coorxy(33, 16); cout << municipality;
						coorxy(29, 18); cout << province;
						coorxy(31, 20); cout << gfname;
						coorxy(65, 20); cout << gmname;
						coorxy(97, 20); cout << glname;
						coorxy(35, 22); cout << gcnum;
						coorxy(29, 24); cout << grelation;
						hdc(0);
					}
				}
				else {
					counter++;
				}
				break;
			case 19://add
				if (acc == 1) {
					hdc(1);
					coorxy(42, 27); cout << "<<";
					coorxy(62, 27); cout << ">>";
					char a;
					a = _getch();
					if (a == -32) {
						a = _getch();
						coorxy(42, 27); cout << "  ";
						coorxy(62, 27); cout << "  ";
						hdc(0);
						if (a == 72 || a == 75) counter--;
						else if (a == 80 || a == 77) counter++;
					}
					else if (a == 13) {
						//admin access
						coorxy(42, 27); cout << "  ";
						coorxy(62, 27); cout << "  ";
						coorxy(43, 27); cout << ">>";
						coorxy(61, 27); cout << "<<";
						psdbtn(45, 26, 14, 1);
						Sleep(100);
						// information must not be empty inorder to add or save
						hdc(0);
						if (fname != "" && mname != "" && lname != "" && age != "" && gender != "" && lrn != "" && bmonth != "" && bday != "" && byear != "" && barangay != "" && municipality != "" && province != "" && gfname != "" && gmname != "" && glname != "" && grelation != "" && gcnum != "") {


							//checking if pooling number is already registerd - done
							if (year == "" && sem == "") {
								system("cls");
								pooltble();
								do {
									//coorxy(45, 11); cout << "What year do you want to enroll? :    ";
									coorxy(80, 11); getchVal(e, 'n', 1);
								} while (e != "1" && e != "2" && e != "3" && e != "4");
								year = e;
								do {
									e = "";
									//coorxy(45, 12); cout << "Enter what semester :    ";
									coorxy(67, 13); getchVal(e, 'n', 1);
									//e += f;

								} while (e != "1" && e != "2");
								sem = e;
								e = "";
								coorxy(69, 15); cout << year << sem;

								// Pooling number table
								coorxy(56, 17); cout << temppoolnum;  // number
								pooln = temppoolnum;

								char ltp;
								hdc(1);
								coorxy(53, 22); cout << "<<";
								coorxy(73, 22); cout << ">>";
								buttonxy(56, 21, 14, 1);
								gotoxy(62, 22); cout << "OK";
								do {
									ltp = _getch();
								} while (ltp != 13);
								coorxy(53, 22); cout << "  ";
								coorxy(73, 22); cout << "  ";
								coorxy(53, 22); cout << ">>";
								coorxy(73, 22); cout << "<<";
								psdbtn(56, 21, 14, 1);
								Sleep(100);
								system("cls");
							}


							// saving the file - done

							ofstream savefile;
							savefile.open(currentfile);
							savefile << pooln + "$" + fname + "$" + mname + "$" + lname + "$" + age + "$" + gender + "$" + lrn + "$" + bmonth + "$" + bday + "$" + byear + "$" + barangay + "$" + municipality + "$" + province + "$" + gfname + "$" + gmname + "$" + glname + "$" + gcnum + "$" + grelation + "$" + year + "$" + sem +"$"+blnc+"$" << endl;
							//savefile << endl;
							for (int a = 0; a < 9; a++) {
								savefile << psdsub[a] + "$";
							}
							savefile.close();
						}
						else
						{
							hdc(1);
							gotoxy(55, 2); color(4); cout << "Please fill up all the information needed"; color(7);
							Sleep(800); gotoxy(55, 2); cout << string(45, ' ');
						}
						//finding the empty file - done

						hdc(0);
						int temppool = 20240001;
						int ext = 0;
						do {
							string tempfinder = to_string(temppool) + ".txt";
							ifstream newfile; // making new file and check if it exist
							newfile.open(tempfinder);
							if (newfile.is_open()) {
								temppool++;
								newfile.close();
							}
							else {
								temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
								currentfile = temppoolnum + ".txt";
								ext = 1;
								break;
							}
						} while (ext != 1);


						coorxy(43, 27); cout << "  ";
						coorxy(61, 27); cout << "  ";

						//Erasing Values - done

						pooln = "", fname = "", mname = "", lname = "", age = "", gender = "",
							lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
							municipality = "", province = "", gfname = "", gmname = "",
							glname = "", gcnum = "", grelation = "", year = "", sem = "",blnc="";

						for (int a = 0; a < 9; a++) {
							psdsub[a] = "";
						}

						system("cls");
						table();

						if (acc != 1) { // display access table
							for (int a = 26; a <= 29; a++) {
								coorxy(69, a); cout << string(17, ' ');
							}

							for (int a = 1; a <= 3; a++) {
								coorxy(0, a); cout << string(50, ' ');
							}

							coorxy(48, 27); cout << string(10, ' ');
							coorxy(51, 27); cout << "ADD";
						}

					}
				}
				else {
					hdc(1);
					coorxy(42, 27); cout << "<<";
					coorxy(62, 27); cout << ">>";
					char a;
					a = _getch();
					if (a == -32) {
						a = _getch();
						hdc(0);
						coorxy(42, 27); cout << "  ";
						coorxy(62, 27); cout << "  ";
						if (a == 72 || a == 75) counter = 17;
						else if (a == 80 || a == 77) counter++;
					}
					else if (a == 13) {

						coorxy(42, 27); cout << "  ";
						coorxy(62, 27); cout << "  ";
						coorxy(43, 27); cout << ">>";
						coorxy(61, 27); cout << "<<";
						psdbtn(45, 26, 14, 1);
						Sleep(100);
						system("cls");
						hp1();
						char hn1;
						hdc(1);
						coorxy(86, 26); cout << "<<";
						coorxy(107, 26); cout << ">>";
						buttonxy(90, 25, 14, 1);
						gotoxy(96, 26); cout << "BACK";
						do {
							hn1 = _getch();
						} while (hn1 != 13);
						coorxy(86, 26); cout << "  ";
						coorxy(107, 26); cout << "  ";
						coorxy(88, 26); cout << ">>";
						coorxy(105, 26); cout << "<<";
						psdbtn(90, 25, 14, 1);
						Sleep(100);
						system("cls");
						table();

						for (int a = 1; a <= 3; a++) {
							coorxy(0, a); cout << string(50, ' ');
						}
						for (int a = 26; a <= 29; a++) {
							coorxy(20, a); cout << string(17, ' ');
						}

						coorxy(48, 27); cout << string(10, ' ');
						coorxy(51, 27); cout << "HELP";
						coorxy(75, 27); cout << string(6, ' ');
						coorxy(76, 27); cout << "ADD";
						coorxy(70, 2); cout << string(45, ' ');
						//coorxy(3, 2); cout << "BSIT Student Enrollment Management System";
						// youre here;

						coorxy(19, 6); cout << fname;
						coorxy(57, 6); cout << mname;
						coorxy(93, 6); cout << lname;
						coorxy(18, 8); cout << age;
						coorxy(18, 10); cout << gender;
						coorxy(56, 10); cout << lrn;
						coorxy(26, 12); cout << bmonth;
						coorxy(56, 12); cout << bday;
						coorxy(93, 12); cout << byear;
						coorxy(29, 14); cout << barangay;
						coorxy(33, 16); cout << municipality;
						coorxy(29, 18); cout << province;
						coorxy(31, 20); cout << gfname;
						coorxy(65, 20); cout << gmname;
						coorxy(97, 20); cout << glname;
						coorxy(35, 22); cout << gcnum;
						coorxy(29, 24); cout << grelation;
						hdc(0);
					}
				}
				break;
			case 20://delete
				if (acc == 1) { // admin access

					// youre here

					coorxy(67, 27); cout << "<<";
					coorxy(87, 27); cout << ">>";
					hdc(1);
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
						i;
						coorxy(67, 27); cout << "  ";
						coorxy(87, 27); cout << "  ";
						coorxy(68, 27); cout << ">>";
						coorxy(86, 27); cout << "<<";
						psdbtn(70, 26, 14, 1);
						Sleep(100);
						hdc(0);

						// Youre here at deleting the file

						remove(currentfile.c_str());

						// Erasing Values - done

						pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "",
							lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
							municipality = "", province = "", gfname = "", gmname = "",
							glname = "", gcnum = "", grelation = "", year = "", sem = "",blnc ="";

						for (int a = 0; a < 9; a++) {
							psdsub[a] = "";
						}

						n = 0;
						coorxy(3, 27); cout << string(20, ' ');
						coorxy(28, 27); cout << ' ';
						for (int x = 0; x < 2; x++) {
							coorxy(3, 26 + n); cout << string(26, ' ');
							n += 2;
						}
						//finding the empty file - done
						int temppool = 20240001;
						int ext = 0;
						do {
							string tempfinder = to_string(temppool) + ".txt";
							ifstream newfile; // making new file and check if it exist
							newfile.open(tempfinder);
							if (newfile.is_open()) {
								temppool++;
								newfile.close();
							}
							else {
								temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
								currentfile = temppoolnum + ".txt";
								ext = 1;
								break;
							}
						} while (ext != 1);

						coorxy(68, 27); cout << "  ";
						coorxy(86, 27); cout << "  ";
						system("cls");
						table();
					}
				}
				else {
					hdc(1);
					coorxy(67, 27); cout << "<<";
					coorxy(87, 27); cout << ">>";
					char a;
					a = _getch();
					if (a == -32) {
						a = _getch();
						coorxy(67, 27); cout << "  ";
						coorxy(87, 27); cout << "  ";
						if (a == 72 || a == 75) counter--;
						else if (a == 80 || a == 77) counter++;
					}
					else if (a == 13) {

						coorxy(67, 27); cout << "  ";
						coorxy(87, 27); cout << "  ";
						coorxy(68, 27); cout << ">>";
						coorxy(86, 27); cout << "<<";
						psdbtn(70, 26, 14, 1);
						Sleep(100);

						// information must not be empty inorder to add or save
						hdc(0);
						if (fname != "" && mname != "" && lname != "" && age != "" && gender != "" && lrn != "" && bmonth != "" && bday != "" && byear != "" && barangay != "" && municipality != "" && province != "" && gfname != "" && gmname != "" && glname != "" && grelation != "" && gcnum != "") {


							//checking if pooling number is already registerd - done

							if (year == "" && sem == "") {
								system("cls");
								pooltble();
								do {
									//coorxy(45, 11); cout << "What year do you want to enroll? :    ";
									coorxy(80, 11); getchVal(e, 'n', 1);
								} while (e != "1" && e != "2" && e != "3" && e != "4");
								year = e;
								do {
									e = "";
									//coorxy(45, 12); cout << "Enter what semester :    ";
									coorxy(67, 13); getchVal(e, 'n', 1);
									//e += f;

								} while (e != "1" && e != "2");
								sem = e;
								e = "";
								coorxy(69, 15); cout << year << sem;

								// Pooling number table
								coorxy(56, 17); cout << temppoolnum;  // number
								pooln = temppoolnum;

								char ltp;
								hdc(1);
								coorxy(53, 22); cout << "<<";
								coorxy(73, 22); cout << ">>";
								buttonxy(56, 21, 14, 1);
								gotoxy(62, 22); cout << "OK";
								do {
									ltp = _getch();
								} while (ltp != 13);
								coorxy(53, 22); cout << "  ";
								coorxy(73, 22); cout << "  ";
								coorxy(53, 22); cout << ">>";
								coorxy(73, 22); cout << "<<";
								psdbtn(56, 21, 14, 1);
								Sleep(100);
								system("cls");
							}


							// saving the file - done

							ofstream savefile;
							savefile.open(currentfile);
							savefile << pooln + "$" + fname + "$" + mname + "$" + lname + "$" + age + "$" + gender + "$" + lrn + "$" + bmonth + "$" + bday + "$" + byear + "$" + barangay + "$" + municipality + "$" + province + "$" + gfname + "$" + gmname + "$" + glname + "$" + gcnum + "$" + grelation + "$" + year + "$" + sem +"$"+blnc +"$" << endl;
							//savefile << endl;
							for (int a = 0; a < 9; a++) {
								savefile << psdsub[a] + "$";
							}
							savefile.close();
						}
						else
						{
							hdc(1);
							gotoxy(40, 2); color(4); cout << "Please fill up all the information needed"; color(7);
							Sleep(800); gotoxy(55, 2); cout << string(45, ' ');
						}
						//finding the empty file - done

						hdc(0);
						int temppool = 20240001;
						int ext = 0;
						do {
							string tempfinder = to_string(temppool) + ".txt";
							ifstream newfile; // making new file and check if it exist
							newfile.open(tempfinder);
							if (newfile.is_open()) {
								temppool++;
								newfile.close();
							}
							else {
								temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
								currentfile = temppoolnum + ".txt";
								ext = 1;
								break;
							}
						} while (ext != 1);


						coorxy(43, 27); cout << "  ";
						coorxy(61, 27); cout << "  ";

						//Erasing Values - done

						pooln = "", fname = "", mname = "", lname = "", age = "", gender = "",
							lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
							municipality = "", province = "", gfname = "", gmname = "",
							glname = "", gcnum = "", grelation = "", year = "", sem = "",blnc = "";

						for (int a = 0; a < 9; a++) {
							psdsub[a] = "";
						}

						system("cls");
						table();

						if (acc != 1) { // display access table
							for (int a = 1; a <= 3; a++) {
								coorxy(0, a); cout << string(50, ' ');
							}
							for (int a = 26; a <= 29; a++) {
								coorxy(20, a); cout << string(17, ' ');
							}

							coorxy(48, 27); cout << string(10, ' ');
							coorxy(51, 27); cout << "HELP";
							coorxy(67, 27); cout << "  ";
							coorxy(87, 27); cout << "  ";
							coorxy(75, 27); cout << string(6, ' ');
							coorxy(76, 27); cout << "ADD";
						}
						coorxy(70, 2); cout << string(45, ' ');

					}
					break;
				}
				break;

			case 21://back
				hdc(1);
				coorxy(92, 27); cout << "<<";
				coorxy(112, 27); cout << ">>";
				char c;
				c = _getch();
				if (c == -32) {
					c = _getch();
					coorxy(92, 27); cout << "  ";
					coorxy(112, 27); cout << "  ";
					hdc(0);
					if (c == 72 || c == 75) {
						/*if (acc == 1) {
							counter--;
						}
						else counter++;*/
						counter--;
					}
					else if (c == 80 || c == 77) {
						if (acc == 1) counter = 0;
						else counter = 1;
					}
				}
				else if (c == 13) {
					coorxy(92, 27); cout << "  ";
					coorxy(112, 27); cout << "  ";
					coorxy(93, 27); cout << ">>";
					coorxy(111, 27); cout << "<<";
					psdbtn(95, 26, 14, 1);
					Sleep(100);
					system("cls");
					hdc(0);
					exit = 1;
				}
				break;
			}
			if (exit == 1) break;
		}
		system("cls");
	}

	else if (x == 2) {
		string var[45]; // variables
		string year; // variable for searching year
		string sem; // variable for searching sem
		string temp; // temporary storage for searching file
		string ysuff, ssuff;


		int counter = 0; // counter for option
		int ext = 0; // exit confirmation
		int cntr = 0; // counter for database
		int dltd = 0; // variable for empty subject
		int st; // storage for returning value

		//variables for display
		cx = 37; // x position
		cy = 8; // y position

		//variables for display - for year and sem
		int dn = 0;
		int r = 0;
		int lvar = 0;
		int num = 1;

		tablec();


		if (acc != 1) {
			for (int a = 26; a <= 28; a++) {
				//coorxy(57, a); cout << string(40, ' ');
				coorxy(10, a); cout << string(85, ' ');
			}
			coorxy(71, 27); cout << string(14, ' ');

			buttonxy(70, 26, 14, 1);
			coorxy(76, 27); cout << "HELP";
		}

		// doing the switching rows - done

		do {

		W:
			hdc(1);
			for (int a = 8; a <= 24; a++) {
				coorxy(1, a); cout << " ";
			}

			switch (counter) {

			case 0:
				hdc(0);
				coorxy(20, 2); st = getchValc(year, 'n', 1);
				coorxy(20, 2); cout << string(1, ' ');
				coorxy(20, 2); cout << year;
				if (st == 111) counter++;
				else if (st == 100) goto W;
				goto W;
				break;

			case 1:
				hdc(0);
				coorxy(64, 2); st = getchValc(sem, 'n', 1);
				coorxy(64, 2); cout << string(1, ' ');
				coorxy(64, 2); cout << sem;
				coorxy(64, 2);
				if (st == 101) counter--;
				else if (st == 111) {
					if (sem == "") {
						counter = 11;
						cx = 3;
						cy = 8;
						if (acc == 1)
						{
							color(8);
							buttonxy(45, 26, 14, 1);
							coorxy(48, 27); cout << "ADD/UPDATE";
							buttonxy(70, 26, 14, 1);
							coorxy(75, 27); cout << "DELETE";
							color(7);
						}
					

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								coorxy(cx, cy); cout << string(3, ' '); // no
								cx += 4;
								coorxy(cx, cy); cout << string(19, ' '); // year level
								cx += 20;
								coorxy(cx, cy); cout << string(14, ' '); // subject code
								cx += 15;
								coorxy(cx, cy); cout << string(48, ' '); // subject description
								cx += 49;
								coorxy(cx, cy); cout << string(6, ' '); // credits
								cx += 7;
								coorxy(cx, cy); cout << string(20, ' '); // subject pre requisites (both 1 & 2)
							}
							cy += 2;
							cx = 3;
						}

						hdc(1);
						goto W;
					}
					else {
						if (acc == 1) {
							buttonxy(45, 26, 14, 1);
							coorxy(48, 27); cout << "ADD/UPDATE";

							buttonxy(70, 26, 14, 1);
							coorxy(75, 27); cout << "DELETE";
							counter++;
						}
						else {
							counter = 11;
						}
					}

					// Erasing variables first

					for (int z = 0; z < 45; z++) {
						var[z] = "";
					}

					// Clearing display

					cx = 3;
					cy = 8;

					for (int z = 0; z < 9; z++) {
						coorxy(cx, cy);
						for (int x = 0; x < 1; x++) {
							coorxy(cx, cy); cout << string(3, ' '); // no
							cx += 4;
							coorxy(cx, cy); cout << string(19, ' '); // year level
							cx += 20;
							coorxy(cx, cy); cout << string(14, ' '); // subject code
							cx += 15;
							coorxy(cx, cy); cout << string(48, ' '); // subject description
							cx += 49;
							coorxy(cx, cy); cout << string(6, ' '); // credits
							cx += 7;
							coorxy(cx, cy); cout << string(20, ' '); // subject pre requisites (both 1 & 2)
						}
						cy += 2;
						cx = 3;
					}




					// Loading file

					if ((year == "1" || year == "2" || year == "3" || year == "4") && (sem == "1" || sem == "2")) {

						temp = year + sem + ".txt";
						ifstream openf(temp);
						if (openf.is_open()) { // if found

							//reset display

							r = 0;
							dn = 0;
							cntr = 0;
							string line;
							for (int z = 0; z < 9; z++) {
								getline(openf, line);
								stringstream ss(line);

								for (int x = 0; x < 5; x++) {
									getline(ss, var[cntr], '$');
									cntr++;
								}
							}
						}
						openf.close();

						// displaying the variables

						/*if (year == "1" && sem == "1")
						{
							ysuff = "st";
							ssuff = "st";
						}
						else if (year == "1" && sem == "2")
						{
							ysuff = "st";
							ssuff = "nd";
						}
						else if (year == "2" && sem == "1")
						{
							ysuff = "nd";
							ssuff = "st";
						}
						else if (year == "2" && sem == "2")
						{
							ysuff = "nd";
							ssuff = "nd";
						}
						else if (year == "3" && sem == "1")
						{
							ysuff = "rd";
							ssuff = "st";
						}
						else if (year == "3" && sem == "2")
						{
							ysuff = "rd";
							ssuff = "nd";
						}
						else if (year == "4" && sem == "1")
						{
							ysuff = "th";
							ssuff = "st";
						}
						else if (year == "4" && sem == "2")
						{
							ysuff = "th";
							ssuff = "nd";
						}*/

						cx = 28;
						cy = 8;
						lvar = 0;
						r = 0;
						dn = 0;
						num = 1;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								if (var[r] != "") {// skip if subject code is empty
									coorxy(cx, cy); cout << var[lvar]; // subject code
									cx += 15;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // description
									cx += 49;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // credits
									cx += 7;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // prse req 1
									cx += 10;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // pre req 2
									lvar++;
									coorxy(8, 8 + dn); cout << " Year " << year << " / " << "sem " << sem; // year level
									coorxy(4, 8 + dn); cout << num; // No.
									num++;
									dn += 2;
									cy += 2;
								}
								else {
									lvar += 5;
								}
							}
							r += 5;
							cx = 28;
						}
					}
					else { // if not existing

						// resetting year and sem

						year = "";
						sem = "";

						coorxy(20, 2); cout << string(20, ' '); // erasing searchbar for year
						coorxy(64, 2); cout << string(20, ' '); // erasing searchbar for sem

						// Erasing variables first

						for (int z = 0; z < 45; z++) {
							var[z] = "";
						}

						// Clearing display

						cx = 3;
						cy = 8;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								coorxy(cx, cy); cout << string(3, ' '); // no
								cx += 4;
								coorxy(cx, cy); cout << string(19, ' '); // year level
								cx += 20;
								coorxy(cx, cy); cout << string(14, ' '); // subject code
								cx += 15;
								coorxy(cx, cy); cout << string(48, ' '); // subject description
								cx += 49;
								coorxy(cx, cy); cout << string(6, ' '); // credits
								cx += 7;
								coorxy(cx, cy); cout << string(20, ' '); // subject pre requisites (both 1 & 2)
							}
							cy += 2;
							cx = 3;
						}

						counter = 11;
					}
				}

				goto W;
				break;
			case 2:
				coorxy(1, 8); cout << char(175);
				switch (_getch()) {
				case 72:
					counter = 0;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[0], var[1], var[2], var[3], var[4], 0, 8, 0);
					break;
				case 8:
					multival(var[0], var[1], var[2], var[3], var[4], 0, 8, 1);
					break;
				}
				goto W;
				break;
			case 3:
				coorxy(1, 10); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[5], var[6], var[7], var[8], var[9], 0, 10, 0);
					break;
				case 8:
					multival(var[5], var[6], var[7], var[8], var[9], 0, 10, 1);
					break;
				}
				goto W;
				break;
			case 4:
				coorxy(1, 12); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[10], var[11], var[12], var[13], var[14], 0, 12, 0);
					break;
				case 8:
					multival(var[10], var[11], var[12], var[13], var[14], 0, 12, 1);
					break;
				}
				goto W;
				break;
			case 5:
				coorxy(1, 14); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[15], var[16], var[17], var[18], var[19], 0, 14, 0);
					break;
				case 8:
					multival(var[15], var[16], var[17], var[18], var[19], 0, 14, 1);
					break;
				}
				goto W;
				break;
			case 6:
				coorxy(1, 16); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[20], var[21], var[22], var[23], var[24], 0, 16, 0);
					break;
				case 8:
					multival(var[20], var[21], var[22], var[23], var[24], 0, 16, 1);
					break;
				}
				goto W;
				break;
			case 7:
				coorxy(1, 18); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[25], var[26], var[27], var[28], var[29], 0, 18, 0);
					break;
				case 8:
					multival(var[25], var[26], var[27], var[28], var[29], 0, 18, 1);
					break;
				}
				goto W;
				break;
			case 8:
				coorxy(1, 20); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[30], var[31], var[32], var[33], var[34], 0, 20, 0);
					break;
				case 8:
					multival(var[30], var[31], var[32], var[33], var[34], 0, 20, 1);
					break;
				}
				goto W;
				break;
			case 9:
				coorxy(1, 22); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[35], var[36], var[37], var[38], var[39], 0, 22, 0);
					break;
				case 8:
					multival(var[35], var[36], var[37], var[38], var[39], 0, 22, 1);
					break;
				}
				goto W;
				break;
			case 10:
				coorxy(1, 24); cout << char(175);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[40], var[41], var[42], var[43], var[44], 0, 24, 0);
					break;
				case 8:
					multival(var[40], var[41], var[42], var[43], var[44], 0, 24, 1);
					break;
				}
				goto W;
				break;
			case 11://help button
				hdc(1);
				if (acc == 1) {
					coorxy(17, 27); cout << "<< ";
					coorxy(37, 27); cout << " >>";

					switch (_getch()) {

					case 72:
					case 75:
						if (year == "" && sem == "") {
							counter = 0;
						}
						else {
							counter--;
						}
						break;
					case 80:
					case 77:
						if (year == "" && sem == "") {
							counter = 14;
						}
						else {
							counter++;
						}
						break;
					case 13:
						coorxy(17, 27); cout << ">>";
						coorxy(37, 27); cout << "<<";
						psdbtn(20, 26, 15, 1);
						Sleep(100);
						system("cls");
						hp1();
						char hn1;
						hdc(1);
						coorxy(86, 26); cout << "<<";
						coorxy(107, 26); cout << ">>";
						buttonxy(90, 25, 14, 1);
						gotoxy(96, 26); cout << "BACK";
						do {
							hn1 = _getch();
						} while (hn1 != 13);
						coorxy(86, 26); cout << "  ";
						coorxy(107, 26); cout << "  ";
						coorxy(88, 26); cout << ">>";
						coorxy(105, 26); cout << "<<";
						psdbtn(90, 25, 14, 1);
						Sleep(100);
						system("cls");
						tablec();
						coorxy(20, 2); cout << year;
						coorxy(64, 2); cout << sem;
						cx = 28;
						cy = 8;
						lvar = 0;
						r = 0;
						dn = 0;
						num = 1;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								if (var[r] != "") {// skip if subject code is empty
									coorxy(cx, cy); cout << var[lvar]; // subject code
									cx += 15;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // description
									cx += 49;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // credits
									cx += 7;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // prse req 1
									cx += 10;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // pre req 2
									lvar++;
									coorxy(8, 8 + dn); cout << " Year " << year << " / " << "sem " << sem; // year level
									coorxy(4, 8 + dn); cout << num; // No.
									num++;
									dn += 2;
									cy += 2;
								}
								else {
									lvar += 5;
								}
							}
							r += 5;
							cx = 28;
						}
						hdc(0);
						break;
					}
					coorxy(17, 27); cout << "   ";
					coorxy(37, 27); cout << "   ";
				}
				else { //help user access
					coorxy(67, 27); cout << "<<";
					coorxy(87, 27); cout << ">>";
					switch (_getch()) {
					case 72:
					case 75:
						if (acc == 1) {
							counter--;
						}
						else {
							counter = 0;
						}
						break;
					case 80:
					case 77:
						if (acc == 1) {
							counter++;
						}
						else {
							counter = 14;
						}
						break;
					case 13:
						coorxy(67, 27); cout << ">>";
						coorxy(86, 27); cout << "<<";
						psdbtn(70, 26, 14, 1);
						Sleep(100);
						system("cls");
						hp1();
						char hn1;
						hdc(1);
						coorxy(86, 26); cout << "<<";
						coorxy(107, 26); cout << ">>";
						buttonxy(90, 25, 14, 1);
						gotoxy(96, 26); cout << "BACK";
						do {
							hn1 = _getch();
						} while (hn1 != 13);
						coorxy(86, 26); cout << "  ";
						coorxy(107, 26); cout << "  ";
						coorxy(88, 26); cout << ">>";
						coorxy(105, 26); cout << "<<";
						psdbtn(90, 25, 14, 1);
						Sleep(100);
						system("cls");
						tablec();
						coorxy(20, 2); cout << year;
						coorxy(64, 2); cout << sem;
						cx = 28;
						cy = 8;
						lvar = 0;
						r = 0;
						dn = 0;
						num = 1;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								if (var[r] != "") {// skip if subject code is empty
									coorxy(cx, cy); cout << var[lvar]; // subject code
									cx += 15;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // description
									cx += 49;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // credits
									cx += 7;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // prse req 1
									cx += 10;
									lvar++;
									coorxy(cx, cy); cout << var[lvar]; // pre req 2
									lvar++;
									coorxy(8, 8 + dn); cout << " Year " << year << " / " << "sem " << sem; // year level
									coorxy(4, 8 + dn); cout << num; // No.
									num++;
									dn += 2;
									cy += 2;
								}
								else {
									lvar += 5;
								}
							}
							r += 5;
							cx = 28;
						}
						hdc(0);

						for (int a = 26; a <= 28; a++) {
							coorxy(10, a); cout << string(60, ' ');
						}
						coorxy(71, 27); cout << string(14, ' ');
						buttonxy(70, 26, 14, 1);	
						coorxy(76, 27); cout << "HELP";
						break;
					}

					// Deleting display access

					coorxy(67, 27); cout << "   ";
					coorxy(86, 27); cout << "   ";
				}
				break;
			case 12:// add
				coorxy(42, 27); cout << "<<";
				coorxy(62, 27); cout << ">>";

				switch (_getch()) {

				case 72:
				case 75:
					counter--;
					break;
				case 80:
				case 77:
					counter++;
					break;
				case 13:
					coorxy(42, 27); cout << ">>";
					coorxy(62, 27); cout << "<<";
					psdbtn(45, 26, 14, 1);
					Sleep(100);

					// Add / update here to data base

					if (temp != "") { // condition to check temporary file is empty
						cntr = 0;
						r = 0;
						dltd = 0;
						ofstream savefile;
						savefile.open(temp);
						for (int z = 0; z < 9; z++) { // this is for saving existing subject
							if (var[r] != "") { // this is to check if subject is not empty
								for (int x = 0; x < 5; x++) {
									savefile << var[cntr] + "$";
									cntr++;
								}
								savefile << endl;
							}
							else { // if subject is empty
								cntr += 5; // this is to skip the iteration of variables
								dltd++; // this is the counter of how many subject is emtpy
							}
							r += 5;
						}
						for (int z = 0; z < dltd; z++) { // this is to add empty lines in the end depending on how many subject is empty
							savefile << "$$$$$" << endl;
						}
						savefile.close();
					}
					year = "";
					sem = "";
					counter = 0;
					system("cls");
					tablec();

					break;
				}

				coorxy(42, 27); cout << "   ";
				coorxy(62, 27); cout << "   ";
				goto W;
				break;
			case 13:// delete button
				coorxy(67, 27); cout << "<<";
				coorxy(87, 27); cout << ">>";
				switch (_getch()) {
				case 72:
				case 75:
					counter--;
					break;
				case 80:
				case 77:
					counter++;
					break;
				case 13:
					coorxy(67, 27); cout << ">>";
					coorxy(86, 27); cout << "<<";
					psdbtn(70, 26, 14, 1);
					Sleep(100);


					// deleting file

					// Erasing

					for (int z = 0; z < 36; z++) {
						var[z] = "";
					}

					if (temp != "") { // condition to check temporary file is empty
						cntr = 0;
						ofstream savefile;
						savefile.open(temp);
						for (int z = 0; z < 9; z++) {
							for (int x = 0; x < 5; x++) {
								savefile << var[cntr] + "$";
								cntr++;
							}
							savefile << endl;
						}
						savefile.close();
					}
					year = "";
					sem = "";
					counter = 0;
					system("cls");
					tablec();


					remove(temp.c_str());
					break;
				}
				coorxy(67, 27); cout << "   ";
				coorxy(86, 27); cout << "   ";
				goto W;
				break;
			case 14: // back
				coorxy(92, 27); cout << "<<";
				coorxy(112, 27); cout << ">>";
				switch (_getch()) {
				case 72:
				case 75:
					if (year == "" && sem == "") {
						counter = 11;
					}
					else {
						if (acc == 1) {
							counter--;
						}
						else {
							counter = 11;
						}
					}
					coorxy(92, 27); cout << "  ";
					coorxy(112, 27); cout << "  ";
					hdc(0);
					goto W;
					break;
				case 80:
				case 77:
					counter = 0;
					coorxy(92, 27); cout << "  ";
					coorxy(112, 27); cout << "  ";
					hdc(0);
					goto W;
					break;
				case 13:
					coorxy(92, 27); cout << " >>";
					coorxy(112, 27); cout << "<< ";
					psdbtn(95, 26, 14, 1);
					Sleep(100);
					ext = 1;
					break;
				}
				coorxy(92, 27); cout << "   ";
				coorxy(112, 27); cout << "   ";
				break;
			}
		} while (ext != 1);
		system("cls");


	}

	else if (x == 3) {
		//menu(2);
	estrt:
		int lcntr; // local counter // inside switch
		int tempre; // return value storage
		int cntr = 0; // counter for first switch
		int v = 0; // temporary variable storage for storing sub
		int n1 = 0; // counter for number of prereq
		int lext = 0; // local exit counter
		int prereq = 0; // counter for pre req
		int y = 0; // counter for how many subject have pre requisites
		int precode = 0; // subject code for no pre req sub
		//int v; // just a global counter
		int cnf = 0; // local confirmation
		int cx = 0; // variable for gotoxy x
		int cy = 0; // variable for gotoxy y
		int index = 0; // variable for declaring index
		int sz = 0; // size of the loop
		int v1 = 0; // page3 local counter variable
		int unt = 0; // total number of units
		int ttlpmt = 0; // total payment = total units * 100
		int svdbl = 0; // saved balance

		string subfile;
		string stinfo[21]; // storage for student information

		string finder; // finder storage
		string dssub[45]; // storage for incoming subject
		string presub[45]; // storage for previous sub
		string subnoprq[45]; // subject that has no pre req
		//string prereqsub[9]; // subject that have pre-requisites
		string psdsub[9]; // passed subject
		//string allsub[360]; // all subject
		char cn1; // local confirmation



	R:
		switch (cntr) {
		case 0:
			page1(); // display table
			/*menudes(30, 17);*/
			tempre = 0;
			lcntr = 0;
			finder = "";

		E:

			// Switch for local option

			switch (lcntr) {
			case 0:
				hdc(0);
				coorxy(37, 4); tempre = getchVal2(finder, 'n', 8);
				coorxy(37, 4); cout << string(8, ' ');
				coorxy(37, 4); cout << finder;
				if (tempre == 101) { coorxy(54, 4); cout << "         "; lcntr = 2; }//UP
				else if (tempre == 110) { coorxy(54, 4); cout << "         "; lcntr++; }//DOWN
				else if (tempre == 100) goto E;
				else if (tempre == 111) {//ENTER

					string txtfile = finder + ".txt";
					ifstream file(txtfile);

					if (file.is_open()) {

						string line;
						getline(file, line);
						stringstream ss(line);
						for (int a = 0; a < 21; a++) {
							getline(ss, stinfo[a], '$');
						}
						/*while (getline(file, line)) {
							stringstream ss(line);
							for (int x = 0; x < 21; x++) {
								getline(ss, stinfo[x], '$');
							}
						}*/

						// erase display - done
						coorxy(18, 8); cout << string(22, ' '); // surname
						coorxy(55, 8); cout << string(23, ' '); // firstname
						coorxy(93, 8); cout << string(18, ' '); // middle name
						coorxy(14, 10); cout << string(9, ' ');// age
						coorxy(44, 10); cout << string(10, ' ');// gender
						coorxy(69, 10); cout << string(15, ' ');// lrn
						coorxy(22, 12); cout << string(70, ' ');// address
						coorxy(25, 14); cout << string(5, ' ');// year
						coorxy(74, 14); cout << string(5, ' ');// sem

						// display
						coorxy(19, 8); cout << stinfo[3]; // surname
						coorxy(55, 8); cout << stinfo[1]; // first name
						coorxy(93, 8); cout << stinfo[2]; // middle name
						coorxy(17, 10); cout << stinfo[4]; // age
						coorxy(44, 10); cout << stinfo[5]; // gender
						coorxy(68, 10); cout << stinfo[6]; // lrn
						coorxy(23, 12); cout << stinfo[10] << " " << stinfo[11] << " " << stinfo[12]; // address
						coorxy(28, 14); cout << stinfo[18]; // year
						coorxy(76, 14); cout << stinfo[19]; // sem

						coorxy(54, 4); cout << "         ";
						coorxy(54, 4); cout << "found";
					}
					else {
						finder = "";
						coorxy(37, 4); cout << string(8, ' ');
						coorxy(37, 4); cout << finder;

						// remove values

						for (int x = 0; x < 21; x++) {
							stinfo[x] = "";
						}

						// erase display - done
						coorxy(18, 8); cout << string(22, ' '); // surname
						coorxy(55, 8); cout << string(22, ' '); // firstname
						coorxy(93, 8); cout << string(18, ' '); // middle name
						coorxy(14, 10); cout << string(9, ' ');// age
						coorxy(44, 10); cout << string(10, ' ');// gender
						coorxy(69, 10); cout << string(15, ' ');// lrn
						coorxy(22, 12); cout << string(70, ' ');// address
						coorxy(25, 14); cout << string(5, ' ');// year
						coorxy(74, 14); cout << string(5, ' ');// sem


						coorxy(54, 4); cout << "         ";
						coorxy(54, 4); cout << "not found";
						for (int a = 0; a < 9; a++) {
							psdsub[a] = "";
						}

						goto E;
					}
					file.close();

					// Open another ifstream for future subject

					v = 0;
					string subf;
					subf = stinfo[18] + stinfo[19] + ".txt";
					ifstream subtxt(subf);
					if (subtxt.is_open()) {
						string line;
						for (int x = 0; x < 9; x++) {
							getline(subtxt, line);
							stringstream ss(line);
							if (line.substr(0) != "$$$$$") { // check if subject is not empty
								for (int y = 0; y < 5; y++) {
									getline(ss, dssub[v], '$');
									v++;
								}
							}
						}
					}
					subtxt.close();

					// open another ifstream to get all subjects


					v = 0;

					ofstream savefile;
					savefile.open("allsub.txt");
					for (int a = 1; a <= 4; a++) {
						string yr, loadfile;
						yr = to_string(a);
						for (int s = 1; s <= 2; s++) {
							string sm, fl;
							sm = to_string(s);
							fl = yr + sm + ".txt";
							ifstream loadfile(fl);
							if (loadfile.is_open()) {
								string line;
								for (int d = 0; d < 9; d++) {
									getline(loadfile, line);
									//stringstream ss(line);
									if (line.substr(0) != "$$$$$") { // check if subject is not empty
										savefile << line << endl;
										/*for (int f = 0; f < 5; f++) {
											getline(ss, allsub[v], '$');
											v++;
										}*/
									}
								}
							}
							loadfile.close();
						}
					}
					savefile.close();
					lcntr++;
				}
				goto E;
				break;
			case 1:

				// Enroll Button
				hdc(1);
				coorxy(36, 19); cout << "<< ";
				coorxy(55, 19); cout << " >>";
				//buttonxy2(80, 16, 14, 1, 2);
				switch (_getch()) {
				case 224:
					switch (_getch()) { // Get the second value
					case 72: // Up arrow
					case 75:
						lcntr--;
						break;
					case 80: // Down arrow
					case 77:
						lcntr++;
						break;
					}
					coorxy(36, 19); cout << "   ";
					coorxy(55, 19); cout << "   ";
					goto E;
					break;
				case 13: // proceed to enroll

					Sleep(100);
					lext = 0;
					if (finder == "")
			        {
						coorxy(54, 4); color(4); cout << "Search a Student Pooling Number!"; color(7);
						Sleep(1500);
						coorxy(54, 4); cout << string(35, ' ');
					}

					for (int x = 0; x < 20; x++) {
						if (stinfo[x] == "") {
							break;
						}
						else {
							lext = 1;
						}
					}

					if (lext == 1) {
						coorxy(36, 19); cout << ">> ";
						coorxy(55, 19); cout << " <<";
						buttonxy2(39, 18, 14, 1, 1);
						Sleep(100);
						system("cls");
						cntr++;
						subfile = stinfo[18] + stinfo[19];
						goto R;
					}
					else goto E;
				default:
					goto E;
				}
				break;
			case 2:

				// Back button

				hdc(1);
				coorxy(61, 19); cout << "<< ";
				coorxy(80, 19); cout << " >>";
				//buttonxy2(100, 16, 14, 1, 2);
				switch (_getch()) {
				case 224:
					switch (_getch()) { // Get the second value
					case 72: // Up arrow
					case 75:
						lcntr--;
						break;
					case 80: // Down arrow
					case 77:
						lcntr = 0;
						break;
					}
					coorxy(61, 19); cout << "   ";
					coorxy(80, 19); cout << "   ";
					goto E;
				case 13:
					coorxy(61, 19); cout << ">>";
					coorxy(80, 19); cout << " <<";
					buttonxy2(64, 18, 14, 1, 1);
					Sleep(150);
					system("cls");


					// Back to main menu here

					break;
				default:
					goto E;
				}

				break;
			} // this is for local switch
			break;

		case 1: // SECOND PAGE

			//checking if student have balance/is enrolled

			if (stinfo[20] != "") {
				svdbl = stoi(stinfo[20]);

				// backuping subjects

				ifstream loadfile;
				loadfile.open(finder + ".txt");
				if (loadfile.is_open()) {
					string line;
					for (int a = 0; a < 2; a++) {
						getline(loadfile, line);
						if (line.substr(0, 4) != "2024") {
							stringstream ss(line);
							for (int a = 0; a < 9; a++) {
								getline(ss, psdsub[a], '$');
							}
						}
					}
				}



				cntr++;
				goto R;
			}


			hdc(0);
			if (stinfo[18] == "1" && stinfo[19] == "1") { // if freshman
				cntr++;
				system("cls");
				goto R;
			}
			else if ((stinfo[18] == "2" && stinfo[19] == "1") || (stinfo[18] == "3" && stinfo[19] == "1") || (stinfo[18] == "4" && stinfo[19] == "1")) { // getting the previos sub last year
				//Z:
				page2();

				// Getting the prereq subs - done

				prereq = 3;
				y = 0; // counter for how many subject have pre requisites
				precode = 0; // subject code for no pre req sub
				v = 0;
				string prereqsub[9]; // subject that have pre-requisites // 1 is the array of prereq // 2 is not prerequist
				for (int x = 0; x < 9; x++) {
					if (dssub[prereq] != "NONE" && dssub[prereq] != "") { // check the first desired subject if it has pre-req
						cnf = 0;
						for (int j = 0; j <= y; j++) { // checking if its not existing
							if (dssub[prereq] == prereqsub[j] && j <= y) { // check if pre-req is already in prereqsub storage
								cnf = 0;
								break;
							}
							else
							{
								cnf = 1;
							}
						}
						if (cnf == 1) {
							prereqsub[y] = dssub[prereq]; // store to pre requisite subject if not existing
							y++;
							cnf = 0;
						}
						if (dssub[prereq + 1] != "NONE" && dssub[prereq + 1] != "") { // check the second desired sub if it has pre-req
							cnf = 0;
							for (int j = 0; j <= y; j++) { // checking if its not existing
								if (dssub[prereq + 1] == prereqsub[j] && j <= y) { // check again the second pre-req if its existing in prereqsub storage
									cnf = 0;
									break;
								}
								else
								{
									cnf = 1;
								}
							}
							if (cnf == 1) {
								prereqsub[y] = dssub[prereq + 1]; // store if its not existing
								y++;
								cnf = 0;
							}
						}
					}
					else {
						if (dssub[prereq] != "") {
							subnoprq[v] = dssub[prereq - 3];
							v++;
						}
					}
					prereq += 5;
				}

				// Displaying prerequisites

				cx = 5;
				cy = 8;
				n1 = 0;
				v = 0;


				for (int x = 0; x < y; x++) {
					cx = 5;
					ifstream ldfile;
					ldfile.open("allsub.txt");

					for (int a = 0; a < 9; a++) {
						string line;
						while (getline(ldfile, line)) {
							stringstream ss(line);
							string var[5];
							for (int s = 0; s < 5; s++) {
								getline(ss, var[s], '$');
							}
							if (prereqsub[x] == var[0]) {
								coorxy(cx, cy); cout << n1 + 1; // subject number
								cx += 5;
								//coorxy(cx, cy); cout << "Year " << stinfo[18] << " / Sem " << stinfo[19];
								coorxy(18, cy); cout << "Pre-req ";
								cx += 27;
								/*coorxy(cx, cy); cout << prereqsub[x];
								cx += 10;*/
								coorxy(cx, cy); cout << var[0]; // subject code
								cx += 15;
								coorxy(cx, cy); cout << var[1]; // subject descrip
								cy += 2;
								n1++;
								//z = 0;
								break;
							}
						}
						ldfile.close();
					}
				}


				// this is for determining how many cases/cin will be used in marking

				string* grd = new string[n1];
				cx = 108;
				cy = 8;
				for (int a = 0; a < n1; a++) {
					coorxy(cx, cy); getchVale(grd[a], 'n', 1);
					cy += 2;
				}

				// Removing failed subjects to prereq array

				v = 0;
				for (int a = 0; a < n1;) {
					if (grd[a] == "0") { // if the pre req index == 0 / failed
						index = -1; // just initialization of not existing index
						sz = 9; // declaring the size of the loop
						for (int s = 0; s < sz; s++) {
							if (prereqsub[s] == prereqsub[a]) { // loop will find the subject to be removed
								index = a; // now declaring the index of subject to be removed
								break;
							}
						}

						if (index != -1) { // if index is existing
							for (int a = index; a < sz - 1; a++) { // the loop will iterate througout the prereq array
								prereqsub[a] = prereqsub[a + 1]; // Now the index of subject(to be removed) will be replaced by the next index
							}
							--sz;
							for (int a = index; a < n1 - 1; a++) { // now the grade of next subject will be the first because the first one was removed
								grd[a] = grd[a + 1];
							}
							--n1; // decrementing the number of iterations when subject is removed
						}
					}
					else {
						psdsub[v] = prereqsub[a]; // getting all the passed subject
						v++;
						a++;
					}
				}

				// confirmation "Next"
				hdc(1);
				coorxy(92, 27); cout << "<< ";
				coorxy(111, 27); cout << " >>";
				do {
					cn1 = _getch();
				} while (cn1 != 13);
				//buttonxy2(92, 27, 14, 1, 1);
				coorxy(92, 27); cout << " >>";
				coorxy(111, 27); cout << "<< ";
				psdbtn(95, 26, 14, 1);
				Sleep(100);
				//hdc(0);
				cntr++;
				//// This is just for testing
				//for (int a = 0; a < size(psdsub); a++) {
				//	cout <<endl<< psdsub[a] << "     ";
				//}
				system("cls");
				goto R;

			}


			else { // getting the previous sub of last sem - youre here
				page2();

				// Getting the prereq subs - done

				prereq = 3;
				precode = 0;
				y = 0; // counter for how many subject have pre requisites
				v = 0;
				string prereqsub[9]; // subject that have pre-requisites // 1 is the array of prereq // 2 is not prerequist
				for (int x = 0; x < 9; x++) {
					if (dssub[prereq] != "NONE" && dssub[prereq] != "") {
						cnf = 0;
						for (int j = 0; j <= y; j++) { // checking if its not existing
							if (dssub[prereq] == prereqsub[j] && j <= y) {
								cnf = 0;
								break;
							}
							else
							{
								cnf = 1;
							}
						}
						if (cnf == 1) {
							prereqsub[y] = dssub[prereq];
							y++;
							cnf = 0;
						}
						if (dssub[prereq + 1] != "NONE" && dssub[prereq + 1] != "") {
							//for (int j = 0; j < 5; j++) { // checking if its not exististing
							cnf = 0;
							for (int j = 0; j <= y; j++) { // checking if its not existing
								if (dssub[prereq + 1] == prereqsub[j] && j <= y) {
									cnf = 0;
									break;
								}
								else
								{
									cnf = 1;
								}
							}
							if (cnf == 1) {
								prereqsub[y] = dssub[prereq + 1];
								y++;
								cnf = 0;
							}

						}
					}
					else {
						if (dssub[prereq] != "") {
							subnoprq[v] = dssub[prereq - 3];
							v++;
						}
					}
					prereq += 5;
				}

				// displaying prerequisits

				cx = 5;
				cy = 8;
				n1 = 0;
				v = 0;


				for (int x = 0; x < y; x++) {
					cx = 5;
					ifstream ldfile;
					ldfile.open("allsub.txt"); // getting the all subjects as basis

					for (int a = 0; a < 9; a++) {
						string line;
						while (getline(ldfile, line)) {
							stringstream ss(line);
							string var[5];
							for (int s = 0; s < 5; s++) {
								getline(ss, var[s], '$');
							}
							if (prereqsub[x] == var[0]) {
								coorxy(cx, cy); cout << n1 + 1; // subject number
								cx += 5;
								//coorxy(cx, cy); cout << "Year " << stinfo[18] << " / Sem " << stinfo[19];
								coorxy(18, cy); cout << "Pre-req ";
								cx += 27;
								/*coorxy(cx, cy); cout << prereqsub[x];
								cx += 10;*/
								coorxy(cx, cy); cout << var[0]; // subject code
								cx += 15;
								coorxy(cx, cy); cout << var[1]; // subject descrip
								cy += 2;
								n1++;
								break;
							}
						}
						ldfile.close();
					}
				}

				// getting the marks of prereq subjects

				string* grd = new string[n1];

				cx = 108;
				cy = 8;
				for (int a = 0; a < n1; a++) {
					coorxy(cx, cy); getchVale(grd[a], 'n', 1);
					cy += 2;
				}

				// Removing the failed subject to prereq


				v = 0;
				for (int a = 0; a < n1;) {
					if (grd[a] == "0") { // if the pre req index == 0 / failed
						index = -1; // just initialization of not existing index
						sz = 9; // declaring the size of the loop
						for (int s = 0; s < sz; s++) {
							if (prereqsub[s] == prereqsub[a]) { // loop will find the subject to be removed
								index = a; // now declaring the index of subject to be removed
								break;
							}
						}

						if (index != -1) { // if index is existing
							for (int a = index; a < sz - 1; a++) { // the loop will iterate througout the prereq array
								prereqsub[a] = prereqsub[a + 1]; // Now the index of subject(to be removed) will be replaced by the next index
							}
							--sz;
							for (int a = index; a < n1 - 1; a++) { // now the grade of next subject will be the first because the first one was removed
								grd[a] = grd[a + 1];
							}
							--n1; // decrementing the number of iterations when subject is removed
						}
					}
					else {
						psdsub[v] = prereqsub[a]; // getting all the passed subject
						v++;
						a++;
					}
				}

				// confirmation "Next"
				hdc(1);
				coorxy(92, 27); cout << "<< ";
				coorxy(111, 27); cout << " >>";
				do {
					cn1 = _getch();
				} while (cn1 != 13);
				coorxy(92, 27); cout << " >>";
				coorxy(111, 27); cout << "<< ";
				psdbtn(95, 26, 14, 1);
				//hdc(0);
				Sleep(100);
				cntr++;
				system("cls");
				goto R;
			}

			break; // break for case 1


		case 2: // youre here at final page // THIRD PAGE

			// you have mow the passed subjects, no pre requisites subjects and desired subjects - youre here at showing the desired subject if passed

			// make an if else for desired subjects that has only 1 pre req and desired subject that have 2 pre req



			page3();

			
			unt = 0; // total units

			if (stinfo[20] != "") {
				svdbl = stoi(stinfo[20]);
				coorxy(4, 27); cout << string(30, ' ');
				coorxy(5, 27); cout << "Pending Balance : ";
				coorxy(28, 27); cout << char(179) << " PAYMENT: " << char(158);
				coorxy(5, 24); cout << "- ENROLLED - "<<char(179)<< " POOL ID : " << stinfo[0] <<" " << char(179);
			}

			if (stinfo[18] == "1" && stinfo[19] == "1") {
				v = 0;
				cy = 6;
				cx = 37;
				for (int a = 0; a < 9; a++) {
					for (int s = 0; s < 1; s++) {
						if (dssub[v] == "") {
							break;
						}
						coorxy(5, cy); cout << a + 1;
						coorxy(10, cy); cout << "Year " << stinfo[18] << " / sem " << stinfo[19];
						coorxy(cx, cy); cout << dssub[v];
						cx += 15;
						v++;
						coorxy(cx, cy); cout << dssub[v];
						cx += 56;
						v++;
						coorxy(cx, cy); cout << dssub[v];
						unt += stoi(dssub[v]);
					}
					v += 3;
					cy += 2;
					cx = 37;
				}
			}
			else {

				// backuping passed subjects 
				
				/*ifstream loadfile;
				loadfile.open(finder + ".txt");
				if (loadfile.is_open()) {
					string line;
					for (int a = 0; a < 2; a++) {
						getline(loadfile, line);
						if (line.substr(0, 4) != "2024") {
							stringstream ss(line);
							for (int a = 0; a < 9; a++) {
								getline(ss, psdsub[a], '$');
							}
						}
					}
				}*/



				v = 3;
				v1 = 0;
				cy = 4;
				cx = 37;
				for (int a = 0; a < 9; a++) {
					if (dssub[v] != "NONE" && dssub[v] != "" && dssub[v + 1] != "NONE" && dssub[v + 1] != "") {
						cnf = 0;
						for (int a = 0; a < size(psdsub); a++) {
							if (psdsub[a] == "") {
								v1 += 5;
								break;
							}
							if (dssub[v] == psdsub[a]) {
								cnf = 1; // means pasado
								break;
							}
						}
						if (cnf == 1) { // checking the second pre req
							cnf = 0;

							for (int a = 0; a < size(psdsub); a++) {
								if (psdsub[a] == "") {
									v1 += 5;
									break;
								}
								if (dssub[v + 1] == psdsub[a]) {
									cnf = 1; // means pasado
									break;
								}
							}

							if (cnf == 1) {
								cnf = 0;
								// cout the passed sub for 2 pre req
								cx = 37;
								cy += 2;
								coorxy(5, cy); cout << a + 1;
								coorxy(10, cy); cout << "Year " << stinfo[18] << " / sem " << stinfo[19];
								coorxy(cx, cy); cout << dssub[v1];
								cx += 15;
								v1++;
								coorxy(cx, cy); cout << dssub[v1];
								cx += 56;
								v1++;
								coorxy(cx, cy); cout << dssub[v1];
								unt += stoi(dssub[v1]);
								v1 += 3;

							}
						}
					}
					else if (dssub[v] != "NONE" && dssub[v] != "") {
						for (int a = 0; a < size(psdsub); a++) {
							if (psdsub[a] == "") {
								v1 += 5;
								break;
							}
							if (dssub[v] == psdsub[a]) {
								cx = 37;
								cy += 2;
								cnf = 1; // means pasado
								coorxy(5, cy); cout << a + 1;
								coorxy(10, cy); cout << "Year " << stinfo[18] << " / sem " << stinfo[19];
								coorxy(cx, cy); cout << dssub[v1];
								cx += 15;
								v1++;
								coorxy(cx, cy); cout << dssub[v1];
								cx += 56;
								v1++;
								coorxy(cx, cy); cout << dssub[v1];
								unt += stoi(dssub[v1]);
								v1 += 3;
								break;
							}
						}
					}
					else if ((dssub[v] == "NONE" || dssub[v] == "") && dssub[v - 3] != "") {
						cy += 2;
						cx = 37;
						coorxy(5, cy); cout << a + 1;
						coorxy(10, cy); cout << "Year " << stinfo[18] << " / sem " << stinfo[19];
						coorxy(cx, cy); cout << dssub[v1];
						cx += 15;
						v1++;
						coorxy(cx, cy); cout << dssub[v1];
						cx += 56;
						v1++;
						coorxy(cx, cy); cout << dssub[v1];
						unt += stoi(dssub[v1]);
						v1 += 3;
					}
					//v1 += 5;
					v += 5;
				}
			}

			coorxy(108, 24); cout << unt;
			if (stinfo[20] != "") {
				ttlpmt = svdbl;
			}
			else {
				ttlpmt = (unt * 300);
			}
			if (stinfo[20] != "") {
				coorxy(23, 27); cout << ttlpmt;
			}
			else {
				coorxy(17, 27); cout << ttlpmt;
			}

			int ecntr = 0, pmt = 0, bal = 0, k = 0, e;
			char ltp;
			string fullname, pm;
		l:
			for(int i=0;;)
			{
				hdc(1);
				coorxy(77, 27); cout << "   ";
				coorxy(96, 27); cout << "   ";
				coorxy(97, 27); cout << "   ";
				coorxy(116, 27); cout << "   ";

				switch (ecntr)
				{
				case 0:
					if (ttlpmt == 0) {
						coorxy(4, 27); cout << string(40, ' ');
						coorxy(8, 27); cout << stinfo[0] << " is successfully enrolled";
						coorxy(4, 24); cout << string(40, ' ');
						//coorxy(55, 27); cout << "Pool ID : " << stinfo[0];
						pm = "0";
						ecntr++;
						goto l;
					}
					hdc(0);

					if (stinfo[20] != "") {
						coorxy(41, 27); e = getchVal(pm, 'n', 5);
						coorxy(41, 27); cout << "      ";
						coorxy(41, 27); cout << pm;
					}
					else {
						coorxy(38, 27); e = getchVal(pm, 'n', 5);
						coorxy(38, 27); cout << "      ";
						coorxy(38, 27); cout << pm;
					}
					if (pm == "") { ecntr = 2; goto l;  break; }
					else if (e == 101) ecntr = 2;
					else if (e == 111) ecntr++;
					goto l;
					break;
				case 1:
					coorxy(40, 29); cout << string(50, ' ');
					color(7);
					buttonxy(80, 26, 14, 1);
					coorxy(84, 27); cout << "CONFIRM";
					coorxy(77, 27); cout << "<<";
					coorxy(96, 27); cout << " >>";
					switch (_getch())
					{
					case 224:
						switch (_getch()) {
						case 75:
						case 72:
							ecntr--;
							break;
						case 77:
						case 80:
							ecntr++;
							break;
						}
						goto l;
						break;
					case 13:

						if (ttlpmt == 0) {
							system("cls");
							break;
						}
						

						coorxy(77, 27); cout << " >>";
						coorxy(96, 27); cout << "<< ";
						psdbtn(80, 26, 14, 1);
						Sleep(150);
						for (int a = 0; a < 1; a++)
						{
							pmt += stoi(pm);
						}
						if (pmt > ttlpmt)
						{
							coorxy(50, 27); color(4); cout << "too much input"; color(7);
							coorxy(50, 27); Sleep(1000); cout << string(20, ' ');
							if (stinfo[20] != "") {
								coorxy(41, 27); cout << "      ";
							}
							else {
								coorxy(38, 27); cout << "      ";
							}
							ecntr = 0;
							color(8); buttonxy(80, 26, 14, 1);coorxy(84, 27); cout << "CONFIRM";color(7);
							pmt = 0, pm = "";
							goto l;
							break;
						}
						else if ((pmt < round(ttlpmt / 2))&&stinfo[20] == "") { // first downpayment needs half
							coorxy(50, 27); color(4); cout << "Limit of half the price"; color(7);
							coorxy(50, 27); Sleep(1000); cout << string(30, ' ');
							if (stinfo[20] != "") {
								coorxy(41, 27); cout <<"     ";
							}
							else {
								coorxy(38, 27); cout << "      ";
							}
							ecntr = 0;
							color(8); buttonxy(80, 26, 14, 1); coorxy(84, 27); cout << "CONFIRM"; color(7);
							pmt = 0, pm = "";
							goto l;
							break;
						}
						else
						{
							bal = ttlpmt - pmt;
							
							// If enrolled and have balance

							if (stinfo[20] != "") {
								stinfo[20] = to_string(bal);



								ofstream svd;
								svd.open(finder + ".txt");
								if (svd.is_open()) {
									for (int a = 0; a < 21; a++) {
										svd << stinfo[a] + "$";
									}
									svd << endl;
									for (int a = 0; a < size(psdsub); a++) {
										svd << psdsub[a] + "$";
									}
									svd.close();
								}

								pm = " ", pmt = 0, bal = 0, svdbl = 0;
								system("cls");

								coorxy(4, 27); cout << string(13, ' ');
								coorxy(3, 27); cout << "Pending Balance : ";

								cntr = 2;
								goto R;
							}

							system("cls");
							sborder();
							lstp();

							// if balance is 0

							if (bal == 0) {
								for (int a = 16; a <= 17; a++) {
									coorxy(49, a); cout << string(30, ' ');
								}
							}
							else {
								coorxy(58, 17); cout << " " << bal << " php";
							}
							coorxy(57, 12); cout << stinfo[0];
							coorxy(52, 13); cout << stinfo[3] +" " + stinfo[1];

							coorxy(50, 22); cout << "<<";
							coorxy(70, 22); cout << ">>";
							do {
								ltp = _getch();
							} while (ltp != 13);
							coorxy(50, 22); cout << "  ";
							coorxy(70, 22); cout << "  ";
							coorxy(50, 22); cout << ">>";
							coorxy(70, 22); cout << "<<";
							psdbtn(53, 21, 14, 1);
							Sleep(100);

							// saving the balance and passed sub

							stinfo[20] = to_string(bal);

							ofstream svd;
							svd.open(finder + ".txt");
							if (svd.is_open()) {
								for (int a = 0; a < 21; a++) {
									svd << stinfo[a] + "$";
								}
								svd << endl;
								for (int a = 0; a < size(psdsub); a++) {
									svd << psdsub[a] + "$";
								}
								svd.close();
							}

							pm = " ", pmt = 0, bal = 0,svdbl = 0;
							system("cls");
							break;
						}
					}
					break;
				case 2:
					coorxy(97, 27); cout << "<<";
					coorxy(116, 27); cout << " >>";
					switch (_getch())
					{
					case 224:
						switch (_getch()) {
						case 75:
						case 72:
							if (pm == "") { ecntr = 0; goto l; break; }
							else ecntr--;
							break;
						case 77:
						case 80:
							if (pm == "") { ecntr = 0; goto l; break; }
							if (ecntr >= 2) { ecntr = 0; goto l; break; }
							else ecntr++;
							break;
						}
						goto l;
						break;
					case 13:
						coorxy(97, 27); cout << " >>";
						coorxy(116, 27); cout << "<< ";
						psdbtn(100, 26, 14, 1);
						Sleep(150);
						system("cls");
						break;
					}
					break;
				}
				return 0;
			}			
		}			
	}	
}



int main() {

	font1(600, 10, 20);

	system("color F");

	char user[] = "user1", upass[] = "upass1";
	char admin[] = "admin1", apass[] = "apass1";
	char username[32] = {}, password[32] = {};
	char a;
	//string username = "";


	int num = 1;
	int access = 0;

	coorxy(53, 19); cout << "Please Wait..";
	hdc(1);
	lborder();
	openscen();
	coorxy(55, 19); cout << string(16, ' ');

	coorxy(38, 19); cout << "- BSIT Student Enrollment Management System -";
	//coorxy(45, 22); system("pause"); ////////////// OPENING 
	coorxy(45, 22); cout << string(40, ' ');
	Sleep(500);
	coorxy(93, 26); cout << "      1A.G1  ";
	coorxy(93, 27); cout << "ver.2.0.2024.4.1";
	//login
	hdc(0);
	coorxy(40, 20); cout << string(6, char(196)); coorxy(71, 20); cout << string(6, char(196));
	coorxy(39, 20); cout << char(218); coorxy(77, 20); cout << char(191);
	for (int i = 0; i < 2; i++)
	{
		coorxy(39, 21 + i); cout << char(179);
		coorxy(77, 21 + i); cout << char(179);
		coorxy(39, 25 + i); cout << char(179);
		coorxy(77, 25 + i); cout << char(179);
	}
	coorxy(39, 27); cout << char(192); coorxy(77, 27); cout << char(217);
	coorxy(40, 27); cout << string(6, char(196)); coorxy(71, 27); cout << string(6, char(196));


	coorxy(42, 22); cout << "Username :";
	coorxy(53, 21); cout << char(218) << string(20, char(196)) << char(191);
	coorxy(53, 22); cout << char(179);
	coorxy(74, 22); cout << char(179);
	coorxy(53, 23); cout << char(192) << string(20, char(196)) << char(217);

	coorxy(42, 25); cout << "Password :";
	coorxy(53, 24); cout << char(218) << string(20, char(196)) << char(191);
	coorxy(53, 25); cout << char(179);
	coorxy(74, 25); cout << char(179);
	coorxy(53, 26); cout << char(192) << string(20, char(196)) << char(217);


Usr: // Login security system
	lborder();
	coorxy(55, 22);
	for (int i = 0;;) { // Login security for username
		a = _getch();
		if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9' || a == ' ') {
			if (i < 19) {
				cout << a;
				username[i] = a;
				++i;
			}
		}
		else if (a == 8 && i >= 1) {
			cout << "\b \b";
			username[--i] = '\0';
		}
		else if (a == 13 && i != 0) {
			username[i] = '\0';
			break;
		}
		else {
			a = _getch();
		}
	}
	coorxy(55, 25);
	for (int i = 0;;) { // login security for password
		a = _getch();
		if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9' || a == ' ') {
			if (i < 19) {
				cout << "*";
				password[i] = a;
				++i;
			}
		}
		else if (a == 8 && i >= 1) {
			cout << "\b \b";
			password[--i] = '\0';
		}
		else if (a == 13) {
			password[i] = '\0';
			if ((strcmp(username, user) == 0 && strcmp(password, upass) == 0) || strcmp(username, admin) == 0 && strcmp(password, apass) == 0) { // For logging in
				if (strcmp(username, admin) == 0 && strcmp(password, apass) == 0) {
					access = 1; // admin access
				}
				break;

			}
			else {
				i = 0;
				coorxy(43, 27); cout << "Incorrect Username or Password";
				coorxy(55, 22); cout << string(19, ' ');
				coorxy(55, 25); cout << string(19, ' ');
				goto Usr;
			}
		}
		else {
			switch (_getch()) {
			case 72:
				coorxy(55, 22); cout << string(19, ' ');
				coorxy(55, 25); cout << string(19, ' ');
				goto Usr;
				break;
			}
		}
	}



	//system("pause");
	system("cls");

	int cy = 0;
	int cntr = 0;
	int ext = 0;

mn:
	lborder();
	menudes(75, 10);
	cy = 0;
	for (int a = 0; a < 5; a++) {
		buttonxy(14, 2 + cy, 25, 3);
		cy += 5;
	}

	coorxy(56, 6); cout << "- BSIT Student Enrollment Management System -";

	coorxy(18, 4); cout << "Student Registration";
	coorxy(17, 9); cout << "Curriculum Management";
	coorxy(18, 14); cout << "Student Enrollment";
	coorxy(25, 19); cout << "Help";
	coorxy(25, 24); cout << "Exit";

	hdc(1);
	coorxy(60, 19); cout << "Use UP and DOWN arrow key to navigate";

Arrw:
	hdc(1);
	cy = 0;
	for (int a = 0; a < 5; a++) {
		coorxy(11, 4 + cy); cout << "   ";
		coorxy(41, 4 + cy); cout << "   ";
		cy += 5;
	}

	if (cntr == 0) {
		coorxy(11, 4); cout << ">> ";
		coorxy(41, 4); cout << " <<";
	}
	else if (cntr == 1) {
		coorxy(11, 9); cout << ">> ";
		coorxy(41, 9); cout << " <<";
	}
	else if (cntr == 2) {
		coorxy(11, 14); cout << ">> ";
		coorxy(41, 14); cout << " <<";
	}
	else if (cntr == 3) {
		coorxy(11, 19); cout << ">> ";
		coorxy(41, 19); cout << " <<";
	}
	else if (cntr == 4) {
		coorxy(11, 24); cout << ">> ";
		coorxy(41, 24); cout << " <<";
	}


	switch (_getch()) {
	case 224:
		switch (_getch()) {
		case 72:
			coorxy(60, 19); cout << string(40, ' ');
			coorxy(64, 19); cout << "Now use ENTER key to choose";
			if (cntr == 0) cntr = 4;
			else cntr--;
			break;
		case 80:
			coorxy(60, 19); cout << string(40, ' ');
			coorxy(64, 19); cout << "Now use ENTER key to choose";
			if (cntr == 4) cntr = 0;
			else cntr++;
			break;
		}
		goto Arrw;
		break;
	case 13:
		coorxy(64, 20); cout << string(40, ' ');
		cy = 0;
		for (int a = 0; a < 5; a++) {
			coorxy(11, 4 + cy); cout << "   ";
			coorxy(41, 4 + cy); cout << "   ";
			cy += 5;
		}

		if (cntr == 0) {//registration
			coorxy(12, 4); cout << ">> ";
			coorxy(40, 4); cout << " <<";
			psdbtn(14, 2, 25, 3);
			Sleep(150);
			system("cls");
			hdc(0);
			menu(1, access);
			system("cls");
		}
		else if (cntr == 1) {//curriculum
			coorxy(12, 9); cout << ">> ";
			coorxy(40, 9); cout << " <<";
			psdbtn(14, 7, 25, 3);
			Sleep(150);
			system("cls");
			hdc(0);
			menu(2, access);
			system("cls");
		}
		else if (cntr == 2) {//enrollment
			coorxy(12, 14); cout << ">> ";
			coorxy(40, 14); cout << " <<";
			psdbtn(14, 12, 25, 3);
			Sleep(150);
			system("cls");
			hdc(0);
			menu(3, access);
			system("cls");
		}
		else if (cntr == 3) {//help
			coorxy(12, 19); cout << ">> ";
			coorxy(40, 19); cout << " <<";
			psdbtn(14, 17, 25, 3);
			Sleep(150);
			system("cls");

			int hcntr = 0, hcntr2 = 0;

		p1:
			lborder();
			hp1();

			buttonxy(65, 25, 14, 1);
			gotoxy(71, 26); cout << "NEXT";
			buttonxy(90, 25, 14, 1);
			gotoxy(96, 26); cout << "BACK";

			coorxy(62, 26); cout << "  ";
			coorxy(82, 26); cout << "  ";
			coorxy(86, 26); cout << "  ";
			coorxy(107, 26); cout << "  ";

			if (hcntr == 0) {

				coorxy(62, 26); cout << "<<";
				coorxy(82, 26); cout << ">>";
			}
			else if (hcntr == 1) {
				coorxy(86, 26); cout << "<<";
				coorxy(107, 26); cout << ">>";
			}

			switch (_getch()) {
			case 224:
				switch (_getch()) {
				case 75:
					if (hcntr == 0) hcntr = 1;
					else hcntr--;
					break;
				case 77:
					if (hcntr == 1) hcntr = 0;
					else hcntr++;
					break;
				}
				goto p1;
				break;
			case 13:
				switch (hcntr)
				{
				case 0:
					coorxy(62, 26); cout << "  ";
					coorxy(82, 26); cout << "  ";

					coorxy(62, 26); cout << ">>";
					coorxy(82, 26); cout << "<<";
					psdbtn(65, 25, 14, 1);
					Sleep(100);
					system("cls");

				p2:
					lborder();
					hp2();

					buttonxy(65, 25, 14, 1);
					buttonxy(90, 25, 14, 1);

					gotoxy(69, 26); cout << "PREVIOUS";
					gotoxy(96, 26); cout << "BACK";

					coorxy(62, 26); cout << "  ";
					coorxy(82, 26); cout << "  ";

					coorxy(86, 26); cout << "  ";
					coorxy(107, 26); cout << "  ";

					if (hcntr2 == 0) {

						coorxy(62, 26); cout << "<<";
						coorxy(82, 26); cout << ">>";
					}
					else if (hcntr2 == 1) {
						coorxy(86, 26); cout << "<<";
						coorxy(107, 26); cout << ">>";
					}

					switch (_getch()) {
					case 224:
						switch (_getch()) {
						case 75:
							if (hcntr2 == 0) hcntr2 = 1;
							else hcntr2--;
							break;
						case 77:
							if (hcntr2 == 1) hcntr2 = 0;
							else hcntr2++;
							break;
						}
						goto p2;
						break;
					case 13:
						switch (hcntr2)
						{
						case 0:
							coorxy(62, 26); cout << "  ";
							coorxy(82, 26); cout << "  ";

							coorxy(62, 26); cout << ">>";
							coorxy(82, 26); cout << "<<";
							psdbtn(65, 25, 14, 1);
							Sleep(100);
							system("cls");
							goto p1;
							break;
							/*case 1:
								coorxy(86, 26); cout << "  ";
								coorxy(107, 26); cout << "  ";

								coorxy(88, 26); cout << ">>";
								coorxy(107, 26); cout << "<<";
								psdbtn(90, 25, 14, 1);
								Sleep(100);
								system("cls");
								goto mn;
								break;*/
						}
					}
				case 1:
					coorxy(86, 26); cout << "  ";
					coorxy(107, 26); cout << "  ";

					coorxy(88, 26); cout << ">>";
					coorxy(105, 26); cout << "<<";
					psdbtn(90, 25, 14, 1);
					Sleep(100);
					system("cls");
					goto mn;
					break;
				}
			}

			system("cls");
		}
		else if (cntr == 4) {//exit
			coorxy(12, 24); cout << ">> ";
			coorxy(40, 24); cout << " <<";
			psdbtn(14, 22, 25, 3);
			Sleep(150);
			system("cls");
			hdc(1);
			sborder();

			ext = 0;
			cntr = 1;
			for (int i = 0; i < 27;) {
				buttonxy(46 + i, 13, 12, 1);
				i += 17;
			}

			coorxy(37, 9); cout << string(50, char(196)); coorxy(36, 9); cout << char(218);
			for (int i = 0; i < 8; i++)
			{
				coorxy(36, 10 + i); cout << char(179);
				coorxy(87, 10 + i); cout << char(179);
			}
			coorxy(87, 9); cout << char(191);
			coorxy(36, 18); cout << char(192);
			coorxy(37, 18); cout << string(50, char(196)); coorxy(87, 18); cout << char(217);

			//buttonxy2(45, 11, 12, 1, 2);
			coorxy(56, 11); cout << "Are you sure?";
			coorxy(51, 14); cout << "Yes";
			coorxy(69, 14); cout << "No";

		ls:
			cy = 0;
			for (int a = 0; a < 2; a++) {
				coorxy(45, 12 + cy); cout << string(33, ' ');
				cy += 4;
			}


			if (cntr == 0) {
				buttonxy2(46, 13, 12, 1, 2);
			}
			else if (cntr == 1) {
				buttonxy2(63, 13, 12, 1, 2);
			}

			coorxy(39, 6); cout << "- BSIT Student Enrollment Management System -";
			switch (_getch()) {
			case 224:
				switch (_getch()) {
				case 75:
					if (cntr == 0) cntr = 1;
					else cntr--;
					break;
				case 77:
					if (cntr == 1) cntr = 0;
					else cntr++;
					break;
				}
				goto ls;
				break;
			case 13:
				if (cntr == 0) {
					psdbtn(46, 13, 12, 1);
					Sleep(150);
					system("cls");
					exit(0);
				}
				else if (cntr == 1) {
					psdbtn(63, 13, 12, 1);
					Sleep(150);
					system("cls");
					cntr = 4;
					goto mn;
				}
				break;
			default:
				goto ls;
				break;
			}
		}
		goto mn;
		break;
	default:
		goto Arrw;
		break;
	}



	coorxy(0, 29); system("pause");

}


//int main() {
//	menu(3,1);
//}

