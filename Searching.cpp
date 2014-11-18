#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Searching
{
public:



	void Search()
	{

		char nameForSearch[50];
		cout << "Enter text or name of the field you want to search: " << endl;
		fflush(stdin);
		cin.getline(nameForSearch, 50);

		char* search = nameForSearch; ///Search Pattern
		int offsetForSearch;
		string lineForSearch;
		ifstream Myfile;
		Myfile.open("AddressBook.txt");
		if (Myfile.is_open())
		{
			while (!Myfile.eof())
			{
				getline(Myfile, lineForSearch);
				if ((offsetForSearch = lineForSearch.find(search, 0)) != string::npos) // If fount
				{
					cout << lineForSearch << endl;
				}
			}
		}
		Myfile.close();
	}
};