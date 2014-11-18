// GenReportBday.cpp : Defines the entry point for the console application.
//


// GeneratingReports.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

class GenerateDoBRep
{
public:

	void GenDoBRep()
	{
		/// Empty vector holding all names from file
		vector<string> names;
		string filename;
		cout << "Enter output file name: ";
		cin >> filename;
		filename = filename + ".txt";

		/// Read names from file AddressBook.txt
		ifstream in("AddressBook.txt");
		if (!in.is_open())
			cout << "Unable to open file\n";


		string word;
		while (getline(in, word))
			names.push_back(word); ///Write lines to a vector

		// Divide every line into two - before and after the first comma
		//Then concat two strings in reverse order so Date of Birth will be the first field
		size_t found;
		for (size_t i = 0; i < names.size(); i++)
		{
			if ((found = names[i].find(",")) != string::npos)
			{

				names[i] = names[i].substr(found + 1, string::npos) + names[i].substr(0, found) + "\n";

			}
		}

		sort(names.begin(), names.end()); // Vector sort








		ofstream fout;
		fout.open(filename.c_str(), ios::out);

		for (size_t i = 0; i < names.size(); i++)
		{
			fout << names[i] << '\n';

		}

		cout << "New Report has been created!" << endl;
		in.close();
		fout.close();

	};
};


