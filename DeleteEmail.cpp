#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class DeleteEmail {
public:
	void DeleteEm(){
		/// Empty vector holding all names from file
		vector<string> names;


		/// Read names from file AddressBook.txt
		ifstream in("AddressBook.txt");
		if (!in.is_open())
			cout << "Unable to open file\n";


		string word;
		while (getline(in, word))
			names.push_back(word);
		int i;;
		cout << "Number of entry where you want to delete email: ";
		cin >> i;


		int indexEnd = 0;
		for (int k = 0; k < 3; ++k)
		{
			indexEnd = (names[i - 1].find(",", indexEnd));
		}


		int indexStart = 0;
		for (int k = 0; k < 3; ++k)
		{
			indexStart = (names[i - 1].find(",", indexStart)) + 1;
		}


		names[i - 1].erase(names[i - 1].begin() + indexStart + 7, names[i - 1].end());


		///Write to a file

		ofstream fout;
		fout.open("AddressBook.txt", ios::out);
		for (size_t i = 0; i < names.size(); i++)
		{
			fout << names[i] << '\n';

		}
		cout << "Email has been deleted to entry No: " << i << endl;
		in.close();
		fout.close();

	};
};