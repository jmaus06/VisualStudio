#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "bankingHeader.h"
#include "main.h"

using namespace std;
using std::ifstream;
int main() {
	
	int count = 1;
	OpenFile();
	
	while (date != "exit" && date != "EXIT") {
		cout << "Welcome to Joel's Bank Explorer. Do not enter leading 0's in dates. Use 1/1/23 format NOT 01/01/23\n\nWhat would you like to search for?\n";
		cin >> date;
		if (firstTime) cout << "***********Deposits***********\n";
		while (getline(fin, lineRead)) SaveLinesandPrintDeposits(count, lineRead, firstTime);
		cout << "*******************************\n\n";
		int loc = 0;
		int firstLoc = 0;
		
		AdjustSpacing(count); //make line more readable

		int digits = date.size();
		for (int x = 0; x < count; ++x) {              //Normal test
			SaveDates(x, digits);			
			PrintResults(x, date);	
		}
		string dateUpper = MakeUpper(date);
		for (int x = 0; x < count; ++x) {              //UPPERCASE test			
			PrintResults(x, dateUpper);
		}
		
		cout << '\n';
		
		if (!textonly) {
			PrintIfDatesMatch(count);
		}
	}
	textonly = false;
	fin.close();
}







