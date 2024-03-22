#pragma once
#include <iostream>
#include <windows.h> 
#include "Coorxy.h"

#define gotoxy coorxy

using namespace std;

void hp() {

    int margin = 6;
    int topSpace = 2;

    system("cls");

    gotoxy(margin, topSpace);
    cout << "NAVIGATION:\n";
    gotoxy(margin, topSpace + 1);
    cout << "1. Use the arrow keys on your keyboard to navigate through the system contents.\n";
    gotoxy(margin, topSpace + 2);
    cout << "2. Use the \"Back\" button to return to the previous page.\n";
    gotoxy(margin, topSpace + 3);
    cout << "3. Use the \"Search Bar\" to locate a specific student pooling number.\n";
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
    cout << "   If any information is missing, the system will remain on the same page until the user fulfills\n";
    gotoxy(8, topSpace + 11);
    cout << "the necessary requirements.\n";
    gotoxy(margin, topSpace + 12);
    cout << "BUTTONS:\n";
    gotoxy(margin, topSpace + 13);
    cout << "1. Use the \"Add/Update\" button to insert or update a student information in the database.\n";
    gotoxy(margin, topSpace + 14);
    cout << "2. Use the \"Delete\" button to remove a student information from the database.\n";
    gotoxy(margin, topSpace + 15);
    cout << "3. Use the \"Back\" button to return to the previous page.\n";
    gotoxy(margin, topSpace + 16);
    cout << "4. Press the \"Enter\" key on your keyboard to confirm inputs and register them in the database.\n";
    gotoxy(margin, topSpace + 17);
    cout << "ADDITIONAL INFORMATION:\n";
    gotoxy(margin, topSpace + 18);
    cout << "1. The system employs strict validation checks to ensure data accuracy and integrity.\n";
    gotoxy(margin, topSpace + 19);
    cout << "2. Error messages will be displayed if incorrect inputs are provided, guiding users to correct any mistakes.\n";
    gotoxy(margin, topSpace + 20);
    cout << "3. For further assistance or queries, contact our support team for prompt assistance.\n";
    coorxy(60, 26); cout << "- BSIT Student Enrollment Management System -";

    coorxy(6, 26); system("pause");
    system("cls");

}
