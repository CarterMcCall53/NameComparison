/* NameComparison
*  Carter McCall
*  11 October 2022
*  Purpose:
*		Create a program that can read in names from files and compare them to see if any are the same
*  Modified 13 October 2022:
*		Fixed issue where sorting algorithm sorted lists upside down
*  Modified 14 October 2022:
*		Added ability to compare a custom input by the user
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
#include "Colors.h"

bool comp = false, check = false;
vector<string> boys, girls;

void sortVector(vector<string>& vec) {
	string temp;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size() - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

void compareBoys(string a, vector<string> b) {
	for (int j = 0; j < b.size(); j++) {
		if (a == b[j]) {
			comp = true;
		}
	}
}

void compareGirls(string a, vector<string> b) {
	for (int j = 0; j < b.size(); j++) {
		if (a == b[j]) {
			if (comp == true) {
				cout << a << " is a popular girls and boys name!" << endl;
			}
			else if (comp == false) {
				cout << a << " is a popular girls name!" << endl;
			}
			check = true;
			break;
		}
	}
	if (comp == true && check == false) {
		cout << a << " is a popular boys name!" << endl;
	}
	else if (comp == false && check == false) {
		cout << a << " is not a popular name!" << endl;
	} 
	
}

int main() {
	char repChar;
	ifstream namesIn;
	string girlsFile = "GirlNames.txt", boysFile = "BoyNames.txt", name, input, inputChar;
	namesIn.open(girlsFile);
	if (!namesIn) cout << "Problem reading girls file" << endl;
	else
	{
		while (namesIn >> name)
		{
			girls.push_back(name);
		}
	}
	namesIn.close();
	cout << ANSI_COLOR_MAGENTA << "\n*Unsorted Girls*\n" << ANSI_COLOR_RESET << endl;
	for (string nm : girls) cout << nm << endl;
	cout << ANSI_COLOR_MAGENTA << "\n**Sorted Girls**\n" << ANSI_COLOR_RESET << endl;
	sortVector(girls);
	for (string nm : girls) cout << nm << endl;
	namesIn.open(boysFile);
	if (!namesIn) cout << "Problem reading boys file" << endl;
	else
	{
		while (namesIn >> name)
		{
			boys.push_back(name);
		}
	}
	namesIn.close();
	cout << ANSI_COLOR_BLUE << "\n**Unsorted Boys**\n" << ANSI_COLOR_RESET << endl;
	for (string nm : boys) cout << nm << endl;
	cout << ANSI_COLOR_BLUE << "\n**Sorted Boys**\n" << ANSI_COLOR_RESET << endl;
	sortVector(boys);
	for (string nm : boys) cout << nm << endl;
	do {
		cout << "\nWhich name would you like to compare?" << endl;
		cin >> input;
		cout << "\n";
		compareBoys(input, boys);
		compareGirls(input, girls);
		input = "";
		comp = false;
		check = false;
		do {
			cout << "Do you want to compare another name? (Y|N): ";
			cin >> inputChar;
			repChar = tolower(inputChar[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
}