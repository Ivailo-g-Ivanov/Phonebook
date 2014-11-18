#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class AddEmail {
public:
	void AddEm(){
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
		cout << "Number of entry where you want to add email: ";
		cin >> i;

		string input1, input2 = " ", input3 = " ";
		cout << "Write email address you want to add: ";
		cin >> input1;
		input2 = input2 + input1;
		input3 = input2 + input3;

		/// Loop to find position of field Email

		int index = 0;
		for (int k = 0; k < 3; ++k)
		{
			index = (names[i - 1].find(",", index)) + 1;
		}

		names[i - 1].insert(index + 7, input3);


		///Write to a file

		ofstream fout;
		fout.open("AddressBook.txt", ios::out);
		for (size_t i = 0; i < names.size(); i++)
		{
			fout << names[i] << '\n';

		}
		cout << "Email has been added to entry No: " << i << endl;
		in.close();
		fout.close();

	};
};