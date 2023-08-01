// ****************************************
// Program Title: Sample header file
// Project File: Project 11.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 04/24/20
// program description: Program reads and counts characters.
// Program will read from input file and count the number of letters, numbers and characters.
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
	ifstream inFile;
	string inputf, line;
	char ch;
	int linetotal, sumtotal;
	int uppers, lowers, spaces, puncts, nums, otherchrs;
	float pcnthigh, pcntlow, pcntspace, pcntpunct, pcntnum, pcntchrs;
	
	
	cout << endl << "Enter in the name of the input file: ";
    cin >> inputf;
    inFile.open(inputf.c_str());
    cout << inputf << endl << endl;
    
    
	while (inFile.fail())   	//Test for wrong filename.
    {
    	inFile.clear();
    	cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
    	cout << "==> Input file failed to open properly!!\n";
    	cout << "==> Attempted to open file: " << inputf << endl;
    	cout << "==> Please try again...\n";
    	cout << string(47,'*') << endl << endl;
    	
    	cout << "Enter in the name of the input file: ";
    	cin >> inputf;
    	inFile.open(inputf.c_str());
    	cout << inputf << endl << endl;	
    }
    
    inFile.get(ch); // priming read.
    
     
	if(inFile.eof())
	{
		cout << string(13,'*') << " Input File Is Empty " << string(13,'*') << endl;
    	cout << "==> The input file is empty.\n";
    	cout << "==> Terminating the program.\n";
    	cout << string(47,'*') << endl << endl;
    	
    	return 1;
	}
	
	
	linetotal = 0;
	
	int sumuppers = 0; 
	int sumlowers = 0; 
	int sumspaces = 0;
	int sumpuncts = 0; 
	int sumnums = 0; 
	int sumotherchrs = 0;
	int totals;
	
	cout << left;
	
	cout << setw(15) << "Line number" << setw(10) << "Upper"
	     << setw(10) << "Lower" << setw(10) << "Digits"
	     << setw(10) << "Punct" << setw(10) << "Spaces"
	     << setw(10) << "Other" << "Total" << endl;
	
	cout << setw(15) << string(11,'-') << setw(10) << string(5,'-')
	     << setw(10) << string(5,'-') << setw(10) << string(6,'-')
	     << setw(10) << string(5,'-') << setw(10) << string(6,'-')
	     << setw(10) << string(5,'-') << string(5,'-') << endl;
	     
	
	
    while(inFile.good())
	{
		linetotal++;
		
		uppers = 0; 
		lowers = 0; 
		spaces = 0;
		puncts = 0; 
		nums = 0; 
		otherchrs = 0;
		
		while(ch != '\n')
		{
			if(isupper(ch))
			{
				uppers++;
				
			}
				
			else if (islower(ch))
			{
				lowers++;
			} 
             
        	else if (isdigit(ch))
        	{
        		nums++;
			}	
				
			else if(isspace(ch))
			{
				spaces++;
			}
				
			else if(ispunct(ch))
			{
				puncts++;
			}
             
        	else
        	{
        		otherchrs++;
			}
		
			inFile.get(ch);
				
		}
		
		inFile.get(ch);
		
		otherchrs++;
		sumuppers += uppers;
		sumlowers += lowers;
		sumnums += nums;
		sumspaces += spaces;
		sumpuncts += puncts;
		sumotherchrs += otherchrs;
		
		sumtotal = uppers+lowers+spaces+puncts+nums+otherchrs;
		
		cout << setw(15) << linetotal << setw(10) << uppers
	         << setw(10) << lowers << setw(10) << nums
	         << setw(10) << puncts << setw(10) << spaces
	         << setw(10) << otherchrs << sumtotal << endl;
	     
	}
	
	totals = sumuppers+sumlowers+sumspaces+sumnums+sumpuncts+sumotherchrs;
	
	
	      
	cout << string(80,'-') << endl;
	       	
	cout << setw(15) << "Totals" << setw(10) << sumuppers
		 << setw(10) << sumlowers << setw(10) << sumnums
	     << setw(10) << sumpuncts << setw(10) << sumspaces
	     << setw(10) << sumotherchrs << totals << endl;
	     
	     
	     
	pcnthigh = sumuppers * 100.0/ totals;
	pcntlow = sumlowers * 100.0/ totals;
	pcntspace = sumspaces * 100.0/ totals;
	pcntpunct = sumpuncts * 100.0/ totals;
	pcntnum = sumnums * 100.0/ totals;
	pcntchrs = sumotherchrs * 100.0/ totals;
	     
	     
	cout << fixed << showpoint << setprecision(2);
	cout << setw(15) << "Percent" << setw(10) << pcnthigh
		 << setw(10) << pcntlow << setw(10) << pcntnum
	     << setw(10) << pcntpunct << setw(10) << pcntspace
	     << setw(10) << pcntchrs << endl << endl;
	     
	     
	
		
	return 0;
}


