#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <cctype>
//Declare variables

using namespace std;

void SaveLinesandPrintDeposits(int& count, std::string& lineRead, bool& firstTime);
void PrintResults(int x, std::string& date);
void SaveDates(int x, int digits);
void PrintIfDatesMatch(int count);
void OpenFile();
void AdjustSpacing(int count);

string MakeUpper(std::string& lineRead);

string token;
string x;
ifstream fin;

bool textonly = false;
string dateSub[4000];
string priceSub[4000];
string savedLine[4000];
int curLine = 0;
bool firstTime = true;
std::vector<string> tokens;
string date = "";
string dateWanted = "";
string lineRead;

void SaveLinesandPrintDeposits(int& count, std::string& lineRead, bool& firstTime)
{
	savedLine[count++] = lineRead;
	if (firstTime) {
		if (lineRead.find(",-") == string::npos) cout << lineRead << endl; //print positive 
	}
	firstTime = false;
}

void PrintResults(int x, std::string& date)
{
	if (date == "groceries") date = "Groceries";
	if (date == "clothing") date = "Clothing";
	if (date == "electronics") date = "Electronics";
	if (date == "restaurants") date = "Restaurants";
	if ((date == "gas") || (date == "gasoline" )) date = "Gasoline";
	if (date == "food") date = "Food";

	if (savedLine[x].find(date) != string::npos) {
		int amount = savedLine[x].rfind('-');
		char a = savedLine[x][amount + 1];
		char b = savedLine[x][amount + 2];
		char c = savedLine[x][amount + 3];
		char d = savedLine[x][amount + 4];
		char e = savedLine[x][amount + 5];
		int numLen = 0;
		if (b == '.') numLen = 1;
		else if (c == '.') numLen = 2;
		else if (d == '.') numLen = 3;
		else if (e == '.') numLen = 4;
		cout << savedLine[x]; //print searched text 
		if (amount == string::npos) cout << "+++++++";
		if (numLen >= 3) cout << "$$$$$$$";
		cout << endl;
		textonly = true;
	}
}

void SaveDates(int x, int digits)
{
	dateSub[x] = savedLine[x].substr(0, digits);
}

void PrintIfDatesMatch(int count)
{
	for (int x = 0; x < count; ++x) {
		if (dateSub[x] == date) {
			cout << savedLine[x] << endl;
		}
	}
}

void OpenFile()
{
	fin.open("testit.csv");
	if (!fin.is_open()) {
		cout << "File not opened";
	}
}

string MakeUpper(std::string& lineRead) {

	int length = lineRead.size();
	for (int ch = 0; ch < length; ++ch) {
		 lineRead[ch] = toupper(lineRead[ch]);		
	}
	return lineRead;
}

void AdjustSpacing(int count)
{
	for (int j = 0; j < count; ++j) {
		for (int i = 0; i < savedLine[j].size(); ++i) {
			if (savedLine[j][i] == ',') {
				savedLine[j][i] = ' ';
				savedLine[j].insert(i, 3, ' ');
			}
		}
	}
}


