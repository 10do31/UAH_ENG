// ****************************************
// Program Title: I/O file commands Program.
// Project File: Project_05.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 02/07/20
// program description: Program perfoms input/output commands by reading files.
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <climits>

using namespace std;
int main(int argc, char *argv[])

{
	
	if (argc != 3)
	{
		cout << endl;
		cout << string(9,'*') << " Command Line Argument Error "
		     << string(9,'*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==> ./Project_05 inputFileName  outputFileName\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}
	
	// Declare I/O and command line variables.
	ifstream inFile;
	ofstream outFile;
	string inputf = argv[1];
	string outputf = argv[2];
	float a, b, c;
	
	cout << endl;
	// Opening the files to read from and to.
	cout << "Opening Input File: " << inputf << endl << endl;
	inFile.open(inputf.c_str());
	
	cout << "Opening Output File: " << outputf << endl << endl;
	outFile.open(outputf.c_str());
	
	// Tests for bad/fail, terminate program.
	if (inFile.fail())
	{
		cout << string(15,'*') << " File Open Error "
		 	 << string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << inputf << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}
	
	if (outFile.fail())
	{
		cout << string(15,'*') << " File Open Error "
		 	 << string(15,'*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outputf << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}
	
	inFile.ignore(INT_MAX,'A');
	inFile >> a;
	inFile.ignore(INT_MAX,'B');
	inFile >> b;
	inFile.ignore(INT_MAX,'C');
	inFile >> c;
	
	float totalsum;
	float avg;
	string avhigh, avmed, avlow;
	string fstA, secB, thdC;
	
	totalsum = a + b + c; 		// Sum of the values read.
	avg = totalsum/3.0;  		// Finding the average of the values.
	avhigh = "High";
	avmed = "Medium";
	avlow = "Low";
	fstA = "First number";
	secB = "Second number";
	thdC = "Third number";
	
	// Logical Expressions of if values read are less than 0.
	if (a<0||b<0||c<0)
	{
		cout << string(15,'*') << " Negative Number "
		 	 << string(15,'*') << endl;
		if (a<0)
			cout << "==> " << fstA << " is less than 0\n";
		if (b<0)
			cout << "==> " << secB << " is less than 0\n";
		if (c<0)
			cout << "==> " << thdC << " is less than 0\n";
		
		cout << "==> All numbers should be positive" << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl << endl;
		
		return 1;
	}
		
	else if (a>=0&&b>=0&&c>=0) 	// Logical expressions and outputs for values greater than 0.
	{
		cout << fixed << showpoint << setprecision(2);
		cout << string(47,'*') << endl;
		cout << left;
		cout << setw(35) << "The numbers read are: " << a << " " << b << " " << c << endl;
		cout << setw(35) << "The sum of the numbers is: " << totalsum << endl;
		cout << setw(35) << "The average of these numbers is: " << avg << endl;
		
		if (avg >= 75)
			cout << setw(35) << "This average is: " << avhigh << endl;
		if (avg<75 && avg>=25)
			cout << setw(35) << "This average is: " << avmed << endl;
		if (avg < 25)
			cout << setw(35) << "This average is: " << avlow << endl;
		
		cout << string(47,'*') << endl << endl;
		
	}	
	
	
	outFile.close();
	
	
	return 0;
}
