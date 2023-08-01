// ****************************************
// Program Title: Sample header file
// Project File: Project_08.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 03/13/20
// program description: Program compresses/decompresses files.
// Program will read files and either compress or decompress based on user selection.
// ****************************************
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <climits>

using namespace std;

void menu();
void compress(ifstream&, ofstream& );
void decompress(ifstream&, ofstream& );
bool GetInFile(ifstream&, string&);
bool GetOutFile(ofstream& );
int get_int();

const int MENU1 = 0;
const int MENU2 = 1;
const int MENU3 = 2;

int main()
{
	ifstream inFile;
	ofstream outFile;
	string inputf, outputf;
	int select;
	
	cout<< endl;
	menu();
	select = get_int();
	
	while (select != 0)
	{
		if (select == 1||select == 2)
		{
			GetInFile(inFile, inputf);
			
			if (inFile.fail())   	//Test for empty file.
    		{
    			inFile.clear();
    			cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
    			cout << "==> Input file failed to open properly!!\n";
    			cout << "==> Attempted to open file: " << inputf << endl;
    			cout << "==> Selected operation has been canceled\n";
    			cout << string(47,'*') << endl << endl;
    	
    		}
		
    		else if (select == 1)
			{
				GetOutFile(outFile);
				compress(inFile, outFile);
			}	
		
			else if (select == 2)
			{
				GetOutFile(outFile);
				decompress(inFile, outFile);		
			}
		}
			
		else
		{
			cout << string(14,'*') << " Invalid Selection " << string(14,'*') << endl;
			cout << "==> Invalid integer value entered\n";
			cout << "==> Please enter 0, 1 or 2\n";
			cout << string(47,'*') << endl << endl;
		}
		
		inFile.clear();
		outFile.clear();
		
		inFile.close();
		outFile.close();
		
		menu();
		select = get_int();
	
	}
	
	cout << "Quit selected.  Terminating program now..." << endl << endl;
	
	return 0;
}

void menu()
{
	// Print Menu for selection
	cout << string(10,'*') << "  Compression Menu  " << string(10,'*') << endl;
	cout << MENU1 << ". Exit Program\n";
	cout << MENU2 << ". Compress File\n";
	cout << MENU3 << ". Decompress File\n";
	cout << string(40,'*') << endl << endl;
	cout << "Input your selection now: ";
}

int get_int()
{
	int select;
	char ch;
	cin >> select;
	
	while (cin.fail())
	{
		cin.clear();
		cin >> ch;
		cout << ch << endl << endl;
		cout << string(14,'*') << " Invalid Selection " << string(14,'*') << endl;
		cout << "==> Invalid character entered!!\n";
		cout << "==> Please enter 0, 1 or 2\n";
		cout << string(47,'*') << endl << endl;
			
		menu();
		cin >> select;
			
	}
	
	cout << select << endl << endl; //Echo Print user choice.
	return select;
}

bool GetInFile(ifstream& inFile, string& inputf) // function definition
{
	
    cout << "Enter the name of the input file: ";
    cin >> inputf;
    inFile.open(inputf.c_str());
    cout << inputf << endl << endl;
    	
	return true; 
}

bool GetOutFile(ofstream& outFile) // function definition
{
	string outputf;

    cout << "Enter the name of the output file: ";
    cin >> outputf;
    outFile.open(outputf.c_str());
    cout << outputf << endl;
  
}

void compress(ifstream& inFile, ofstream& outFile)
{
	char ch1;
	char ch2;
	int count = 0;
	
	inFile.get(ch1);
	
	if(inFile.good())
	{
		count += 1;
	}
	
	else   		//error message for empty file
	{
		cout << endl << string(15,'*') << " Empty Input File " << string(14,'*') << endl;
		cout << "==> Empty file for Compression\n";
		cout << "==> Nothing written to the output file\n";
		cout << string(47,'*') << endl << endl;
		return;
	}
	
	inFile.get(ch2);
	
	while(inFile.good())
	{
		if(ch1 == ch2)
		{
			count += 1;
		}
		
		else
		{
			outFile << count << ch1;
			count = 1;
		}
		
	ch1 = ch2;
	inFile.get(ch2);
	
	}
	
	outFile << count << ch1;
	cout << endl << "==> File has been Compressed" << endl << endl;
	
}


void decompress(ifstream& inFile, ofstream& outFile)
{
	char decom_ch;
	int decom_ch2;
	
	inFile >> decom_ch2;
	inFile.get(decom_ch);
	
	if(inFile.eof())
	{
		cout << endl << string(15,'*') << " Empty Input File " << string(14,'*') << endl;
		cout << "==> Empty file for Decompression\n";
		cout << "==> Nothing written to the output file\n";
		cout << string(47,'*') << endl << endl;
		return;
	}
	
	while(inFile.good())
	{
		while(decom_ch2 > 0)
		{
			outFile << decom_ch;
			decom_ch2 --;
		}
		
		inFile >> decom_ch2;
		inFile.get(decom_ch);
	}
	
	cout << endl << "==> File has been Decompressed" << endl << endl;
}
