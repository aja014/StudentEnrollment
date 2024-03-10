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
#include "curriTable.h" // Display table for Curriculum

//#include "Delay.h"
#define gc getchcout
//#include "enrollment.cpp"

using namespace std;

// ifstream to read
// ofstream to write

void multival(string& w, string& x, string& y, string& z, int a,int b, int c) { // w x y z is the storage, a b is the position of gotoxy, c if erasing (1 == erase)


	if (c == 1) { // this is to erase
		w = "";
		coorxy(a + 37, b); cout << string(13, ' ');
		coorxy(a + 37, b); cout << w;
		x = "";
		coorxy(a + 52, b); cout << string(37, ' ');
		coorxy(a + 52, b); cout << x;
		y = "";
		coorxy(a + 92, b); cout << string(8, ' ');
		coorxy(a + 92, b); cout << y;
		z = "";
		coorxy(a + 102, b); cout << string(14, ' ');
		coorxy(a + 102, b); cout << z;
	}
	else {

		int localcounter = 1;
		int sm;

		//getting the values inside the line

	Q:
		switch (localcounter) {
		case 1:
			coorxy(a + 37, b); sm = getchValc(w, 0);
			coorxy(a + 37, b); cout << string(13, ' ');
			coorxy(a + 37, b); cout << w;
			if (sm == 111)localcounter++; // if getchvalc returned a value
			else if (sm == 100) goto Q; // if getchvalc returned empty/null
			goto Q;
			break;
		case 2:
			coorxy(a + 52, b); sm = getchValc(x, 0);
			coorxy(a + 52, b); cout << string(37, ' ');
			coorxy(a + 52, b); cout << x;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 3:
			coorxy(a + 92, b); sm = getchValc(y, 0);
			coorxy(a + 92, b); cout << string(8, ' ');
			coorxy(a + 92, b); cout << y;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 4:
			coorxy(a + 102, b); sm = getchValc(z, 0);
			coorxy(a + 102, b); cout << string(14, ' ');
			coorxy(a + 102, b); cout << z;
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


int menu(int x) {
	system("cls");
	char a;

	if (x == 1) {
		string currentfile;

		string pooln, fname, mname, lname, age, gender, lrn, bmonth, bday, byear, barangay, municipality, province, gfname, gmname, glname, gcnum,
			grelation, targety;// Local varible storage for information

		string finder; // Local variable
		string temppoolnum; // local variable
		string searchpool[32]; // local variable
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


		table();





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
							while (getline(loadfile, line)) {
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
								getline(ss, targety, '$');
							}

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
							coorxy(10, 0); cout << "         ";
							coorxy(10, 0); cout << "found";
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
								glname = "", gcnum = "", grelation = "", targety = "";


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
							coorxy(10, 0); cout << "not found";
						}


						coorxy(31, 2); cout << string(8, ' ');

						j = 0; // resetting the searchfinder
						temppoolnum = finder; // backuping the pooling num
						finder = ""; // resetting poolinf finder
						counter = 0;
						goto Q;
					}
				}


				break;
			case 1:
				coorxy(19, 6); n = getchVal(fname, 0);
				coorxy(19, 6); cout << string(20, ' ');
				coorxy(19, 6); cout << fname;//getchcout(fname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 2:
				coorxy(57, 6); n = getchVal(mname, 0);
				coorxy(57, 6); cout << string(20, ' ');
				coorxy(57, 6); cout << mname; //getchcout(mname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 3:
				coorxy(93, 6); n = getchVal(lname, 0);
				coorxy(93, 6); cout << string(20, ' ');
				coorxy(93, 6); cout << lname; //getchcout(lname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 4:
				coorxy(18, 8); n = getchVal(age, 2);
				coorxy(18, 8); cout << string(20, ' ');
				coorxy(18, 8); cout << age; //getchcout(age);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 5:
				coorxy(18, 10); n = getchVal(gender, 0);
				coorxy(18, 10); cout << string(20, ' ');
				coorxy(18, 10); cout << gender; //getchcout(gender);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 6:
				coorxy(56, 10); n = getchVal(lrn, 12);
				coorxy(56, 10); cout << string(20, ' ');
				coorxy(56, 10); cout << lrn; //getchcout(lrn);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 7:
				coorxy(26, 12); n = getchVal(bmonth, 0);
				coorxy(26, 12); cout << string(20, ' ');
				coorxy(26, 12); cout << bmonth; //getchcout(bmonth);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 8:
				coorxy(56, 12); n = getchVal(bday, 2);
				coorxy(56, 12); cout << string(20, ' ');
				coorxy(56, 12); cout << bday; //getchcout(bday);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 9:
				coorxy(93, 12); n = getchVal(byear, 4);
				coorxy(93, 12); cout << string(20, ' ');
				coorxy(93, 12); cout << byear; //getchcout(byear);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 10:
				coorxy(29, 14); n = getchVal(barangay, 0);
				coorxy(29, 14); cout << string(30, ' ');
				coorxy(29, 14); cout << barangay; //getchcout(barangay);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 11:
				coorxy(33, 16); n = getchVal(municipality, 0);
				coorxy(33, 16); cout << string(30, ' ');
				coorxy(33, 16); cout << municipality; //getchcout(municipality);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 12:
				coorxy(29, 18); n = getchVal(province, 0);
				coorxy(29, 18); cout << string(30, ' ');
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
				coorxy(31, 20); n = getchVal(gfname, 0);
				coorxy(31, 20); cout << string(17, ' ');
				coorxy(31, 20); cout << gfname;// getchcout(gfname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 14:
				coorxy(65, 20); n = getchVal(gmname, 0);
				coorxy(65, 20); cout << string(15, ' ');
				coorxy(65, 20); cout << gmname; //getchcout(gmname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 15:
				coorxy(97, 20); n = getchVal(glname, 0);
				coorxy(97, 20); cout << string(17, ' ');
				coorxy(97, 20); cout << glname; //getchcout(glname);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 16:
				coorxy(35, 22); n = getchVal(gcnum, 11);
				coorxy(35, 22); cout << string(17, ' ');
				coorxy(35, 22); cout << gcnum; //getchcout(gcnum);
				if (n == 101) counter--;
				else counter++;
				goto Q;
				break;
			case 17:
				coorxy(29, 24); n = getchVal(grelation, 0);
				coorxy(29, 24); cout << string(30, ' ');
				coorxy(29, 24); cout << grelation; //getchcout(grelation);
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

					// information must not be empty inorder to add or save

					if (fname != "" && mname != "" && lname != "" && age != "" && gender != "" && lrn != "" && bmonth != "" && bday != "" && byear != "" && barangay != "" && municipality != "" && province != "" && gfname != "" && gmname != "" && glname != "" && grelation != "" && gcnum!= "") {


					//checking if pooling number is already registerd - done

						if (targety == "") {
							system("cls");
							do {
								coorxy(45, 11); cout << "What year do you want to enroll? :    ";
								coorxy(80, 11); getchVal(e, 0);
							} while (e != "1" && e != "2" && e != "3" && e != "4");
							targety = e;
							do {
								e = "";
								coorxy(45, 12); cout << "Enter what semester :    ";
								coorxy(67, 12); getchVal(e, 0);
								//e += f;

							} while (e != "1" && e != "2");
							targety += e;
							e = "";
							coorxy(45, 14); cout << "target year/sem code" << targety;

							// Pooling number table
							coorxy(43, 16); cout << char(179) << " Pooling num : " << temppoolnum;  // number
							n = 0;
							coorxy(68, 16); cout << char(179);
							for (int j = 0; j < 2; j++) {
								coorxy(43, 15 + n); cout << string(26, char(196));
								n += 2;
							}
							coorxy(43, 18); system("pause");
						}


						// saving the file - done

						ofstream savefile;
						savefile.open(currentfile);
						savefile << pooln + "$" + fname + "$" + mname + "$" + lname + "$" + age + "$" + gender + "$" + lrn + "$" + bmonth + "$" + bday + "$" + byear + "$" + barangay + "$" + municipality + "$" + province + "$" + gfname + "$" + gmname + "$" + glname + "$" + gcnum + "$" + grelation + "$" + targety + "$" << endl;
						savefile.close();
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


					coorxy(43, 27); cout << "  ";
					coorxy(61, 27); cout << "  ";

					//Erasing Values - done

					pooln = "", fname = "", mname = "", lname = "", age = "", gender = "",
						lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
						municipality = "", province = "", gfname = "", gmname = "",
						glname = "", gcnum = "", grelation = "", targety = "";

					system("cls");
					table();
				}
				break;

			case 19:

				// youre here

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
					i;
					coorxy(67, 27); cout << "  ";
					coorxy(87, 27); cout << "  ";
					coorxy(68, 27); cout << "<<";
					coorxy(86, 27); cout << ">>";
					Sleep(100);


					// Youre here at deleting the file

					remove(currentfile.c_str());



					// Erasing Values - done

					pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "",
						lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
						municipality = "", province = "", gfname = "", gmname = "",
						glname = "", gcnum = "", grelation = "", targety = "";


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
					else if (c == 80 || c == 77) counter = 0;
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
	}

	else if (x == 2) {

		string var[45]; // variables
		string year; // variable for searching year
		string sem; // variable for searching sem
		string temp; // temporary storage for searching file


		int counter = 0; // counter for option
		int ext = 0; // exit confirmation
		int cntr = 0; // counter for database
		int dltd = 0; // variable for empty subject
		int st; // storage for returning value

		//variables for display
		int cx = 37; // x position
		int cy = 8; // y position

		//variables for display - for year and sem
		int dn = 0;
		int r = 0;
		int lvar = 0;
		int num = 1;
		
		tablec();





		// doing the switching rows - done

		do {

		W:

			switch (counter) {

			case 0:
				coorxy(20, 2); st = getchValc(year, 0);
				coorxy(20, 2); cout << string(15, ' ');
				coorxy(20, 2); cout << year;
				if (st == 111) counter++;
				else if (st == 100) goto W;
				goto W;
				break;

			case 1:
				coorxy(64, 2); st = getchValc(sem, 0);
				coorxy(64, 2); cout << string(15, ' ');
				coorxy(64, 2); cout << sem;
				coorxy(64, 2);
				if (st == 101) counter--;
				else if (st == 111) {
					counter++;

					// Erasing variables first

					for (int z = 0; z < 36; z++) {
						var[z] = "";
					}

					// Clearing display

					cx = 5;
					cy = 8;

					for (int z = 0; z < 9; z++) {
						coorxy(cx, cy);
						for (int x = 0; x < 1; x++) {
							coorxy(cx, cy); cout << string(4, ' ');
							cx += 7;
							coorxy(cx, cy); cout << string(21, ' ');
							cx += 25;
							coorxy(cx, cy); cout << string(13, ' ');
							cx += 15;
							coorxy(cx, cy); cout << string(38, ' ');
							cx += 40;
							coorxy(cx, cy); cout << string(8, ' ');
							cx += 10;
							coorxy(cx, cy); cout << string(14, ' ');
						}
						cy += 2;
						cx = 5;
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

								for (int x = 0; x < 4; x++) {
									getline(ss, var[cntr], '$');
									cntr++;
								}
							}
						}
						openf.close();

						// displaying the variables

						cx = 37;
						cy = 8;
						lvar = 0;
						r = 0;
						dn = 0;
						num = 1;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								if (var[r] != "") {// skip if subject code is empty
									coorxy(cx, cy); cout << var[lvar];
									cx += 15;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									cx += 40;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									cx += 10;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									lvar++;
									coorxy(13, 8 + dn); cout << "year " << year << " / " << "sem " << sem;
									coorxy(5, 8 + dn); cout << num;
									num++;
									dn += 2;
									cy += 2;
								}
								else {
									lvar += 4;
								}
							}
							r += 4;
							cx = 37;
						}
					}
					else { // if not existing

						// resetting year and sem

						year = "";
						sem = "";

						coorxy(20, 2); cout << string(20, ' '); // erasing searchbar for year
						coorxy(64, 2); cout << string(20, ' '); // erasing searchbar for sem

						// Erasing variables first

						for (int z = 0; z < 36; z++) {
							var[z] = "";
						}

						// Clearing display

						cx = 5;
						cy = 8;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								coorxy(cx, cy); cout << string(4, ' ');
								cx += 7;
								coorxy(cx, cy); cout << string(21, ' ');
								cx += 25;
								coorxy(cx, cy); cout << string(13, ' ');
								cx += 15;
								coorxy(cx, cy); cout << string(38, ' ');
								cx += 40;
								coorxy(cx, cy); cout << string(8, ' ');
								cx += 10;
								coorxy(cx, cy); cout << string(14, ' ');
							}
							cy += 2;
							cx = 5;
						}

						counter = 13;
					}
				}

				goto W;
				break;
			case 2:
				coorxy(0, 8);
				switch (_getch()) {
				case 72:
					counter = 0;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[0], var[1], var[2], var[3], 0, 8, 0);
					break;
				case 8:
					multival(var[0], var[1], var[2], var[3], 0, 8, 1);
					break;
				}
				goto W;
				break;
			case 3:
				coorxy(0, 10);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[4], var[5], var[6], var[7], 0, 10, 0);
					break;
				case 8:
					multival(var[4], var[5], var[6], var[7], 0, 10, 1);
					break;
				}
				goto W;
				break;
			case 4:
				coorxy(0, 12);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[8], var[9], var[10], var[11], 0, 12, 0);
					break;
				case 8:
					multival(var[8], var[9], var[10], var[11], 0, 12, 1);
					break;
				}
				goto W;
				break;
			case 5:
				coorxy(0, 14);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[12], var[13], var[14], var[15], 0, 14, 0);
					break;
				case 8:
					multival(var[12], var[13], var[14], var[15], 0, 14, 1);
					break;
				}
				goto W;
				break;
			case 6:
				coorxy(0, 16);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[16], var[17], var[18], var[19], 0, 16, 0);
					break;
				case 8:
					multival(var[16], var[17], var[18], var[19], 0, 16, 1);
					break;
				}
				goto W;
				break;
			case 7:
				coorxy(0, 18);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[20], var[21], var[22], var[23], 0, 18, 0);
					break;
				case 8:
					multival(var[20], var[21], var[22], var[23], 0, 18, 1);
					break;
				}
				goto W;
				break;
			case 8:
				coorxy(0, 20);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[24], var[25], var[26], var[27], 0, 20, 0);
					break;
				case 8:
					multival(var[24], var[25], var[26], var[27], 0, 20, 1);
					break;
				}
				goto W;
				break;
			case 9:
				coorxy(0, 22);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[28], var[29], var[30], var[31], 0, 22, 0);
					break;
				case 8:
					multival(var[28], var[29], var[30], var[31], 0, 22, 1);
					break;
				}
				goto W;
				break;
			case 10:
				coorxy(0, 24);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[32], var[33], var[34], var[35], 0, 24, 0);
					break;
				case 8:
					multival(var[32], var[33], var[34], var[35], 0, 24, 1);
					break;
				}
				goto W;
				break;
			case 11:
				coorxy(57, 27); cout << "<<";
				coorxy(77, 27); cout << ">>";

				switch (_getch()) {

				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					coorxy(57, 27); cout << " <<";
					coorxy(76, 27); cout << ">> ";
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
								for (int x = 0; x < 4; x++) {
									savefile << var[cntr] + "$";
									cntr++;
								}
								savefile << endl;
							}
							else { // if subject is empty
								cntr += 4; // this is to skip the iteration of variables
								dltd++; // this is the counter of how many subject is emtpy
							}
							r += 4;
						}
						for (int z = 0; z < dltd; z++) { // this is to add empty lines in the end depending on how many subject is empty
							savefile << "$$$$" << endl;
						}
						savefile.close();
					}
					system("cls");
					tablec();

					break;
				}

				coorxy(57, 27); cout << "   ";
				coorxy(76, 27); cout << "   ";
				goto W;
				break;
			case 12:
				coorxy(77, 27); cout << "<<";
				coorxy(97, 27); cout << ">>";
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					coorxy(77, 27); cout << " <<";
					coorxy(96, 27); cout << ">> ";
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
							for (int x = 0; x < 4; x++) {
								savefile << var[cntr] + "$";
								cntr++;
							}
							savefile << endl;
						}
						savefile.close();
					}
					system("cls");
					tablec();


					remove(temp.c_str());
					break;
				}
				coorxy(77, 27); cout << "   ";
				coorxy(96, 27); cout << "   ";
				goto W;
				break;
			case 13:
				coorxy(97, 27); cout << "<<";
				coorxy(117, 27); cout << ">>";
				switch (_getch()) {
				case 72:
				case 75:
					if (year == "" && sem == "") {
						counter = 0;
					}
					else {
						counter--;
					}
					coorxy(97, 27); cout << "  ";
					coorxy(117, 27); cout << "  ";
					goto W;
					break;
				case 80:
				case 77:
					counter = 0;
					coorxy(97, 27); cout << "  ";
					coorxy(117, 27); cout << "  ";
					goto W;
					break;
				case 13:
					coorxy(97, 27); cout << " <<";
					coorxy(116, 27); cout << ">> ";
					Sleep(100);
					ext = 1;
					break;
				}
				coorxy(97, 27); cout << "   ";
				coorxy(116, 27); cout << "   ";
				break;
			}
		} while (ext != 1);
		system("cls");


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
//			}
//		}
//		else if (a == 8 && i >= 1) {
//			cout << "\b \b";
//			username[--i] = '\0';
//		}
//		else if (a == 13) {
//			username[i] = '\0';
//			break;
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


//void savefile() {
//	ofstream myfile("C:\\Users\\Asus\\Documents\\GitHub\\StudentEnrollment\\StudentEnrollment\\Students.txt");
//	if (myfile.is_open()) {
//		//myfile << i + "$" << endl;
//		for (int j = 0; j < 10; j++) {
//			if (students[j][0] != "") {
//			myfile << students[j][0] + "$" + students[j][1] + "$" + students[j][2] + "$" + students[j][3] + "$" + students[j][4] + "$" + students[j][5] + "$" + students[j][6] + "$" + students[j][7] + "$" + students[j][8] + "$" + students[j][9] + "$" + students[j][10] + "$" + students[j][11] + "$" + students[j][12] + "$" + students[j][13] + "$" + students[j][14] + "$" + students[j][15] + "$" + students[j][16] + "$" + students[j][17] + "$" << endl;
//			}
//			/*else {
//				break;
//			}*/
//			//myfile << students[j][0] + "$" + students[j][1] + "$" + students[j][2] + "$" + students[j][3] + "$" + students[j][4] + "$" + students[j][5] + "$" + students[j][6] + "$" + students[j][7] + "$" + students[j][8] + "$" + students[j][9] + "$" + students[j][10] + "$" + students[j][11] + "$" + students[j][12] + "$" + students[j][13] + "$" + students[j][14] + "$" + students[j][15] + "$" + students[j][16] + "$" + students[j][17] + "$" << endl;
//
//		}
//	}
//	myfile.close();
//}

//void loadfile() {
//	ifstream myfile("C:\\Users\\Asus\\Documents\\GitHub\\StudentEnrollment\\StudentEnrollment\\Students.txt");
//	string line;
//	int c = 0,j=0;
//
//	if (myfile.is_open()) {
//		while (getline(myfile, line)) {
//			stringstream ss(line);
//			//var = line.substr(0);
//			//getline(ss, var, '$');
//			for (j = 0; j < 19; j++) {
//					getline(ss, students[c][j], '$');
//						poolnum1 = students[c][j];
//					}
//				}
//			c++; // youre here finding the empty pooling num if empty and skip if they have
//
//
//				if (j == 0 && (students[c][j] != "")) {
//			/*for (int j = 0; j < 10; j++) {
//				for (int k = 0; k < 19; k++) {
//
//				}
//			}*/
//
//		}
//	}
//
//	myfile.close();
//
//}
	
//int main() {  // Registration
//
//	string currentfile;
//	string finder; // Local variable
//	string temppoolnum; // local variable
//	string searchpool[32]; // local variable
//	string e; //local variable for targety
//	
//		table();
//		
//
//		string pooln,fname, mname, lname, age, gender, lrn, bmonth, bday, byear, barangay, municipality, province, gfname, gmname, glname, gcnum,
//			grelation,targety;
//
//		char d; // local variable
//
//		int counter = 0, n; // local variable
//		int i = 0; // student counter // local variable
//
//		int exit=0; // local variable
//		for (i = 0;;) {
//			Q:
//
//			switch (counter) {
//			case 0:
//
//				
//				coorxy(31, 2);
//				for (int j = 0;;) {
//					d = _getch();
//					if (d == -32) {
//						d = _getch();
//						if (d == 72 || d == 75) {
//							counter = 20;
//							break;
//						}
//						else if (d == 80 || d == 77) {
//							counter++;
//							break;
//						}
//					}
//					else if (d == 8 && j >= 1) {
//						cout << "\b \b";
//						searchpool[--j] = '\0';
//					}
//					else if ((d >= '0' && d <= '9') && j < 8) {
//						cout << d;
//						searchpool[j] = d;
//						++j;
//					}
//					else if (d == 13) {
//						//counter++;
//						searchpool[j] = '\0';
//
//						for (int k = 0; k < 8; k++) { // converting string array searchpoolnum[32] to single value finder
//							finder += searchpool[k];
//
//						}
//
//						// Erasing display
//
//						coorxy(19, 6); cout << string(15, ' ');
//						coorxy(57, 6); cout << string(15, ' ');
//						coorxy(93, 6); cout << string(15, ' ');
//						coorxy(18, 8); cout << string(15, ' ');
//						coorxy(18, 10); cout << string(15, ' ');
//						coorxy(56, 10); cout << string(15, ' ');
//						coorxy(26, 12); cout << string(15, ' ');
//						coorxy(56, 12); cout << string(15, ' ');
//						coorxy(93, 12); cout << string(15, ' ');
//						coorxy(29, 14); cout << string(15, ' ');
//						coorxy(33, 16); cout << string(15, ' ');
//						coorxy(29, 18); cout << string(15, ' ');
//						coorxy(31, 20); cout << string(15, ' ');
//						coorxy(65, 20); cout << string(15, ' ');
//						coorxy(97, 20); cout << string(15, ' ');
//						coorxy(35, 22); cout << string(15, ' ');
//						coorxy(29, 24); cout << string(15, ' ');
//
//						// youre here at finding  - done
//
//						string findtxt = finder + ".txt";
//						ifstream loadfile(findtxt);
//						if (loadfile.is_open()) { // if found, store the data
//							currentfile = findtxt; 
//							string line;
//							while (getline(loadfile, line)) {
//								stringstream ss(line);
//								getline(ss, pooln, '$');
//								getline(ss, fname, '$');
//								getline(ss, mname, '$');
//								getline(ss, lname, '$');
//								getline(ss, age, '$');
//								getline(ss, gender, '$');
//								getline(ss, lrn, '$');
//								getline(ss, bmonth, '$');
//								getline(ss, bday, '$');
//								getline(ss, byear, '$');
//								getline(ss, barangay, '$');
//								getline(ss, municipality, '$');
//								getline(ss, province, '$');
//								getline(ss, gfname, '$');
//								getline(ss, gmname, '$');
//								getline(ss, glname, '$');
//								getline(ss, gcnum, '$');
//								getline(ss, grelation, '$');
//								getline(ss, targety, '$');
//							}
//
//							// displaying found datas - done
//
//							coorxy(19, 6); cout << fname; 
//							coorxy(57, 6); cout << mname;
//							coorxy(93, 6); cout << lname;
//							coorxy(18, 8); cout << age;
//							coorxy(18, 10); cout << gender;
//							coorxy(56, 10); cout << lrn;
//							coorxy(26, 12); cout << bmonth;
//							coorxy(56, 12); cout << bday;
//							coorxy(93, 12); cout << byear;
//							coorxy(29, 14); cout << barangay;
//							coorxy(33, 16); cout << municipality;
//							coorxy(29, 18); cout << province;
//							coorxy(31, 20); cout << gfname;
//							coorxy(65, 20); cout << gmname;
//							coorxy(97, 20); cout << glname;
//							coorxy(35, 22); cout << gcnum;
//							coorxy(29, 24); cout << grelation;
//
//
//							loadfile.close();
//							coorxy(10, 0); cout << "         ";
//							coorxy(10, 0); cout << "found";
//						}
//						else { // if not found;
//
//
//							// erasing display - done
//
//							coorxy(19, 6); cout << string(15, ' ');
//							coorxy(57, 6); cout << string(15, ' ');
//							coorxy(93, 6); cout << string(15, ' ');
//							coorxy(18, 8); cout << string(15, ' ');
//							coorxy(18, 10); cout << string(15, ' ');
//							coorxy(56, 10); cout << string(15, ' ');
//							coorxy(26, 12); cout << string(15, ' ');
//							coorxy(56, 12); cout << string(15, ' ');
//							coorxy(93, 12); cout << string(15, ' ');
//							coorxy(29, 14); cout << string(15, ' ');
//							coorxy(33, 16); cout << string(15, ' ');
//							coorxy(29, 18); cout << string(15, ' ');
//							coorxy(31, 20); cout << string(15, ' ');
//							coorxy(65, 20); cout << string(15, ' ');
//							coorxy(97, 20); cout << string(15, ' ');
//							coorxy(35, 22); cout << string(15, ' ');
//							coorxy(29, 24); cout << string(15, ' ');
//
//
//							pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "", // resetting variable values
//							lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
//							municipality = "", province = "", gfname = "", gmname = "",
//							glname = "", gcnum = "", grelation = "", targety = "";
//
//
//							// finding new empty pooling number - done
//
//							int temppool = 20240001; // temporary pooling number
//							int ext = 0; // confirmation exit
//							do {
//								string tempfinder = to_string(temppool) + ".txt";
//								ifstream newfile; // making new file and check if it exist
//								newfile.open(tempfinder);
//								if (newfile.is_open()) {
//									temppool++;
//									newfile.close();
//								}
//								else {
//									finder = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//									currentfile = finder + ".txt";
//									ext = 1;
//									break;
//								}
//							} while (ext != 1);
//							coorxy(10, 0); cout << "not found";
//						}
//						
//
//						coorxy(31, 2); cout << string(8, ' ');
//
//						j = 0; // resetting the searchfinder
//						temppoolnum = finder; // backuping the pooling num
//						finder = ""; // resetting poolinf finder
//						counter = 0;
//						goto Q;
//					}
//				}
//
//
//				break;
//			case 1:
//				coorxy(19, 6); n = getchVal(fname, 0);
//				coorxy(19, 6); cout << string(20, ' ');
//				coorxy(19, 6); cout << fname;//getchcout(fname);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 2:
//				coorxy(57, 6); n = getchVal(mname, 0);
//				coorxy(57, 6); cout << string(20, ' ');
//				coorxy(57, 6); cout << mname; //getchcout(mname);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 3:
//				coorxy(93, 6); n = getchVal(lname, 0);
//				coorxy(93, 6); cout << string(20, ' ');
//				coorxy(93, 6); cout << lname; //getchcout(lname);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 4:
//				coorxy(18, 8); n = getchVal(age, 2);
//				coorxy(18, 8); cout << string(20, ' ');
//				coorxy(18, 8); cout << age; //getchcout(age);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 5:
//				coorxy(18, 10); n = getchVal(gender, 0);
//				coorxy(18, 10); cout << string(20, ' ');
//				coorxy(18, 10); cout << gender; //getchcout(gender);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 6:
//				coorxy(56, 10); n = getchVal(lrn, 12);
//				coorxy(56, 10); cout << string(20, ' ');
//				coorxy(56, 10); cout << lrn; //getchcout(lrn);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 7:
//				coorxy(26, 12); n = getchVal(bmonth, 0);
//				coorxy(26, 12); cout << string(20, ' ');
//				coorxy(26, 12); cout << bmonth; //getchcout(bmonth);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 8:
//				coorxy(56, 12); n = getchVal(bday, 2);
//				coorxy(56, 12); cout << string(20, ' ');
//				coorxy(56, 12); cout << bday; //getchcout(bday);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 9:
//				coorxy(93, 12); n = getchVal(byear, 4);
//				coorxy(93, 12); cout << string(20, ' ');
//				coorxy(93, 12); cout << byear; //getchcout(byear);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 10:
//				coorxy(29, 14); n = getchVal(barangay, 0);
//				coorxy(29, 14); cout << string(30, ' ');
//				coorxy(29, 14); cout << barangay; //getchcout(barangay);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 11:
//				coorxy(33, 16); n = getchVal(municipality, 0);
//				coorxy(33, 16); cout << string(30, ' ');
//				coorxy(33, 16); cout << municipality; //getchcout(municipality);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 12:
//				coorxy(29, 18); n = getchVal(province, 0);
//				coorxy(29, 18); cout << string(30, ' ');
//				coorxy(29, 18); cout << province; //getchcout(province);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			/*case 13:
//				coorxy(38, 21); n = getchVal(postalzip, 4);
//				coorxy(38, 21); cout << string(20, ' ');
//				coorxy(38, 21); getchcout(postalzip);
//				if (n == 101) counter--;
//				else counter++;
//				goto Q;
//				break;*/
//			case 13:
//				coorxy(31, 20); n = getchVal(gfname, 0);
//				coorxy(31, 20); cout << string(17, ' ');
//				coorxy(31, 20); cout << gfname;// getchcout(gfname);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 14:
//				coorxy(65, 20); n = getchVal(gmname, 0);
//				coorxy(65, 20); cout << string(15, ' ');
//				coorxy(65, 20); cout << gmname; //getchcout(gmname);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 15:
//				coorxy(97, 20); n = getchVal(glname, 0);
//				coorxy(97, 20); cout << string(17, ' ');
//				coorxy(97, 20); cout << glname; //getchcout(glname);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 16:
//				coorxy(35, 22); n = getchVal(gcnum, 11);
//				coorxy(35, 22); cout << string(17, ' ');
//				coorxy(35, 22); cout << gcnum; //getchcout(gcnum);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				goto Q;
//				break;
//			case 17:
//				coorxy(29, 24); n = getchVal(grelation, 0);
//				coorxy(29, 24); cout << string(30, ' ');
//				coorxy(29, 24); cout << grelation; //getchcout(grelation);
//				if (n == 101) counter--;
//				else if (n == 100) goto Q;
//				else counter++;
//				break;
//			case 18:
//				coorxy(42, 27); cout << "<<";
//				coorxy(62, 27); cout << ">>";
//				char a;
//				a = _getch();
//				if (a == -32) {
//					a = _getch();
//					coorxy(42, 27); cout << "  ";
//					coorxy(62, 27); cout << "  ";
//					if (a == 72 || a == 75) counter--;
//					else if (a == 80 || a == 77) counter++;
//				}
//				else if (a == 13) {
//
//					coorxy(42, 27); cout << "  ";
//					coorxy(62, 27); cout << "  ";
//					coorxy(43, 27); cout << "<<";
//					coorxy(61, 27); cout << ">>";
//					Sleep(100);
//
//					// checking if all information is not empty
//					
//					if (fname != "" && mname != "" && lname != "" && age != "" && gender != "" && lrn != "" && bmonth != "" && bday != "" && byear != "" && barangay != "" && municipality != "" && province != "" && gfname != "" && gmname != "" && glname != "" && grelation != "" && gcnum != "") {
//
//						// checking if studnet is already registered
//
//						if (targety == "") {
//							system("cls");
//							do {
//								coorxy(45, 11); cout << "What year do you want to enroll? :    ";
//								coorxy(80, 11); getchVal(e, 0);
//							} while (e != "1" && e != "2" && e != "3" && e != "4");
//							targety = e;
//							do {
//								e = "";
//								coorxy(45, 12); cout << "Enter what semester :    ";
//								coorxy(67, 12); getchVal(e, 0);
//								//e += f;
//
//							} while (e != "1" && e != "2");
//							targety += e;
//							e = "";
//							coorxy(45, 14); cout << "target year/sem code" << targety;
//
//							// Pooling number table
//							coorxy(43, 16); cout << char(179) << " Pooling num : " << temppoolnum;  // number
//							n = 0;
//							coorxy(68, 16); cout << char(179);
//							for (int j = 0; j < 2; j++) {
//								coorxy(43, 15 + n); cout << string(26, char(196));
//								n += 2;
//							}
//							coorxy(43, 18); system("pause");
//						}
//
//
//						// saving the file - done
//
//						ofstream savefile;
//						savefile.open(currentfile);
//						savefile << pooln + "$" + fname + "$" + mname + "$" + lname + "$" + age + "$" + gender + "$" + lrn + "$" + bmonth + "$" + bday + "$" + byear + "$" + barangay + "$" + municipality + "$" + province + "$" + gfname + "$" + gmname + "$" + glname + "$" + gcnum + "$" + grelation + "$" + targety + "$" << endl;
//						savefile.close();
//
//					//finding the empty file - done
//
//					int temppool = 20240001;
//					int ext = 0;
//					do {
//						string tempfinder = to_string(temppool) + ".txt";
//						ifstream newfile; // making new file and check if it exist
//						newfile.open(tempfinder);
//						if (newfile.is_open()) {
//							temppool++;
//							newfile.close();
//						}
//						else {
//							temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//							currentfile = temppoolnum + ".txt";
//							ext = 1;
//							break;
//						}
//					} while (ext != 1);
//
//
//					
//					//Erasing Values - done
//					
//					pooln = "",fname = "", mname = "", lname = "", age = "", gender = "",
//					lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
//					municipality = "", province = "", gfname = "", gmname = "",
//					glname = "", gcnum = "", grelation = "", targety = ""; 
//
//					system("cls"); 
//					table();
//					}
//					coorxy(43, 27); cout << "  ";
//					coorxy(61, 27); cout << "  ";
//				}
//			break;
//
//			case 19:
//
//				// youre here
//
//				coorxy(67, 27); cout << "<<";
//				coorxy(87, 27); cout << ">>";
//				char b;
//				b = _getch();
//				if (b == -32) {
//					b = _getch();
//					coorxy(67, 27); cout << "  ";
//					coorxy(87, 27); cout << "  ";
//					if (b == 72 || b == 75) counter--;
//					else if (b == 80 || b == 77) counter++;
//				}
//				else if (b == 13) {
//					i;
//					coorxy(67, 27); cout << "  ";
//					coorxy(87, 27); cout << "  ";
//					coorxy(68, 27); cout << "<<";
//					coorxy(86, 27); cout << ">>";
//					Sleep(100);
//					
//
//					// Youre here at deleting the file
//
//					remove(currentfile.c_str());
//					
//
//
//					// Erasing Values - done
//
//					pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "",
//					lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
//					municipality = "", province = "", gfname = "", gmname = "",
//					glname = "", gcnum = "", grelation = "", targety = ""; 
//
//					
//					n = 0;
//					coorxy(3, 27); cout << string(20, ' ') ;
//					coorxy(28, 27); cout << ' ';
//					for (int x = 0; x < 2; x++) {
//						coorxy(3, 26 + n); cout << string(26, ' ');
//						n += 2;
//					}
//
//
//					//finding the empty file - done
//
//					int temppool = 20240001;
//					int ext = 0;
//					do {
//						string tempfinder = to_string(temppool) + ".txt";
//						ifstream newfile; // making new file and check if it exist
//						newfile.open(tempfinder);
//						if (newfile.is_open()) {
//							temppool++;
//							newfile.close();
//						}
//						else {
//							temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//							currentfile = temppoolnum + ".txt";
//							ext = 1;
//							break;
//						}
//					} while (ext != 1);
//					
//
//					coorxy(68, 27); cout << "  ";
//					coorxy(86, 27); cout << "  ";
//					system("cls");
//					table();
//				}
//				break;
//
//			case 20:
//				coorxy(92, 27); cout << "<<";
//				coorxy(112, 27); cout << ">>";
//				char c;
//				c = _getch();
//				if (c == -32) {
//					c = _getch();
//					coorxy(92, 27); cout << "  ";
//					coorxy(112, 27); cout << "  ";
//					if (c == 72 || c == 75) counter--;
//					else if (c == 80 || c == 77) counter=0;
//				}
//				else if (c == 13) {
//					coorxy(92, 27); cout << "  ";
//					coorxy(112, 27); cout << "  ";
//					coorxy(93, 27); cout << "<<";
//					coorxy(111, 27); cout << ">>";
//					Sleep(100);
//					system("cls");
//					exit = 1;
//				}
//				break;
//			}
//			if (exit == 1) break;
//		}
//		system("cls");
//
//		//savefile();
//
//		
//}

int main() { // curriculum

	tablec();

	string var[45]; // variables
	string year; // variable for searching year
	string sem; // variable for searching sem
	string temp; // temporary storage for searching file


	int counter = 0; // counter for option
	int ext = 0; // exit confirmation
	int cntr = 0; // counter for database
	int dltd = 0; // variable for empty subject
	int st; // storage for returning value

	//variables for display
	int cx =37; // x position
	int cy = 8; // y position

	//variables for display - for year and sem
	int dn = 0;
	int r = 0;
	int lvar=0;
	int num = 1;




	// doing the switching rows - done

	do {

	Q:

		switch (counter) {

			case 0:
				coorxy(20, 2); st = getchValc(year,0);
				coorxy(20, 2); cout << string(15, ' ');
				coorxy(20, 2); cout << year;
				if (st == 111) counter++;
				else if (st == 100) goto Q;
				goto Q;
				break;

			case 1:
				coorxy(64, 2); st = getchValc(sem, 0);
				coorxy(64, 2); cout << string(15, ' ');
				coorxy(64, 2); cout << sem;
				coorxy(64, 2);
				if (st == 101) counter--;
				else if (st == 111) {
					counter++;

					// Erasing variables first

					for (int z = 0; z < 36; z++) {
						var[z] = "";
					}

					// Clearing display

					cx = 5;
					cy = 8;

					for (int z = 0; z < 9; z++) {
						coorxy(cx, cy);
						for (int x = 0; x < 1; x++) {
							coorxy(cx, cy); cout << string(4, ' ');
							cx += 7;
							coorxy(cx, cy); cout << string(21, ' ');
							cx += 25;
							coorxy(cx, cy); cout << string(13, ' ');
							cx += 15;
							coorxy(cx, cy); cout << string(38, ' ');
							cx += 40;
							coorxy(cx, cy); cout << string(8, ' ');
							cx += 10;
							coorxy(cx, cy); cout << string(14, ' ');
						}
						cy += 2;
						cx = 5;
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

								for (int x = 0; x < 4; x++) {
									getline(ss, var[cntr], '$');
									cntr++;
								}
							}
						}
						openf.close();

						// displaying the variables

						cx = 37;
						cy = 8;
						lvar = 0;
						r = 0;
						dn = 0;
						num = 1;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								if (var[r] != "") {// skip if subject code is empty
									coorxy(cx, cy); cout << var[lvar];
									cx += 15;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									cx += 40;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									cx += 10;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									lvar++;
									coorxy(13, 8 + dn); cout << "year " << year << " / " << "sem " << sem;
									coorxy(5, 8 + dn); cout << num;
									num++;
									dn += 2;
									cy += 2;
								}
								else {
									lvar += 4;
								}
							}
							r += 4;
							cx = 37;
						}
					}
					else { // if not existing

						// resetting year and sem

						year = "";
						sem = "";

						coorxy(20, 2); cout << string(20, ' '); // erasing searchbar for year
						coorxy(64, 2); cout << string(20, ' '); // erasing searchbar for sem

						// Erasing variables first

						for (int z = 0; z < 36; z++) {
							var[z] = "";
						}

						// Clearing display

						cx = 5;
						cy = 8;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								coorxy(cx, cy); cout << string(4, ' ');
								cx += 7;
								coorxy(cx, cy); cout << string(21, ' ');
								cx += 25;
								coorxy(cx, cy); cout << string(13, ' ');
								cx += 15;
								coorxy(cx, cy); cout << string(38, ' ');
								cx += 40;
								coorxy(cx, cy); cout << string(8, ' ');
								cx += 10;
								coorxy(cx, cy); cout << string(14, ' ');
							}
							cy += 2;
							cx = 5;
						}

						counter = 13;
					}
				}

				goto Q;
				break;
			case 2:
				coorxy(0, 8); 
				switch (_getch()) {
				case 72:
					counter=0;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[0], var[1], var[2], var[3], 0, 8,0);
					break;
				case 8:
					multival(var[0], var[1], var[2], var[3],0,8,1);
					break;
				}
				goto Q;
				break;
			case 3:
				coorxy(0, 10);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[4], var[5], var[6], var[7], 0, 10,0);
					break;
				case 8:
					multival(var[4], var[5], var[6], var[7], 0, 10, 1);
					break;
				}
				goto Q;
				break;
			case 4:
				coorxy(0, 12);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[8], var[9], var[10], var[11], 0, 12,0);
					break;
				case 8:
					multival(var[8], var[9], var[10], var[11], 0, 12, 1);
					break;
				}
				goto Q;
				break;
			case 5:
				coorxy(0, 14);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[12], var[13], var[14], var[15], 0, 14,0);
					break;
				case 8:
					multival(var[12], var[13], var[14], var[15], 0, 14, 1);
					break;
				}
				goto Q;
				break;
			case 6:
				coorxy(0, 16);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[16], var[17], var[18], var[19], 0, 16,0);
					break;
				case 8:
					multival(var[16], var[17], var[18], var[19], 0, 16, 1);
					break;
				}
				goto Q;
				break;
			case 7:
				coorxy(0, 18);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[20], var[21], var[22], var[23], 0, 18,0);
					break;
				case 8:
					multival(var[20], var[21], var[22], var[23], 0, 18, 1);
					break;
				}
				goto Q;
				break;
			case 8:
				coorxy(0, 20);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[24], var[25], var[26], var[27], 0, 20,0);
					break;
				case 8:
					multival(var[24], var[25], var[26], var[27], 0, 20, 1);
					break;
				}
				goto Q;
				break;
			case 9:
				coorxy(0, 22);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[28], var[29], var[30], var[31], 0, 22,0);
					break;
				case 8:
					multival(var[28], var[29], var[30], var[31], 0, 22, 1);
					break;
				}
				goto Q;
				break;
			case 10:
				coorxy(0, 24);
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					multival(var[32], var[33], var[34], var[35], 0, 24,0);
					break;
				case 8:
					multival(var[32], var[33], var[34], var[35], 0, 24, 1);
					break;
				}
				goto Q;
				break;
			case 11:
				coorxy(57, 27); cout << "<<";
				coorxy(77, 27); cout << ">>";

				switch (_getch()) {

				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					coorxy(57, 27); cout << " <<";
					coorxy(76, 27); cout << ">> ";
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
								for (int x = 0; x < 4; x++) {
									savefile << var[cntr] + "$";
									cntr++;
								}
								savefile << endl;
							}
							else { // if subject is empty
								cntr += 4; // this is to skip the iteration of variables
								dltd++; // this is the counter of how many subject is emtpy
							}
							r += 4;
						}
						for (int z = 0; z < dltd; z++) { // this is to add empty lines in the end depending on how many subject is empty
							savefile << "$$$$" << endl;
						}
						savefile.close();
					}
					system("cls");
					tablec();

					break;
				}

				coorxy(57, 27); cout << "   ";
				coorxy(76, 27); cout << "   ";
				goto Q;
				break;
			case 12:
				coorxy(77, 27); cout << "<<";
				coorxy(97, 27); cout << ">>";
				switch (_getch()) {
				case 72:
					counter--;
					break;
				case 80:
					counter++;
					break;
				case 13:
					coorxy(77, 27); cout << " <<";
					coorxy(96, 27); cout << ">> ";
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
							for (int x = 0; x < 4; x++) {
								savefile << var[cntr] + "$";
								cntr++;
							}
							savefile << endl;
						}
						savefile.close();
					}
					system("cls");
					tablec();


					remove(temp.c_str());
					break;
				}
				coorxy(77, 27); cout << "   ";
				coorxy(96, 27); cout << "   ";
				goto Q;
				break;
			case 13:
				coorxy(97, 27); cout << "<<";
				coorxy(117, 27); cout << ">>";
				switch (_getch()) {
				case 72:
				case 75:
					if (year == "" && sem == "") {
						counter = 0;
					}
					else {
						counter--;
					}
					coorxy(97, 27); cout << "  ";
					coorxy(117, 27); cout << "  ";
					goto Q;
					break;
				case 80:
				case 77:
					counter=0;
					coorxy(97, 27); cout << "  ";
					coorxy(117, 27); cout << "  ";
					goto Q;
					break;
				case 13:
					coorxy(97, 27); cout << " <<";
					coorxy(116, 27); cout << ">> ";
					Sleep(100);
					ext = 1;
					break;
				}
				coorxy(97, 27); cout << "   ";
				coorxy(116, 27); cout << "   ";
				break;
		}
	}while (ext != 1);
	system("cls");
}

//int main() {
//	char name[50];
//	cin.get(name, 50);
//	cout << name;
//}






