#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
using std::ifstream;
int main() {
	string token;
	string x;
	ifstream fin;
	int count = 1;
	bool textonly = false;
	string dateSub[4000];
	string priceSub[4000];
	string savedLine[4000];
	int curLine = 0;
	fin.open("statement.csv");
	std::vector<string> tokens;
	if (!fin.is_open()) {
		cout << "File not opened";
	}
	string date = "";
	string dateWanted = "";
	string lineRead;

	while (date != "exit") {
		cout << "Welcome to Joel's Bank Explorer. Do not enter leading 0's in dates. Use 1/1/23 format NOT 01/01/23\n\nWhat would you like to search for?\n";
		cin >> date;
		cout << "***********Deposits***********\n";
		while (getline(fin, lineRead)) {

			savedLine[count++] = lineRead;
			if (lineRead.find(",-")==string::npos) cout << lineRead << endl; //print positive 


		}
		cout << "*******************************\n\n";
		int loc = 0;
		int firstLoc = 0;
		int digits = date.size();
		for (int x = 0; x < count; ++x) { //create array of dates
			dateSub[x] = savedLine[x].substr(0, digits);
			if (savedLine[x].find(date) != string::npos) {
				cout << savedLine[x] << endl; //print searched text 
				textonly = true;

			}
		}
		int totalCount = 0;
		cout << '\n';
		if (!textonly) { //only do if not searching for text
			for (int x = 0; x < count; ++x) {
				if (dateSub[x] == date) {
					cout << savedLine[x] << endl;
					++totalCount;
				}

			}
			cout << "\n\nThese are the " << totalCount << " transactions on " << date << ".\n";

		}
	}
	textonly = false;
	cin >> x;
	fin.close();



}