// ****************************************
// Program Title: Test Score Statistics.
// Project File: Project_06.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 02/18/20
// program description: Program reads test scores from input files.
// Program calculates and outputs average, variance and std dev based on scores.
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <climits>
#include <cmath>
#include <cstdlib>

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
		cout << "==> ./Project_06 inputFileName  outputFileName\n";
		cout << string(47,'*') << endl << endl;
		
		return 1;
	}

	// Declare I/O and command line variables.
	ifstream inFile;
	ofstream outFile;
	string inputf = argv[1];
	string outputf = argv[2];
	int a, b, c, d;
	string line, grdA = "A", grdB = "B", grdC = "C", grdD = "D";
	float avg, totalsum, var, sumsqrs, stdev, nums=4.0;
	string letter = "Letter grade equivalent: ";
	
	cout << endl;
	
	// Opening the files to read from and to.
	cout << "Opening input file: " << inputf << endl << endl;
	inFile.open(inputf.c_str());
	
	// Tests for bad/fail.
	while (inFile.fail())
	{
		inFile.clear();
		cout << string(15,'*') << " File Open Error "
		 	 << string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << inputf << endl;
		cout << "==> Try Again\n";
		cout << string(47,'*') << endl << endl;
		
		cout << "Enter in the name of the input file: ";
		cin >> inputf;
		inFile.open(inputf.c_str());
		cout << inputf << endl << endl;
			
	}  
	
	inFile.ignore(INT_MAX, '\n');
	inFile >> a >> b >> c >> d;
	inFile.ignore(INT_MAX,'\n');
	getline(inFile, line,'\n');
	
	
	outFile.open(outputf.c_str());
	cout << "Opening output file: " << outputf << endl << endl;
	
	while (outFile.fail())
	{
		cout << string(15,'*') << " File Open Error "
		 	 << string(15,'*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outputf << endl;
		cout << "==> Try Again\n";
		cout << string(47,'*') << endl << endl;
		
		cout << "Enter in the name of the output file: ";
		cin >> outputf;
		outFile.open(outputf.c_str());
		cout << outputf << endl << endl;
			
	}  
	
	while (!inFile)
	{
		if (!a||!b||!c||!d)
		{	
			cout << string(15,'*') << " File Read Error "
		 	 	 << string(15,'*') << endl;
			cout << "==> Reading of the 4 test scores failed.\n";
			cout << "==> The input stream is in the fail state mode.\n";
			cout << "==> There is an error in the input file.\n";
			cout << "==> Program Terminated.\n";
			cout << string(47,'*') << endl;
			
			outFile << string(15,'*') << " File Read Error "
		 	 	    << string(15,'*') << endl;
			outFile << "==> Reading of the 4 test scores failed.\n";
			outFile << "==> The input stream is in the fail state mode.\n";
			outFile << "==> There is an error in the input file.\n";
			outFile << "==> Program Terminated.\n";
			outFile << string(47,'*') << endl;
			
			return 1;
		}	
		else if (!getline(inFile, line,'\n'))
		{
			cout << string(15,'*') << " File Read Error "
		 	     << string(15,'*') << endl;
			cout << "==> Reading of the information line failed.\n";
			cout << "==> The input stream is in the fail state mode.\n";
			cout << "==> There is an error in the input file.\n";
			cout << "==> Program Terminated.\n";
			cout << string(47,'*') << endl;
			
			outFile << string(15,'*') << " File Read Error "
		 	     << string(15,'*') << endl;
			outFile << "==> Reading of the information line failed.\n";
			outFile << "==> The input stream is in the fail state mode.\n";
			outFile << "==> There is an error in the input file.\n";
			outFile << "==> Program Terminated.\n";
			outFile << string(47,'*') << endl;
		
			return 1;
		}
	}
	
	if (a<0||b<0||c<0||d<0)
	{
		cout << string(15,'*') << " File Read Error "
		 	 << string(15,'*') << endl;
		cout << "==> Test scores read are: " << left << setw(6) << a << setw(6) << b << setw(6) << c << setw(6) << d << endl;
		cout << "==> One or more of the scores is negative!\n";
		cout << "==> Program Terminated.\n";
		cout << string(47,'*') << endl;
			
		outFile << string(15,'*') << " File Read Error "
		 	 	<< string(15,'*') << endl;
		outFile << "==> Test scores read are: "<< left << setw(6) << a << setw(6) << b << setw(6) << c << setw(6) << d << endl;
		outFile << "==> One or more of the scores is negative!\n";
		outFile << "==> Program Terminated.\n";
		outFile << string(47,'*') << endl;
		
		return 1;
	}
	
	totalsum = a + b + c + d;
	avg = totalsum / nums;
	sumsqrs = pow((a-avg),2)+pow((b-avg),2)+pow((c-avg),2)+pow((d-avg),2);
	var = sumsqrs/nums;
	stdev = sqrt(var);
	
	if (a>=0 && b>=0 && c>=0 && d>=0)
	{
		outFile << fixed << showpoint << setprecision(2);
		outFile << left;
		outFile << string(17,'*') << "   Statistics   "
			    << string(17,'*') << endl;
		outFile << setw(32) << line << setw(6) << a << setw(6) << b << setw(6) << c << setw(6) << d << endl;
		outFile << setw(32) << "The sum of the scores is: " << totalsum << endl;
		outFile << setw(32) << "The average of the scores is: " << avg << endl;
		if (avg >= 90)
			outFile << setw(32) << letter << grdA << endl;
		if (avg >= 80 && avg < 90)
			outFile << setw(32) << letter << grdB << endl;
		if (avg >= 70 && avg < 80)
			outFile << setw(32) << letter << grdC << endl;
		if (avg >= 60 && avg < 70)
			outFile << setw(32) << letter << grdD << endl;
		if (avg < 60)
			outFile << setw(32) << letter << "F" << endl;	
		outFile << setw(32) << "The variance of the scores is: " << var << endl;
		outFile << setw(32) << "The standard deviation is: " << stdev << endl;	
		outFile << string(50,'*') << endl;	
		
	}		 		
	
	inFile.close();
	outFile.close();
	
	return 0;
	
}
