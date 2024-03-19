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
#include "entable.h" // Display for enrollment

//#include "Delay.h"
#define gc getchcout
//#include "enrollment.cpp"

using namespace std;

// ifstream to read
// ofstream to write

void multival(string& v, string& w, string& x, string& y, string& z, int a,int b, int c) { // w x y z is the storage, a b is the position of gotoxy, c if erasing (1 == erase)


	if (c == 1) { // this is to erase
		v = "";
		coorxy(a + 37, b); cout << string(13, ' ');
		coorxy(a + 37, b); cout << v;
		w = "";
		coorxy(a + 52, b); cout << string(37, ' ');
		coorxy(a + 52, b); cout << w;
		x = "";
		coorxy(a + 92, b); cout << string(8, ' ');
		coorxy(a + 92, b); cout << x;
		y = "";
		coorxy(a + 102, b); cout << string(7, ' ');
		coorxy(a + 102, b); cout << y;
		z = "";
		coorxy(a + 109, b); cout << string(7, ' ');
		coorxy(a + 109, b); cout << y;
	}
	else {

		int localcounter = 1;
		int sm;

		//getting the values inside the line

	Q:
		switch (localcounter) {
		case 1:
			coorxy(a + 37, b); sm = getchValc(v, 'l', 13); // subject code
			coorxy(a + 37, b); cout << string(13, ' ');
			coorxy(a + 37, b); cout << v;
			if (sm == 111)localcounter++; // if getchvalc returned a value
			else if (sm == 100) goto Q; // if getchvalc returned empty/null
			goto Q;
			break;
		case 2:
			coorxy(a + 52, b); sm = getchValc(w, 'l', 37); // subject description
			coorxy(a + 52, b); cout << string(37, ' ');
			coorxy(a + 52, b); cout << w;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 3:
			coorxy(a + 92, b); sm = getchValc(x, 'l', 8); // subject credits
			coorxy(a + 92, b); cout << string(8, ' ');
			coorxy(a + 92, b); cout << x;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 4:
			coorxy(a + 102, b); sm = getchValc(y, 'l', 8);  // subject pre req 1
			coorxy(a + 102, b); cout << string(7, ' ');
			coorxy(a + 102, b); cout << y;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
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

	if (x == 1) {



		string currentfile; // storage for filename

		string pooln, fname, mname, lname, age, gender, lrn, bmonth, bday, byear, barangay, municipality, province, gfname, gmname, glname, gcnum,
			grelation, year,sem;// Local varible storage for information

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


		table();

		if (acc != 1) { // display access table
			for (int a = 26; a <= 29; a++) {
				coorxy(69, a); cout << string(17, ' ');
			}

			for (int a = 1; a <= 3; a++) {
				coorxy(0, a); cout << string(50, ' ');
			}


			coorxy(48, 27); cout << string(10,' ');
			coorxy(51, 27); cout << "ADD";
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
									getline(ss, year, '$');
									getline(ss, sem, '$');
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
									glname = "", gcnum = "", grelation = "", year = "", sem = "";


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
				} else {

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
					else counter = 20;
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
				coorxy(29, 18); n = getchVal(province, 'n', 87);
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

					if (fname != "" && mname != "" && lname != "" && age != "" && gender != "" && lrn != "" && bmonth != "" && bday != "" && byear != "" && barangay != "" && municipality != "" && province != "" && gfname != "" && gmname != "" && glname != "" && grelation != "" && gcnum != "") {


						//checking if pooling number is already registerd - done

						if (year == "" && sem == "") {
							system("cls");
							do {
								coorxy(45, 11); cout << "What year do you want to enroll? :    ";
								coorxy(80, 11); getchVal(e, 'n', 1);
							} while (e != "1" && e != "2" && e != "3" && e != "4");
							year = e;
							do {
								e = "";
								coorxy(45, 12); cout << "Enter what semester :    ";
								coorxy(67, 12); getchVal(e, 'n', 1);
								//e += f;

							} while (e != "1" && e != "2");
							sem = e;
							e = "";
							coorxy(45, 14); cout << "target year/sem code" << year << sem;

							// Pooling number table
							coorxy(43, 16); cout << char(179) << " Pooling num : " << temppoolnum;  // number
							pooln = temppoolnum;
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
						savefile << pooln + "$" + fname + "$" + mname + "$" + lname + "$" + age + "$" + gender + "$" + lrn + "$" + bmonth + "$" + bday + "$" + byear + "$" + barangay + "$" + municipality + "$" + province + "$" + gfname + "$" + gmname + "$" + glname + "$" + gcnum + "$" + grelation + "$" + year + "$" + sem << endl;
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
						glname = "", gcnum = "", grelation = "", year = "", sem="";

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
				break;

			case 19:
				if (acc == 1) { // admin access

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
							glname = "", gcnum = "", grelation = "", year = "", sem = "";


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

						counter = 0;
						coorxy(68, 27); cout << "  ";
						coorxy(86, 27); cout << "  ";
						system("cls");
						table();
					}
				}
				else {
					counter = 20;
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
					if (c == 72 || c == 75) {
						if (acc == 1) {
							counter--;
						}
						else counter = 18;
					}
					else if (c == 80 || c == 77) {
						if (acc == 1) counter = 0;
						else counter = 1;
					}
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
		string ysuff, ssuff;


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


		if (acc != 1) {
			for (int a = 26; a <= 29; a++) {
				coorxy(57, a); cout << string(40, ' ');
			}
		}





		// doing the switching rows - done

		do {

		W:

			switch (counter) {

			case 0:
				coorxy(20, 2); st = getchValc(year, 'n', 1);
				coorxy(20, 2); cout << string(1, ' ');
				coorxy(20, 2); cout << year;
				if (st == 111) counter++;
				else if (st == 100) goto W;
				goto W;
				break;

			case 1:
				coorxy(64, 2); st = getchValc(sem, 'n', 1);
				coorxy(64, 2); cout << string(1, ' ');
				coorxy(64, 2); cout << sem;
				coorxy(64, 2);
				if (st == 101) counter--;
				else if (st == 111) {
					if (sem == "") {
						counter = 0;
						goto W;
					}
					else {
						if (acc == 1) {
							counter++;
						}
						else {
							counter = 13;
						}

					}

					// Erasing variables first

					for (int z = 0; z < 45; z++) {
						var[z] = "";
					}

					// Clearing display

					cx = 5;
					cy = 8;

					for (int z = 0; z < 9; z++) {
						coorxy(cx, cy);
						for (int x = 0; x < 1; x++) {
							coorxy(cx, cy); cout << string(4, ' '); // no
							cx += 6;
							coorxy(cx, cy); cout << string(23, ' '); // year level
							cx += 25;
							coorxy(cx, cy); cout << string(13, ' '); // subject code
							cx += 15;
							coorxy(cx, cy); cout << string(38, ' '); // subject description
							cx += 40;
							coorxy(cx, cy); cout << string(8, ' '); // credits
							cx += 10;
							coorxy(cx, cy); cout << string(14, ' '); // subject pre requisites (both 1 & 2)
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

								for (int x = 0; x < 5; x++) {
									getline(ss, var[cntr], '$');
									cntr++;
								}
							}
						}
						openf.close();

						// displaying the variables

						if (year == "1" && sem == "1")
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
						}

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
									cx += 7;
									lvar++;
									coorxy(cx, cy); cout << var[lvar];
									lvar++;
									coorxy(11, 8 + dn); cout <<" Year" << year << " " << "sem "<< sem;
									coorxy(5, 8 + dn); cout << num;
									num++;
									dn += 2;
									cy += 2;
								}
								else {
									lvar += 5;
								}
							}
							r += 5;
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

						for (int z = 0; z < 45; z++) {
							var[z] = "";
						}

						// Clearing display

						cx = 5;
						cy = 8;

						for (int z = 0; z < 9; z++) {
							coorxy(cx, cy);
							for (int x = 0; x < 1; x++) {
								coorxy(cx, cy); cout << string(4, ' ');
								cx += 6;
								coorxy(cx, cy); cout << string(23, ' ');
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
					multival(var[0], var[1], var[2], var[3],var[4], 0, 8, 0);
					break;
				case 8:
					multival(var[0], var[1], var[2], var[3], var[4], 0, 8, 1);
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
					multival(var[5], var[6], var[7], var[8], var[9], 0, 10, 0);
					break;
				case 8:
					multival(var[5], var[6], var[7], var[8], var[9], 0, 10, 1);
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
					multival(var[10], var[11], var[12], var[13], var[14], 0, 12, 0);
					break;
				case 8:
					multival(var[10], var[11], var[12], var[13], var[14], 0, 12, 1);
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
					multival(var[15], var[16], var[17], var[18], var[19], 0, 14, 0);
					break;
				case 8:
					multival(var[15], var[16], var[17], var[18], var[19], 0, 14, 1);
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
					multival(var[20], var[21], var[22], var[23], var[24], 0, 16, 0);
					break;
				case 8:
					multival(var[20], var[21], var[22], var[23], var[24], 0, 16, 1);
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
					multival(var[25], var[26], var[27], var[28], var[29], 0, 18, 0);
					break;
				case 8:
					multival(var[25], var[26], var[27], var[28], var[29], 0, 18, 1);
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
					multival(var[30], var[31], var[32], var[33], var[34], 0, 20, 0);
					break;
				case 8:
					multival(var[30], var[31], var[32], var[33], var[34], 0, 20, 1);
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
					multival(var[35], var[36], var[37], var[38], var[39], 0, 22, 0);
					break;
				case 8:
					multival(var[35], var[36], var[37], var[38], var[39], 0, 22, 1);
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
					multival(var[40], var[41], var[42], var[43], var[44], 0, 24, 0);
					break;
				case 8:
					multival(var[40], var[41], var[42], var[43], var[44], 0, 24, 1);
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
						if (acc == 1) {
							counter--;
						}
						else {
							counter = 0;
						}
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
//			menu(num, access); // Options when entered part 2
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

// registration
	
//int main() { // registration
//	string currentfile;
//
//	string pooln, fname, mname, lname, age, gender, lrn, bmonth, bday, byear, barangay, municipality, province, gfname, gmname, glname, gcnum,
//		grelation, targety;// Local varible storage for information
//
//	string finder; // storage for searching pooling number
//	string temppoolnum; // temporary storage for filename
//	string searchpool[32]; // array storage for searching
//	string e; //local variable for targety
//
//	char d; // local variable for getch in switching
//
//	int temppool = 20240001;// variable for temporary pooling num (need for finding empty pool)
//	int ext = 0; // variable for exit confirmation
//	int exit = 0; // local variable
//	int counter = 0; // local variable // counter 
//	int n; // storage for returning value
//	int i = 0; // student counter // local variable
//	int racc = 0; // registration saving acces
//
//
//
//	//finding the empty file - done
//
//	temppool = 20240001;
//	ext = 0;
//	do {
//		string tempfinder = to_string(temppool) + ".txt";
//		ifstream newfile; // making new file and check if it exist
//		newfile.open(tempfinder);
//		if (newfile.is_open()) {
//			temppool++;
//			newfile.close();
//		}
//		else {
//			temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//			currentfile = temppoolnum + ".txt";
//			ext = 1;
//			break;
//		}
//	} while (ext != 1);
//
//
//	table();
//
//
//
//
//
//	for (i = 0;;) {
//	Q:
//
//		switch (counter) {
//		case 0:
//
//
//			coorxy(31, 2);
//			for (int j = 0;;) {
//				d = _getch();
//				if (d == -32) {
//					d = _getch();
//					if (d == 72 || d == 75) {
//						counter = 20;
//						break;
//					}
//					else if (d == 80 || d == 77) {
//						counter++;
//						break;
//					}
//				}
//				else if (d == 8 && j >= 1) {
//					cout << "\b \b";
//					searchpool[--j] = '\0';
//				}
//				else if ((d >= '0' && d <= '9') && j < 8) {
//					cout << d;
//					searchpool[j] = d;
//					++j;
//				}
//				else if (d == 13) {
//					//counter++;
//					searchpool[j] = '\0';
//
//					for (int k = 0; k < 8; k++) { // converting string array searchpoolnum[32] to single value finder
//						finder += searchpool[k];
//
//					}
//
//					// Erasing display
//
//					coorxy(19, 6); cout << string(15, ' ');
//					coorxy(57, 6); cout << string(15, ' ');
//					coorxy(93, 6); cout << string(15, ' ');
//					coorxy(18, 8); cout << string(15, ' ');
//					coorxy(18, 10); cout << string(15, ' ');
//					coorxy(56, 10); cout << string(15, ' ');
//					coorxy(26, 12); cout << string(15, ' ');
//					coorxy(56, 12); cout << string(15, ' ');
//					coorxy(93, 12); cout << string(15, ' ');
//					coorxy(29, 14); cout << string(15, ' ');
//					coorxy(33, 16); cout << string(15, ' ');
//					coorxy(29, 18); cout << string(15, ' ');
//					coorxy(31, 20); cout << string(15, ' ');
//					coorxy(65, 20); cout << string(15, ' ');
//					coorxy(97, 20); cout << string(15, ' ');
//					coorxy(35, 22); cout << string(15, ' ');
//					coorxy(29, 24); cout << string(15, ' ');
//
//					// youre here at finding  - done
//
//					string findtxt = finder + ".txt";
//					ifstream loadfile(findtxt);
//					if (loadfile.is_open()) { // if found, store the data
//						currentfile = findtxt;
//						string line;
//						while (getline(loadfile, line)) {
//							stringstream ss(line);
//							getline(ss, pooln, '$');
//							getline(ss, fname, '$');
//							getline(ss, mname, '$');
//							getline(ss, lname, '$');
//							getline(ss, age, '$');
//							getline(ss, gender, '$');
//							getline(ss, lrn, '$');
//							getline(ss, bmonth, '$');
//							getline(ss, bday, '$');
//							getline(ss, byear, '$');
//							getline(ss, barangay, '$');
//							getline(ss, municipality, '$');
//							getline(ss, province, '$');
//							getline(ss, gfname, '$');
//							getline(ss, gmname, '$');
//							getline(ss, glname, '$');
//							getline(ss, gcnum, '$');
//							getline(ss, grelation, '$');
//							getline(ss, targety, '$');
//						}
//
//						// displaying found datas - done
//
//						coorxy(19, 6); cout << fname;
//						coorxy(57, 6); cout << mname;
//						coorxy(93, 6); cout << lname;
//						coorxy(18, 8); cout << age;
//						coorxy(18, 10); cout << gender;
//						coorxy(56, 10); cout << lrn;
//						coorxy(26, 12); cout << bmonth;
//						coorxy(56, 12); cout << bday;
//						coorxy(93, 12); cout << byear;
//						coorxy(29, 14); cout << barangay;
//						coorxy(33, 16); cout << municipality;
//						coorxy(29, 18); cout << province;
//						coorxy(31, 20); cout << gfname;
//						coorxy(65, 20); cout << gmname;
//						coorxy(97, 20); cout << glname;
//						coorxy(35, 22); cout << gcnum;
//						coorxy(29, 24); cout << grelation;
//
//
//						loadfile.close();
//						coorxy(10, 0); cout << "         ";
//						coorxy(10, 0); cout << "found";
//					}
//					else { // if not found;
//
//
//						// erasing display - done
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
//
//						pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "", // resetting variable values
//							lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
//							municipality = "", province = "", gfname = "", gmname = "",
//							glname = "", gcnum = "", grelation = "", targety = "";
//
//
//						// finding new empty pooling number - done
//
//						temppool = 20240001; // temporary pooling number
//						ext = 0; // confirmation exit
//						do {
//							string tempfinder = to_string(temppool) + ".txt";
//							ifstream newfile; // making new file and check if it exist
//							newfile.open(tempfinder);
//							if (newfile.is_open()) {
//								temppool++;
//								newfile.close();
//							}
//							else {
//								finder = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//								currentfile = finder + ".txt";
//								ext = 1;
//								break;
//							}
//						} while (ext != 1);
//						coorxy(10, 0); cout << "not found";
//					}
//
//
//					coorxy(31, 2); cout << string(8, ' ');
//
//					j = 0; // resetting the searchfinder
//					temppoolnum = finder; // backuping the pooling num
//					finder = ""; // resetting poolinf finder
//					counter = 0;
//					goto Q;
//				}
//			}
//
//
//			break;
//		case 1:
//			coorxy(19, 6); n = getchVal(fname, 'l', 21);
//			coorxy(19, 6); cout << string(21, ' ');
//			coorxy(19, 6); cout << fname;//getchcout(fname);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 2:
//			coorxy(57, 6); n = getchVal(mname, 'l', 21);
//			coorxy(57, 6); cout << string(21, ' ');
//			coorxy(57, 6); cout << mname; //getchcout(mname);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 3:
//			coorxy(93, 6); n = getchVal(lname, 'l', 23);
//			coorxy(93, 6); cout << string(23, ' ');
//			coorxy(93, 6); cout << lname; //getchcout(lname);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 4:
//			coorxy(18, 8); n = getchVal(age, 'n', 2);
//			coorxy(18, 8); cout << string(2, ' ');
//			coorxy(18, 8); cout << age; //getchcout(age);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 5:
//			coorxy(18, 10); n = getchVal(gender, 'l', 29);
//			coorxy(18, 10); cout << string(29, ' ');
//			coorxy(18, 10); cout << gender; //getchcout(gender);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 6:
//			coorxy(56, 10); n = getchVal(lrn, 'n', 12);
//			coorxy(56, 10); cout << string(12, ' ');
//			coorxy(56, 10); cout << lrn; //getchcout(lrn);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 7:
//			coorxy(26, 12); n = getchVal(bmonth, 'l', 21);
//			coorxy(26, 12); cout << string(21, ' ');
//			coorxy(26, 12); cout << bmonth; //getchcout(bmonth);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 8:
//			coorxy(56, 12); n = getchVal(bday, 'n', 2);
//			coorxy(56, 12); cout << string(2, ' ');
//			coorxy(56, 12); cout << bday; //getchcout(bday);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 9:
//			coorxy(93, 12); n = getchVal(byear, 'n', 4);
//			coorxy(93, 12); cout << string(4, ' ');
//			coorxy(93, 12); cout << byear; //getchcout(byear);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 10:
//			coorxy(29, 14); n = getchVal(barangay, 'l', 87);
//			coorxy(29, 14); cout << string(87, ' ');
//			coorxy(29, 14); cout << barangay; //getchcout(barangay);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 11:
//			coorxy(33, 16); n = getchVal(municipality, 'l', 83);
//			coorxy(33, 16); cout << string(83, ' ');
//			coorxy(33, 16); cout << municipality; //getchcout(municipality);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 12:
//			coorxy(29, 18); n = getchVal(province, 'n', 87);
//			coorxy(29, 18); cout << string(87, ' ');
//			coorxy(29, 18); cout << province; //getchcout(province);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//			/*case 13:
//				coorxy(38, 21); n = getchVal(postalzip, 4);
//				coorxy(38, 21); cout << string(20, ' ');
//				coorxy(38, 21); getchcout(postalzip);
//				if (n == 101) counter--;
//				else counter++;
//				goto Q;
//				break;*/
//		case 13:
//			coorxy(31, 20); n = getchVal(gfname, 'l', 17);
//			coorxy(31, 20); cout << string(17, ' ');
//			coorxy(31, 20); cout << gfname;// getchcout(gfname);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 14:
//			coorxy(65, 20); n = getchVal(gmname, 'l', 17);
//			coorxy(65, 20); cout << string(17, ' ');
//			coorxy(65, 20); cout << gmname; //getchcout(gmname);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 15:
//			coorxy(97, 20); n = getchVal(glname, 'l', 19);
//			coorxy(97, 20); cout << string(19, ' ');
//			coorxy(97, 20); cout << glname; //getchcout(glname);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 16:
//			coorxy(35, 22); n = getchVal(gcnum, 'n', 11);
//			coorxy(35, 22); cout << string(11, ' ');
//			coorxy(35, 22); cout << gcnum; //getchcout(gcnum);
//			if (n == 101) counter--;
//			else counter++;
//			goto Q;
//			break;
//		case 17:
//			coorxy(29, 24); n = getchVal(grelation, 'l', 87);
//			coorxy(29, 24); cout << string(87, ' ');
//			coorxy(29, 24); cout << grelation; //getchcout(grelation);
//			if (n == 101) counter--;
//			else counter++;
//			break;
//		case 18:
//			coorxy(42, 27); cout << "<<";
//			coorxy(62, 27); cout << ">>";
//			char a;
//			a = _getch();
//			if (a == -32) {
//				a = _getch();
//				coorxy(42, 27); cout << "  ";
//				coorxy(62, 27); cout << "  ";
//				if (a == 72 || a == 75) counter--;
//				else if (a == 80 || a == 77) counter++;
//			}
//			else if (a == 13) {
//
//				coorxy(42, 27); cout << "  ";
//				coorxy(62, 27); cout << "  ";
//				coorxy(43, 27); cout << "<<";
//				coorxy(61, 27); cout << ">>";
//				Sleep(100);
//
//				// information must not be empty inorder to add or save
//
//				if (fname != "" && mname != "" && lname != "" && age != "" && gender != "" && lrn != "" && bmonth != "" && bday != "" && byear != "" && barangay != "" && municipality != "" && province != "" && gfname != "" && gmname != "" && glname != "" && grelation != "" && gcnum != "") {
//
//
//					//checking if pooling number is already registerd - done
//
//					if (targety == "") {
//						system("cls");
//						pooltable();
//						do {
//							coorxy(45, 11); cout << "What year do you want to enroll? :    ";
//							coorxy(80, 11); getchVal(e, 'n', 1);
//						} while (e != "1" && e != "2" && e != "3" && e != "4");
//						targety = e;
//						do {
//							e = "";
//							coorxy(45, 12); cout << "Enter what semester :    ";
//							coorxy(67, 12); getchVal(e, 'n', 1);
//							//e += f;
//
//						} while (e != "1" && e != "2");
//						targety += e;
//						e = "";
//						coorxy(45, 14); cout << "target year/sem code" << targety;
//
//						// Pooling number table
//						coorxy(43, 16); cout << char(179) << " Pooling num : " << temppoolnum;  // number
//						n = 0;
//						coorxy(68, 16); cout << char(179);
//						for (int j = 0; j < 2; j++) {
//							coorxy(43, 15 + n); cout << string(26, char(196));
//							n += 2;
//						}
//						coorxy(43, 18); system("pause");
//					}
//
//
//					// saving the file - done
//
//					ofstream savefile;
//					savefile.open(currentfile);
//					savefile << pooln + "$" + fname + "$" + mname + "$" + lname + "$" + age + "$" + gender + "$" + lrn + "$" + bmonth + "$" + bday + "$" + byear + "$" + barangay + "$" + municipality + "$" + province + "$" + gfname + "$" + gmname + "$" + glname + "$" + gcnum + "$" + grelation + "$" + targety + "$" << endl;
//					savefile.close();
//				}
//
//				//finding the empty file - done
//
//				int temppool = 20240001;
//				int ext = 0;
//				do {
//					string tempfinder = to_string(temppool) + ".txt";
//					ifstream newfile; // making new file and check if it exist
//					newfile.open(tempfinder);
//					if (newfile.is_open()) {
//						temppool++;
//						newfile.close();
//					}
//					else {
//						temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//						currentfile = temppoolnum + ".txt";
//						ext = 1;
//						break;
//					}
//				} while (ext != 1);
//
//
//				coorxy(43, 27); cout << "  ";
//				coorxy(61, 27); cout << "  ";
//
//				//Erasing Values - done
//
//				pooln = "", fname = "", mname = "", lname = "", age = "", gender = "",
//					lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
//					municipality = "", province = "", gfname = "", gmname = "",
//					glname = "", gcnum = "", grelation = "", targety = "";
//
//				system("cls");
//				table();
//			}
//			break;
//
//		case 19:
//
//			// youre here
//
//			coorxy(67, 27); cout << "<<";
//			coorxy(87, 27); cout << ">>";
//			char b;
//			b = _getch();
//			if (b == -32) {
//				b = _getch();
//				coorxy(67, 27); cout << "  ";
//				coorxy(87, 27); cout << "  ";
//				if (b == 72 || b == 75) counter--;
//				else if (b == 80 || b == 77) counter++;
//			}
//			else if (b == 13) {
//				i;
//				coorxy(67, 27); cout << "  ";
//				coorxy(87, 27); cout << "  ";
//				coorxy(68, 27); cout << "<<";
//				coorxy(86, 27); cout << ">>";
//				Sleep(100);
//
//
//				// Youre here at deleting the file
//
//				remove(currentfile.c_str());
//
//
//
//				// Erasing Values - done
//
//				pooln = ""; fname = "", mname = "", lname = "", age = "", gender = "",
//					lrn = "", bmonth = "", bday = "", byear = "", barangay = "",
//					municipality = "", province = "", gfname = "", gmname = "",
//					glname = "", gcnum = "", grelation = "", targety = "";
//
//
//				n = 0;
//				coorxy(3, 27); cout << string(20, ' ');
//				coorxy(28, 27); cout << ' ';
//				for (int x = 0; x < 2; x++) {
//					coorxy(3, 26 + n); cout << string(26, ' ');
//					n += 2;
//				}
//
//
//				//finding the empty file - done
//
//				int temppool = 20240001;
//				int ext = 0;
//				do {
//					string tempfinder = to_string(temppool) + ".txt";
//					ifstream newfile; // making new file and check if it exist
//					newfile.open(tempfinder);
//					if (newfile.is_open()) {
//						temppool++;
//						newfile.close();
//					}
//					else {
//						temppoolnum = to_string(temppool); // if it doesnt exist, it'll be as the current file;
//						currentfile = temppoolnum + ".txt";
//						ext = 1;
//						break;
//					}
//				} while (ext != 1);
//
//				counter = 0; 
//				coorxy(68, 27); cout << "  ";
//				coorxy(86, 27); cout << "  ";
//				system("cls");
//				table();
//			}
//			break;
//
//		case 20:
//			coorxy(92, 27); cout << "<<";
//			coorxy(112, 27); cout << ">>";
//			char c;
//			c = _getch();
//			if (c == -32) {
//				c = _getch();
//				coorxy(92, 27); cout << "  ";
//				coorxy(112, 27); cout << "  ";
//				if (c == 72 || c == 75) counter--;
//				else if (c == 80 || c == 77) counter = 0;
//			}
//			else if (c == 13) {
//				coorxy(92, 27); cout << "  ";
//				coorxy(112, 27); cout << "  ";
//				coorxy(93, 27); cout << "<<";
//				coorxy(111, 27); cout << ">>";
//				Sleep(100);
//				system("cls");
//				exit = 1;
//			}
//			break;
//		}
//		if (exit == 1) break;
//	}
//	system("cls");
//}

// curiculum

//int main() {
//	string var[45]; // variables
//	string year; // variable for searching year
//	string sem; // variable for searching sem
//	string temp; // temporary storage for searching file
//	string ysuff, ssuff;
//
//	int counter = 0; // counter for option
//	int ext = 0; // exit confirmation
//	int cntr = 0; // counter for database
//	int dltd = 0; // variable for empty subject
//	int st; // storage for returning value
//
//	//variables for display
//	int cx = 37; // x position
//	int cy = 8; // y position
//
//	//variables for display - for year and sem
//	int dn = 0;
//	int r = 0;
//	int lvar = 0;
//	int num = 1;
//
//	tablec();
//
//
//
//
//
//	// doing the switching rows - done
//
//	do {
//
//	W:
//
//		switch (counter) {
//
//		case 0:
//			coorxy(20, 2); st = getchValc(year, 'n', 1);
//			coorxy(20, 2); cout << string(1, ' ');
//			coorxy(20, 2); cout << year;
//			if (st == 111) counter++;
//			else if (st == 100) goto W;
//			goto W;
//			break;
//
//		case 1:
//			coorxy(64, 2); st = getchValc(sem, 'n', 1);
//			coorxy(64, 2); cout << string(1, ' ');
//			coorxy(64, 2); cout << sem;
//			coorxy(64, 2);
//			if (st == 101) counter--;
//			else if (st == 111) {
//				counter++;
//
//				// Erasing variables first
//
//				for (int z = 0; z < 45; z++) {
//					var[z] = "";
//				}
//
//				// Clearing display
//
//				cx = 5;
//				cy = 8;
//
//				for (int z = 0; z < 9; z++) {
//					coorxy(cx, cy);
//					for (int x = 0; x < 1; x++) {
//						coorxy(cx, cy); cout << string(4, ' '); // no
//						cx += 6;
//						coorxy(cx, cy); cout << string(23, ' '); // year level
//						cx += 25;
//						coorxy(cx, cy); cout << string(13, ' '); // subject code
//						cx += 15;
//						coorxy(cx, cy); cout << string(38, ' '); // subject description
//						cx += 40;
//						coorxy(cx, cy); cout << string(8, ' '); // credits
//						cx += 10;
//						coorxy(cx, cy); cout << string(14, ' '); // subject pre requisites (both 1 & 2)
//					}
//					cy += 2;
//					cx = 5;
//				}
//
//
//
//
//				// Loading file
//
//				if ((year == "1" || year == "2" || year == "3" || year == "4") && (sem == "1" || sem == "2")) {
//
//					temp = year + sem + ".txt";
//					ifstream openf(temp);
//					if (openf.is_open()) { // if found
//
//						//reset display
//
//						r = 0;
//						dn = 0;
//						cntr = 0;
//						string line;
//						for (int z = 0; z < 9; z++) {
//							getline(openf, line);
//							stringstream ss(line);
//
//							for (int x = 0; x < 5; x++) {
//								getline(ss, var[cntr], '$');
//								cntr++;
//							}
//						}
//					}
//					openf.close();
//
//					// displaying the variables
//
//					if (year == "1" && sem == "1")
//					{
//						ysuff = "st";
//						ssuff = "st";
//					}
//					else if (year == "1" && sem == "2")
//					{
//						ysuff = "st";
//						ssuff = "nd";
//					}
//					else if (year == "2" && sem == "1")
//					{
//						ysuff = "nd";
//						ssuff = "st";
//					}
//					else if (year == "2" && sem == "2")
//					{
//						ysuff = "nd";
//						ssuff = "nd";
//					}
//					else if (year == "3" && sem == "1")
//					{
//						ysuff = "rd";
//						ssuff = "st";
//					}
//					else if (year == "3" && sem == "2")
//					{
//						ysuff = "rd";
//						ssuff = "nd";
//					}
//					else if (year == "4" && sem == "1")
//					{
//						ysuff = "th";
//						ssuff = "st";
//					}
//					else if (year == "4" && sem == "2")
//					{
//						ysuff = "th";
//						ssuff = "nd";
//					}
//
//
//
//
//					cx = 37;
//					cy = 8;
//					lvar = 0;
//					r = 0;
//					dn = 0;
//					num = 1;
//
//					for (int z = 0; z < 9; z++) {
//						coorxy(cx, cy);
//						for (int x = 0; x < 1; x++) {
//							if (var[r] != "") {// skip if subject code is empty
//								coorxy(cx, cy); cout << var[lvar];
//								cx += 15;
//								lvar++;
//								coorxy(cx, cy); cout << var[lvar];
//								cx += 40;
//								lvar++;
//								coorxy(cx, cy); cout << var[lvar];
//								cx += 10;
//								lvar++;
//								coorxy(cx, cy); cout << var[lvar];
//								cx += 7;
//								lvar++;
//								coorxy(cx, cy); cout << var[lvar];
//								lvar++;
//								coorxy(11, 8 + dn); cout << year << ysuff << " Year" << " - " << sem << ssuff << " Semester";
//								coorxy(5, 8 + dn); cout << num;
//								num++;
//								dn += 2;
//								cy += 2;
//							}
//							else {
//								lvar += 5;
//							}
//						}
//						r += 5;
//						cx = 37;
//					}
//				}
//				else { // if not existing
//
//					// resetting year and sem
//
//					year = "";
//					sem = "";
//
//					coorxy(20, 2); cout << string(20, ' '); // erasing searchbar for year
//					coorxy(64, 2); cout << string(20, ' '); // erasing searchbar for sem
//
//					// Erasing variables first
//
//					for (int z = 0; z < 45; z++) {
//						var[z] = "";
//					}
//
//					// Clearing display
//
//					cx = 5;
//					cy = 8;
//
//					for (int z = 0; z < 9; z++) {
//						coorxy(cx, cy);
//						for (int x = 0; x < 1; x++) {
//							coorxy(cx, cy); cout << string(4, ' ');
//							cx += 6;
//							coorxy(cx, cy); cout << string(23, ' ');
//							cx += 25;
//							coorxy(cx, cy); cout << string(13, ' ');
//							cx += 15;
//							coorxy(cx, cy); cout << string(38, ' ');
//							cx += 40;
//							coorxy(cx, cy); cout << string(8, ' ');
//							cx += 10;
//							coorxy(cx, cy); cout << string(14, ' ');
//						}
//						cy += 2;
//						cx = 5;
//					}
//
//					counter = 13;
//				}
//			}
//
//			goto W;
//			break;
//		case 2:
//			coorxy(0, 8);
//			switch (_getch()) {
//			case 72:
//				counter = 0;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[0], var[1], var[2], var[3], var[4], 0, 8, 0);
//				break;
//			case 8:
//				multival(var[0], var[1], var[2], var[3], var[4], 0, 8, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 3:
//			coorxy(0, 10);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[5], var[6], var[7], var[8], var[9], 0, 10, 0);
//				break;
//			case 8:
//				multival(var[5], var[6], var[7], var[8], var[9], 0, 10, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 4:
//			coorxy(0, 12);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[10], var[11], var[12], var[13], var[14], 0, 12, 0);
//				break;
//			case 8:
//				multival(var[10], var[11], var[12], var[13], var[14], 0, 12, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 5:
//			coorxy(0, 14);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[15], var[16], var[17], var[18], var[19], 0, 14, 0);
//				break;
//			case 8:
//				multival(var[15], var[16], var[17], var[18], var[19], 0, 14, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 6:
//			coorxy(0, 16);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[20], var[21], var[22], var[23], var[24], 0, 16, 0);
//				break;
//			case 8:
//				multival(var[20], var[21], var[22], var[23], var[24], 0, 16, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 7:
//			coorxy(0, 18);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[25], var[26], var[27], var[28], var[29], 0, 18, 0);
//				break;
//			case 8:
//				multival(var[25], var[26], var[27], var[28], var[29], 0, 18, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 8:
//			coorxy(0, 20);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[30], var[31], var[32], var[33], var[34], 0, 20, 0);
//				break;
//			case 8:
//				multival(var[30], var[31], var[32], var[33], var[34], 0, 20, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 9:
//			coorxy(0, 22);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[35], var[36], var[37], var[38], var[39], 0, 22, 0);
//				break;
//			case 8:
//				multival(var[35], var[36], var[37], var[38], var[39], 0, 22, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 10:
//			coorxy(0, 24);
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				multival(var[40], var[41], var[42], var[43], var[44], 0, 24, 0);
//				break;
//			case 8:
//				multival(var[40], var[41], var[42], var[43], var[44], 0, 24, 1);
//				break;
//			}
//			goto W;
//			break;
//		case 11:
//			coorxy(57, 27); cout << "<<";
//			coorxy(77, 27); cout << ">>";
//
//			switch (_getch()) {
//
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				coorxy(57, 27); cout << " <<";
//				coorxy(76, 27); cout << ">> ";
//				Sleep(100);
//
//				// Add / update here to data base
//
//				if (temp != "") { // condition to check temporary file is empty
//					cntr = 0;
//					r = 0;
//					dltd = 0;
//					ofstream savefile;
//					savefile.open(temp);
//					for (int z = 0; z < 9; z++) { // this is for saving existing subject
//						if (var[r] != "") { // this is to check if subject is not empty
//							for (int x = 0; x < 5; x++) {
//								savefile << var[cntr] + "$";
//								cntr++;
//							}
//							savefile << endl;
//						}
//						else { // if subject is empty
//							cntr += 5; // this is to skip the iteration of variables
//							dltd++; // this is the counter of how many subject is emtpy
//						}
//						r += 5;
//					}
//					for (int z = 0; z < dltd; z++) { // this is to add empty lines in the end depending on how many subject is empty
//						savefile << "$$$$$" << endl;
//					}
//					savefile.close();
//				}
//				year = "";
//				sem = "";
//				counter = 0;
//				system("cls");
//				tablec();
//
//				break;
//			}
//
//			coorxy(57, 27); cout << "   ";
//			coorxy(76, 27); cout << "   ";
//			goto W;
//			break;
//		case 12:
//			coorxy(77, 27); cout << "<<";
//			coorxy(97, 27); cout << ">>";
//			switch (_getch()) {
//			case 72:
//				counter--;
//				break;
//			case 80:
//				counter++;
//				break;
//			case 13:
//				coorxy(77, 27); cout << " <<";
//				coorxy(96, 27); cout << ">> ";
//				Sleep(100);
//
//
//				// deleting file
//
//				// Erasing
//
//				for (int z = 0; z < 36; z++) {
//					var[z] = "";
//				}
//
//				if (temp != "") { // condition to check temporary file is empty
//					cntr = 0;
//					ofstream savefile;
//					savefile.open(temp);
//					for (int z = 0; z < 9; z++) {
//						for (int x = 0; x < 5; x++) {
//							savefile << var[cntr] + "$";
//							cntr++;
//						}
//						savefile << endl;
//					}
//					savefile.close();
//				}
//				year = "";
//				sem = "";
//				counter = 0;
//				system("cls");
//				tablec();
//
//
//				remove(temp.c_str());
//				break;
//			}
//			coorxy(77, 27); cout << "   ";
//			coorxy(96, 27); cout << "   ";
//			goto W;
//			break;
//		case 13:
//			coorxy(97, 27); cout << "<<";
//			coorxy(117, 27); cout << ">>";
//			switch (_getch()) {
//			case 72:
//			case 75:
//				if (year == "" && sem == "") {
//					counter = 0;
//				}
//				else {
//					counter--;
//				}
//				coorxy(97, 27); cout << "  ";
//				coorxy(117, 27); cout << "  ";
//				goto W;
//				break;
//			case 80:
//			case 77:
//				counter = 0;
//				coorxy(97, 27); cout << "  ";
//				coorxy(117, 27); cout << "  ";
//				goto W;
//				break;
//			case 13:
//				coorxy(97, 27); cout << " <<";
//				coorxy(116, 27); cout << ">> ";
//				Sleep(100);
//				ext = 1;
//				break;
//			}
//			coorxy(97, 27); cout << "   ";
//			coorxy(116, 27); cout << "   ";
//			break;
//		}
//	} while (ext != 1);
//	system("cls");
//}

///////////////////////////////

int main() {
	/*font1(300, 10, 20);*/
	menu(1,0); // youre at access in enrollment
}

//enrolment


//bool marks(int x, string y, string  z) {
//	if (x == 1) {
//		if (y == "1") {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	else if (x == 2) {
//		if (y == "1" && z == "1") {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//}

//int main() { // Enrolment
//	//menu(2);
//
//	string finder; // finder storage
//	int lcntr; // local counter // inside switch
//	int tempre; // return value storage
//	int cntr = 0; // counter for first switch
//	int tempyear; // temporary strage for year string to int conversion
//	int tempsem;// temporary strage for sem string to int conversion
//	int v = 0; // temporary variable storage for storing sub
//	int n1 = 0; // counter for number of prereq
//
//	string subfile;
//	string stinfo[20]; // storage for student information
//
//	string dssub[45]; // storage for incoming subject
//	string presub[45]; // storage for previous sub
//	
//
//
//	R:
//	switch (cntr) {
//	case 0:
//		page1(); // display table
//
//		tempre = 0;
//		lcntr = 0;
//		finder = "";
//
//		E:
//			
//		// Switch for local option
//
//		switch (lcntr) {
//		case 0:
//			coorxy(27, 2);	tempre = getchVal2(finder, 'n', 8);
//			coorxy(27, 2); cout << string(8, ' ');
//			coorxy(27, 2); cout << finder;
//			if (tempre == 101) lcntr = 2;
//			else if (tempre == 110) lcntr++;
//			else if (tempre == 100) goto E;
//			else if (tempre == 111) {
//
//				string txtfile = finder + ".txt";
//				ifstream file(txtfile);
//
//				if (file.is_open()) {
//
//					string line;
//					while (getline(file, line)) {
//						stringstream ss(line);
//						for (int x = 0; x < 20; x++) {
//							getline(ss, stinfo[x], '$');
//						}
//					}
//				
//				// erase display - done
//					coorxy(15, 6); cout << string(25, ' '); // surname
//					coorxy(54, 6); cout << string(26, ' '); // firstname
//					coorxy(94, 6); cout << string(23, ' '); // middle name
//					coorxy(11, 8); cout << string(9, ' ');// age
//					coorxy(31, 8); cout << string(29, ' ');// gender
//					coorxy(68, 8); cout << string(15, ' ');// lrn
//					coorxy(15, 10); cout << string(102, ' ');// address
//					coorxy(21, 12); cout << string(5, ' ');// year
//					coorxy(73, 12); cout << string(5, ' ');// sem
//
//				// display
//				coorxy(15, 6); cout << stinfo[3]; // surname
//				coorxy(54, 6); cout << stinfo[1]; // first name
//				coorxy(95, 6); cout << stinfo[2]; // middle name
//				coorxy(11, 8); cout << stinfo[4]; // age
//				coorxy(31, 8); cout << stinfo[5]; // gender
//				coorxy(68, 8); cout << stinfo[6]; // lrn
//				coorxy(15, 10); cout << stinfo[10] << " " << stinfo[11] << " " << stinfo[12]; // address
//				coorxy(21, 12); cout << stinfo[18]; // year
//				coorxy(73, 12); cout << stinfo[19]; // sem
//				}
//				else {
//
//					// remove values
//
//					for (int x = 0; x < 20; x++) {
//						stinfo[x] = "";
//					}
//
//					// erase display - done
//					coorxy(15, 6); cout << string(25, ' '); // surname
//					coorxy(54, 6); cout << string(26, ' '); // firstname
//					coorxy(94, 6); cout << string(23, ' '); // middle name
//					coorxy(11, 8); cout << string(9, ' ');// age
//					coorxy(31, 8); cout << string(29, ' ');// gender
//					coorxy(68, 8); cout << string(15, ' ');// lrn
//					coorxy(15, 10); cout << string(102, ' ');// address
//					coorxy(21, 12); cout << string(5, ' ');// year
//					coorxy(73, 12); cout << string(5, ' ');// sem
//				}
//				file.close();
//
//				// Open another ifstream for future subject
//				v = 0;
//				string subf;
//				subf = stinfo[18] + stinfo[19] + ".txt";
//				ifstream subtxt(subf);
//				if (subtxt.is_open()) {
//					string line;
//					for (int x = 0; x < 9; x++) {
//						getline(subtxt, line);
//						stringstream ss(line);
//						if (line.substr(0) != "$$$$$") { // check if subject is not empty
//							for (int y = 0; y < 5; y++) {
//								getline(ss, dssub[v], '$');
//								v++;
//							}
//						}
//					}
//				}
//				subtxt.close();
//
//				// get the previous sub if not fresh man
//
//				if ((stinfo[18] == "2" && stinfo[19] == "1") || (stinfo[18] == "3" && stinfo[19] == "1") || (stinfo[18] == "4" && stinfo[19] == "1")) { // fresh for new year
//					tempyear = stoi(stinfo[18]) - 1;
//					tempsem = stoi(stinfo[19]) + 1;
//					v = 0;
//					string prevsubfile = to_string(tempyear) + to_string(tempsem) + ".txt";
//					ifstream subtxt(prevsubfile);
//					if (subtxt.is_open()) {
//						string line;
//						for (int x = 0; x < 9; x++) {
//							getline(subtxt, line);
//							stringstream ss(line);
//							if (line.substr(0) != "$$$$") { // check if subject is not empty
//								for (int y = 0; y < 5; y++) {
//									getline(ss, presub[v], '$');
//									v++;
//
//								}
//							}
//						}
//					}
//					subtxt.close();
//
//				}
//				else if (stinfo[19] == "2") { // if remain in same year
//
//					tempsem = stoi(stinfo[19]) - 1;
//					string prevsubfile = stinfo[18] + to_string(tempsem) + ".txt";
//					ifstream subtxt(prevsubfile);
//					v = 0;
//					if (subtxt.is_open()) {
//						string line;
//						for (int x = 0; x < 9; x++) {
//							getline(subtxt, line);
//							stringstream ss(line);
//							if (line.substr(0) != "$$$$") { // check if subject is not empty
//								for (int y = 0; y < 5; y++) {
//									getline(ss, presub[v], '$');
//									v++;
//								}
//							}
//						}
//					}
//					subtxt.close();
//				}
//
//
//
//				lcntr++;
//			}
//			goto E;
//			break;
//		case 1:
//
//			// Enroll Button
//
//			coorxy(77, 17); cout << "<< ";
//			coorxy(96, 17); cout << " >>";
//			//buttonxy2(80, 16, 14, 1, 2);
//			switch (_getch()) {
//				case 224:
//					switch (_getch()) { // Get the second value
//					case 72: // Up arrow
//						lcntr--;
//						break;
//					case 80: // Down arrow
//						lcntr++;
//						break;
//					}
//					coorxy(77, 17); cout << "   ";
//					coorxy(96, 17); cout << "   ";
//					goto E;
//					break;
//				case 13: // proceed to enroll
//					coorxy(77, 17); cout << " <<";
//					coorxy(96, 17); cout << ">> ";
//					buttonxy2(80,16,14,1,1);
//					Sleep(100);
//					int lext = 0;
//					for (int x = 0; x < 20; x++) {
//						if (stinfo[x] == "") {
//							break;
//						}
//						else {
//							lext = 1;
//							system("cls");
//						}
//					}
//
//					if (lext == 1) {
//						cntr++;
//						subfile = stinfo[18] + stinfo[19];
//						goto R;
//					}
//					else goto E;
//			}
//			break;
//		case 2:
//
//			// Back button
//
//			coorxy(97, 17); cout << "<< ";
//			coorxy(116, 17); cout << " >>";
//			//buttonxy2(100, 16, 14, 1, 2);
//			switch (_getch()) {
//			case 224:
//				switch (_getch()) { // Get the second value
//				case 72: // Up arrow
//					lcntr--;
//					break;
//				case 80: // Down arrow
//					lcntr=0;
//					break;
//				}
//				coorxy(97, 17); cout << "   ";
//				coorxy(116, 17); cout << "   ";
//				goto E;
//			case 13:
//				coorxy(97, 17); cout << " <<";
//				coorxy(116, 17); cout << ">> ";
//				buttonxy2(100, 16, 14, 1, 1);
//				Sleep(150);
//				system("cls");
//
//
//				// Back to main menu here
//
//				break;
//			}
//			
//			break;
//		} // this is for local switch
//		break;
//
//	case 1:
//
//		if (stinfo[18] == "1" && stinfo[19] == "1") { // if freshman
//			cntr++;
//			system("cls");
//			goto R;
//		}
//		else if ((stinfo[18] == "2" && stinfo[19] == "1") || (stinfo[18] == "3" && stinfo[19] == "1") || (stinfo[18] == "4" && stinfo[19] == "1")) { // getting the previos sub last year
//			page2();
//
//			// Getting the prereq subs - done
//
//			int prereq = 3;
//			int y =0; // counter for how many subject have pre requisites
//			string prereqsub[9]; // subject that have pre-requisites // 1 is the array of prereq // 2 is not prerequist
//			//string repititvesub;
//			for (int x = 0; x < 9; x++) {
//				if (dssub[prereq] != "NONE" && dssub[prereq] != "") { // check the first desired subject if it has pre-req
//					int cnf = 0;
//					for (int j = 0; j <=y; j++) { // checking if its not existing
//						if (dssub[prereq] == prereqsub[j]&& j<=y) { // check if pre-req is already in prereqsub storage
//							cnf = 0;
//							break;
//						}
//						else
//						{
//							cnf = 1;
//						}
//					}
//					if (cnf == 1) {
//						prereqsub[y] = dssub[prereq]; // store to pre requisite subject if not existing
//						y++;
//						cnf = 0;
//					}
//					if (dssub[prereq+1] != "NONE" && dssub[prereq+1] != "") { // check the second desired sub if it has pre-req
//							int cnf = 0;
//							for (int j = 0; j <=y; j++) { // checking if its not existing
//								if (dssub[prereq+1] == prereqsub[j] && j <= y) { // check again the second pre-req if its existing in prereqsub storage
//									cnf = 0;
//									break;
//								}
//								else
//								{
//									cnf = 1;
//								}
//							}
//							if (cnf == 1) {
//								prereqsub[y] = dssub[prereq+1]; // store if its not existing
//								y++;
//								cnf = 0;
//							}
//					}
//					prereq += 5;
//				}
//			}
//
//			// Displaying prerequisites
//
//			int cx =5;
//			int cy =8;
//			int z = 0;
//			n1=0;
//
//			for (int x = 0; x < y; x++) { 
//				z = 0;
//				cx = 5;
//				for (int a = 0; a < 9; a++){
//					if (prereqsub[x] == presub[z]) {
//						coorxy(cx, cy); cout << n1+1;
//						cx += 5;
//						coorxy(cx, cy); cout << "Year " << stinfo[18] << " / Sem " << stinfo[19];
//						cx += 27;
//						/*coorxy(cx, cy); cout << prereqsub[x];
//						cx += 10;*/
//						coorxy(cx, cy); cout << presub[z];
//						cx += 15;
//						coorxy(cx, cy); cout << presub[z + 1];
//						cy += 2;
//						n1++;
//						//z = 0;
//						break;
//					}
//					z += 5;
//				}
//			}
//
//
//			// this is for determining how many cases/cin will be used in marking
//
//			string* grd = new string[n1];
//			cx = 108;
//			cy = 8;
//			for (int a = 0; a < n1;a++) {
//				coorxy(cx, cy); getchVale(grd[a],'n',1);
//				cy += 2;
//			}
//
//			// Removing failed subjects to prereq array
//
//			for (int a = 0; a < n1;) { // YOUR PROBLEM IS WITH THE COUNTER OF GRD - youre at getting all the subjects
//				if (grd[a] == "0") { // if the pre req index == 0 / failed
//					int index = -1; // just initialization of not existing index
//					int sz = size(prereqsub); // declaring the size of the loop
//					for (int s = 0; s < sz; s++) {
//						if (prereqsub[s] == prereqsub[a]) { // loop will find the subject to be removed
//							index = a; // now declaring the index of subject to be removed
//							break;
//						}
//					}
//
//					if (index != -1) { // if index is existing
//						for (int a = index; a < sz - 1; a++) { // the loop will iterate througout the prereq array
//							prereqsub[a] = prereqsub[a + 1]; // Now the index of subject(to be removed) will be replaced by the next index
//						}
//						--sz;
//						for (int a = index; a < n1-1; a++) { // now the grade of next subject will be the first because the first one was removed
//							grd[a] = grd[a + 1];
//						}
//						--n1; // decrementing the number of iterations when subject is removed
//					}
//				}
//				else {
//					a++;
//				}
//			}
//
//			// This is just for testing
//
//			for (int a = 0; a < size(prereqsub); a++) {
//				cout <<endl<< prereqsub[a] << "     ";
//			}
//
//
//		}
//		else { // getting the previous sub of last sem
//			page2();	
//
//			// Getting the prereq subs - done
//
//			int prereq = 3;
//			int y = 0; // counter for how many subject have pre requisites
//			string prereqsub[9]; // subject that have pre-requisites // 1 is the array of prereq // 2 is not prerequist
//			string repititvesub;
//			for (int x = 0; x < 9; x++) {
//				if (dssub[prereq] != "NONE" && dssub[prereq] != "") {
//					int cnf = 0;
//					for (int j = 0; j <= y; j++) { // checking if its not existing
//						if (dssub[prereq] == prereqsub[j] && j <= y) {
//							cnf = 0;
//							break;
//						}
//						else
//						{
//							cnf = 1;
//						}
//					}
//					if (cnf == 1) {
//						prereqsub[y] = dssub[prereq];
//						y++;
//						cnf = 0;
//					}
//					if (dssub[prereq + 1] != "NONE" && dssub[prereq + 1] != "") {
//						//for (int j = 0; j < 5; j++) { // checking if its not exististing
//						int cnf = 0;
//						for (int j = 0; j <= y; j++) { // checking if its not existing
//							if (dssub[prereq + 1] == prereqsub[j] && j <= y) {
//								cnf = 0;
//								break;
//							}
//							else
//							{
//								cnf = 1;
//							}
//						}
//						if (cnf == 1) {
//							prereqsub[y] = dssub[prereq + 1];
//							y++;
//							cnf = 0;
//						}
//						//}
//					}
//					else {
//						//y++;
//					}
//					prereq += 5;
//				}
//
//
//			}
//
//			int cx = 5;
//			int cy = 8;
//			int z = 0;
//
//			// Displaying prerequisites
//
//			for (int x = 0; x < y; x++) {
//				z = 0;
//				cx = 5;
//				for (int a = 0; a < 9; a++) {
//					if (prereqsub[x] == presub[z]) {
//						coorxy(cx, cy); cout << n1 + 1;
//						cx += 5;
//						coorxy(cx, cy); cout << "Year " << stinfo[18] << " / Sem " << stinfo[19];
//						cx += 27;
//						/*coorxy(cx, cy); cout << prereqsub[x];
//						cx += 10;*/
//						coorxy(cx, cy); cout << presub[z];
//						cx += 15;
//						coorxy(cx, cy); cout << presub[z + 1];
//						cy += 2;
//						n1++;
//						//z = 0;
//						break;
//					}
//					z += 5;
//				}
//			}
//
//			//
//			//int* grd = new int[n1];
//			string *grd = new string[n1];
//
//			cx = 108;
//			cy = 8;
//			for (int a = 0; a < n1; a++) {
//				coorxy(cx, cy); cin >> grd[a];
//				cy += 2;
//			}
//
//			// Removing the failed subject to prereq
//
//			for (int a = 0; a < n1;) {
//				if (grd[a] == "0") { // if the pre req index == 0 / failed
//					int index = -1; // just initialization of not existing index
//					int sz = size(prereqsub); // declaring the size of the loop
//					for (int s = 0; s < sz; s++) {
//						if (prereqsub[s] == prereqsub[a]) { // loop will find the subject to be removed
//							index = a; // now declaring the index of subject to be removed
//							break;
//						}
//					}
//
//					if (index != -1) { // if index is existing
//						for (int a = index; a < sz - 1; a++) { // the loop will iterate througout the prereq array
//							prereqsub[a] = prereqsub[a + 1]; // Now the index of subject(to be removed) will be replaced by the next index
//						}
//						--sz;
//						for (int a = index; a < n1 - 1; a++) { // now the grade of next subject will be the first because the first one was removed
//							grd[a] = grd[a + 1];
//						}
//						--n1; // decrementing the number of iterations when subject is removed
//					}
//				}
//				else {
//					a++;
//				}
//			}
//
//			// This is just for testing
//
//			for (int a = 0; a < size(prereqsub); a++) {
//				cout << prereqsub[a]<< "     ";
//			}
//
//
//		}
//
//		break; // break for case 1
//	case 2:
//		page3();
//		break;
//	}
//
//	coorxy(0, 29); system("pause");
//}

//bool checkConditions(bool conditions[], const std::string conditionNames[], int numConditions) {
//	for (int i = 0; i < numConditions; ++i) {
//		if (!conditions[i]) {
//			std::cout << "Sorry, you did not meet the condition for " << conditionNames[i] << "." << std::endl;
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	const int NUM_CONDITIONS = 3;
//	bool conditions[NUM_CONDITIONS];
//	string conditionNames[NUM_CONDITIONS] = { "English", "Science", "PE" };
//
//	// Let's assume the user inputs whether the conditions are met
//	cout << "Enter '1' if the condition is met, and '0' otherwise." << std::endl;
//	for (int i = 0; i < NUM_CONDITIONS; ++i) {
//		cout << conditionNames[i] << ": ";
//		cin >> conditions[i];
//	}
//
//	// Check if all conditions are met
//	if (checkConditions(conditions, conditionNames, NUM_CONDITIONS)) {
//		cout << "Congratulations! You meet all the conditions." << std::endl;
//	}
//
//	return 0;
//}