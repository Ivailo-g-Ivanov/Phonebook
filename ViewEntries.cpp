#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Viewing
{
public:

	void ViewEnt()
	{
		ifstream myfile;
		myfile.open("AddressBook.txt");
		cout << endl;
		if (myfile)
		{
			string line;
			while (getline(myfile, line))
				cout << line << endl;
		}
		myfile.close();
	};
};
