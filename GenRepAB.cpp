
// GeneratingReports.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


class GenRepAB
{
public:
	vector<string> names;
	string filename;

	void GenerateRepAB()
	{
		/// Empty vector holding all names from file

		cout << "Enter output file name: ";
		cin >> filename;
		filename = filename + ".txt";

		/// Read names from file AddressBook.txt
		ifstream in("AddressBook.txt");
		if (!in.is_open())
			cout << "Unable to open file\n";


		string word;
		while (getline(in, word))
			names.push_back(word);



		/// Loop to erase ID of lines otherwise it is impossible to be sorted
		for (size_t i = 0; i < names.size(); i++)

		{
			names[i].erase(names[i].begin());
		}


		sort(names.begin(), names.end()); ///Vector Sort

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

