/* NameComparison
*  Carter McCall
*  11 October 2022
*  Purpose:
*		Create a program that can read in names from files and compare them to see if any are the same
*  Modified 13 October 2022:
*		Fixed issue where sorting algorithm sorted lists upside down
*  Modified 14 October 2022:
*		Added ability to compare a custom input by the user
*  Modified 18 October 2022:
*		Changed colors and made a better interface
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
#include "Colors.h"

bool comp = false, check = false;
vector<string> boys, girls, same;

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

void compare(vector<string> a, vector<string> b) {
	string temp;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size() - 1; j++) {
			if (a[i] == b[j]) {
				same.push_back(a[i]);
			}
		}
	}
}

void compareBoys(string a, vector<string> b) {
	if (a != "END") {
		for (int j = 0; j < b.size(); j++) {
			if (a == b[j]) {
				comp = true;
			}
		}
	}
}

void compareGirls(string a, vector<string> b) {
	if (a != "END")
	{
		for (int j = 0; j < b.size(); j++) {
			if (a == b[j]) {
				if (comp == true) {
					cout << ANSI_COLOR_CYAN << a << " is a popular girls and boys name!" << endl;
				}
				else if (comp == false) {
					cout << ANSI_COLOR_MAGENTA << a << " is a popular girls name!" << endl;
				}
				check = true;
				break;
			}
		}
		if (comp == true && check == false) {
			cout << ANSI_COLOR_BLUE << a <<" is a popular boys name!" << endl;
		}
		else if (comp == false && check == false) {
			cout << ANSI_COLOR_WHITE << a <<" is not a popular name!" << endl;
		}
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
	sortVector(girls);
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
	sortVector(boys);
	compare(boys, girls);
	for (string nm : same) cout << ANSI_COLOR_GREEN << nm << " is a popular girls and boys name!" << endl;
	ANSI_COLOR_RESET;
	do {
		cout << ANSI_COLOR_YELLOW << "\nWhich name would you like to compare? Press END to leave the program: "
			<< ANSI_COLOR_GREEN;
		getline(cin, input);
		if (input != "END") {
			cout << "\n";
			compareBoys(input, boys);
			compareGirls(input, girls);
			input = "";
			comp = false;
			check = false;
		}
	} while (input != "END");
	cout << ANSI_COLOR_WHITE;
}