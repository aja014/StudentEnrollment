#pragma once
#include <iostream>
#include "Coorxy.h"
#include "border.h"

#define gotoxy coorxy

using namespace std;

void hp2()
{
	lborder();

    int margin = 12;
    int topSpace = 5;
    gotoxy(margin, topSpace);
    cout << "ABOUT THE PROGRAM :";
    gotoxy(margin, topSpace + 1);
    cout << "About BSIT Student Enrollment Management System";
    gotoxy(margin, topSpace + 2);
    cout << "The BSIT Student Enrollment Management System is a system software solution designed to";
    gotoxy(margin, topSpace + 3);
    cout << "efficiently organize the enrollment process for Bachelor of Science in Information Technology";
    gotoxy(margin, topSpace + 4);
    cout << "(BSIT) students.";
    gotoxy(margin, topSpace + 6);
    cout << "BRIEF DESCRIPTION :";
    gotoxy(margin, topSpace + 7);
    cout << "With its intuitive interface and comprehensive functionality, this program offers a centralized";
    gotoxy(margin, topSpace + 8);
    cout << "hub for seamlessly managing student enrollment, facilitating course registrations, and";
    gotoxy(margin, topSpace + 9);
    cout << " facilitating administrative tasks efficiently.Designed to enhance productivity and accuracy,";
    gotoxy(margin, topSpace + 10);
    cout << "this system serves as an essential tool for academic institutions seeking to modernize ";
    gotoxy(margin, topSpace + 11);
    cout << "and elevate their enrollment management processes.";

    gotoxy(margin, topSpace + 13);
    cout << "Developed by : BSIT 1A - G1 (Group 1)";
    /*gotoxy(margin, topSpace + 14);
    cout << "Angeles, Aaron James";
    gotoxy(margin, topSpace + 15);
    cout << "Regalado, Martin Jeco";
    gotoxy(margin, topSpace + 16);
    cout << "Agustin, Jeffry";
    gotoxy(margin, topSpace + 17);
    cout << "Santos, Cedrick";
    gotoxy(margin, topSpace + 18);
    cout << "Torres, Adrian";*/
    gotoxy(margin, topSpace + 14);
    cout << "Date : April 01, 2024";
    gotoxy(margin, topSpace + 15);
    cout << "Code Version : 2.0";
    gotoxy(12, 26);
    cout << "- BSIT Student Enrollment Management System -";

	
    
}

void hp1()
{
	int margin = 12;
	int topSpace = 3;

	lborder();

	gotoxy(margin, topSpace);
	cout << "NAVIGATION:\n";
	gotoxy(margin, topSpace + 1);
	cout << "1. Use the arrow keys on your keyboard to navigate through the system contents.\n";
	gotoxy(margin, topSpace + 2);
	cout << "2. Use the \"Back\" button to return to the previous page or to the main menu.\n";
	gotoxy(margin, topSpace + 3);
	cout << "3. Use the \"Search Bar\" to locate a specific student pooling number and subjects.\n";
	gotoxy(margin, topSpace + 4);
	cout << "USER INPUTS:\n";
	gotoxy(margin, topSpace + 5);
	cout << "1. Input necessary information by using the appropriate keyboard keys.\n";
	gotoxy(margin, topSpace + 6);
	cout << "2. Use \"A-Z\" letters for information such as name, address, guardian name, etc.\n";
	gotoxy(margin, topSpace + 7);
	cout << "3. Use numbers for information such as age, contact number, etc.\n";
	gotoxy(margin, topSpace + 8);
	cout << "4. Press the \"Enter\" key on your keyboard to confirm inputs and register them in the database.\n";
	gotoxy(margin, topSpace + 9);
	cout << "5. The system will continuously prompt for information until all required fields are completed.\n";
	gotoxy(margin, topSpace + 10);
	cout << " * If any information is missing, the system will remain on the same page until the user fulfills\n";
	gotoxy(12, topSpace + 11);
	cout << "the necessary requirements.\n";
	gotoxy(margin, topSpace + 12);
	cout << "BUTTONS:\n";
	gotoxy(margin, topSpace + 13);
	cout << "1. Use the \"Add/Update\" button to insert or update a student information in the database.\n";
	gotoxy(margin, topSpace + 14);
	cout << "2. Use the \"Delete\" button to remove a student and subjects information from the database.\n";
	gotoxy(margin, topSpace + 15);
	cout << "3. Use the \"Back\" button to return to the previous page or to the main menu.\n";
	gotoxy(margin, topSpace + 16);
	cout << "4. Press the \"Enter\" key on your keyboard to confirm inputs and register them in the database.\n";
	gotoxy(margin, topSpace + 17);
	cout << "ADDITIONAL INFORMATION:\n";
	gotoxy(margin, topSpace + 18);
	cout << "1. The system employs strict validation checks to ensure data accuracy and integrity.\n";
	gotoxy(margin, topSpace + 19);
	cout << "2. Error messages will be displayed if incorrect inputs are provided, guiding users to correct any\n";
	gotoxy(margin, topSpace + 20);
	cout << "mistakes";
	gotoxy(margin, topSpace + 21);
	cout << "3. For further assistance or queries, contact our support team for prompt assistance.\n";
	gotoxy(12, 26);
	cout << "- BSIT Student Enrollment Management System -";

}
