// ****************************************
// Program Title: Password Generator
// Project FIle: Project_04.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 01/31/20
// program description: Program generates password using combinations of character inputs.
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	// Program Header.
	cout << right << endl;
	cout << string(60,'*') << endl;
	cout << setw(40) << "Password Generator" << endl;
	cout << string(60, '*') << endl;
	
	string name, firstw, secondw, thirdw; // input variables.
	int firstw_len, secondw_len, thirdw_len, name_len;  
	
	// User Input Prompts.
	cout << "Enter user's first and last names separated by a space: ";
	getline(cin,name);		
	cout << endl << "name = " << name << endl << endl; // echo print.
	
	cout << "Enter the first word: ";
	cin >> firstw;
	cout << endl << "first word = " << firstw << endl << endl;
	
	cout << "Enter the second word: ";
	cin >> secondw;
	cout << endl << "second word = " << secondw << endl << endl;
	
	cout << "Enter the third word: ";
	cin >> thirdw;
	cout << endl << "third word = " << thirdw << endl << endl;
	
	
	firstw_len = firstw.length();
	secondw_len = secondw.length();
	thirdw_len = thirdw.length();
	name_len = name.length();
	
	// Output Table.
	cout << string(60,'*') << endl;
	cout << left;
	cout << setw(8) << "Word#" << setw(10) << "Length" << setw(20) << "Word" << endl;
	cout << setw(8) << "-----" << setw(10) << "------" << setw(20) << "----" << endl;
	cout << setw(8) << "1" << setw(10) << firstw_len << setw(20) << firstw << endl;
	cout << setw(8) << "2" << setw(10) << secondw_len << setw(20) << secondw << endl;
	cout << setw(8) << "3" << setw(10) << thirdw_len << setw(20) << thirdw << endl;
	cout << setw(8) << "-----" << setw(10) << "------" << setw(20) << "----" << endl << endl;
	
	// Calculate Average of word lengths, set to 2 decimal points.
	cout << fixed << showpoint << setprecision(2);
	float avgwdlen;
	avgwdlen = (firstw_len + secondw_len + thirdw_len) / 3.0;
	cout << setw(20) << "Average word length = " << avgwdlen << endl;
	
	int pos = name.find(" ");
	
	// Combining outputs to one Password string.
	cout << endl << "password = ";
	cout << name.substr(0,1) << name.substr(pos+1,1) << name_len;
	cout << firstw.substr(0,1) << firstw.substr(firstw_len -1) << firstw_len;
	cout << secondw.substr(0,1) << secondw.substr(secondw_len -1) << secondw_len;
	cout << thirdw.substr(0,1) << thirdw.substr( thirdw_len -1) << thirdw_len << endl;
	cout << string(60, '*') << endl << endl;
	
	
	return 0;
}
