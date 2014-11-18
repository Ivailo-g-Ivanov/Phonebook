// AbSimpleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
 #include <cstdlib>
#include <stdio.h>   
#include <fstream>
#include <string>
#include "Searching.cpp"
#include "GenRepAB.cpp"
#include "AddPhone.cpp"
#include "ViewEntries.cpp"
#include "AddEmail.cpp"
#include "GenDoBRep.cpp"
#include "DeleteEmail.cpp"

using namespace std;
Searching sr;
GenRepAB GRab;
AddPhone AP;
Viewing v;
AddEmail AE;
GenerateDoBRep GDoB;
DeleteEmail De;


class AddressBook{

public:


	void AddEntry();


	int MainMenu();

	struct Entry_Struct ///Defines empty struct
	{
		char firstName[15];
		char lastName[15];
		char birthday[15];
		string phone;
		char email[15];
	};

	Entry_Struct entries[100];
	unsigned int count;
};


void AddressBook::AddEntry()
{



	int number_of_lines = 0;
	string line;
	ifstream myfile("AddressBook.txt");
	while (getline(myfile, line)) ///Function to get number of lines
		++number_of_lines;
	cout << "Number of lines in text file: " << number_of_lines << endl;
	ofstream myout;
	myout.open("AddressBook.txt", ios::app);
	char add[50];
	fflush(stdin);
	cout << "Entry ID:  " << (number_of_lines + 1) << endl;
	myout << number_of_lines + 1 << " "; /// Using number of lines as ID for every line
	cout << "Enter First Name: ";
	cin >> entries[count].firstName;
	myout << "Name:" << entries[count].firstName << " ";
	cout << "Enter Last Name: ";
	cin >> entries[count].lastName;
	myout << entries[count].lastName << ",";
	cout << "Enter Date of Birth: ";
	cin >> entries[count].birthday;
	myout << "Date of birth: " << entries[count].birthday << ",";
k:cout << "Enter Phone Number.It must start with +359 : ";
	cin >> entries[count].phone;
	if (entries[count].phone.find("+359") != 0)
	{
		std::cout << "Invalid phone number" << endl;
		goto k;
	}
	else
		myout << "Phone: " << entries[count].phone << ",";
	cout << "Enter Email: ";
	cin >> entries[count].email;
	myout << "Email: " << entries[count].email << endl;

	++count; // +1to total entry count  

	myout.close();

}





AddressBook my_book; ///object to call functions from Class AddressBook

int MainMenu() ///Main Menu of the program
{
	int num;
	bool bQuit = false;


	while (bQuit == false)
	{

		cout << "+-------------------------------------+" << endl;
		cout << "|         Address Book Menu           |" << endl;
		cout << "|                                     |" << endl;
		cout << "| 1- Add an entry                     |" << endl;
		cout << "| 2- Search for text or field		   |" << endl;
		cout << "| 3- Write alphabetical report by name|" << endl;
		cout << "| 4- Add phone to entry               |" << endl;
		cout << "| 5- Add email to entry               |" << endl;
		cout << "| 6- Write report by date of birth    |" << endl;
		cout << "| 7- Delete Email of an entry         |" << endl;
		cout << "| 8- Exit                             |" << endl;
		cout << "+-------------------------------------+" << endl;

		cout << endl;
		cout << "Please enter a number for one of the above options: ";
		cin >> num;
		cout << endl;

		if (num == 1)
			my_book.AddEntry();
		else if (num == 2)
			sr.Search();
		else if (num == 3)
			GRab.GenerateRepAB();
		else if (num == 4)
		{
			v.ViewEnt();
			AP.AddPhoneTo();
		}
		else if (num == 5)
		{
			v.ViewEnt();
			AE.AddEm();
		}
		else if (num == 6)
		{
			GDoB.GenDoBRep();
		}
		else if (num == 7)
		{
			De.DeleteEm();
		}
		else if (num == 8)
			bQuit = false;
		else
			cout << "Invalid choice. Please try again" << endl;
		cout << endl;
	}

	return 0;
}

int main()
{

	MainMenu();
	return 0;
}