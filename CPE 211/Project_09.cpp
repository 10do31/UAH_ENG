// ****************************************
// Program Title: Array Computations.
// Project File: Project_09.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 04/10/20
// program description: Program will compute various Boolean Algebra results.
// Results for OR, AND and XOR of two 2-dimensional arrays of binary values.
// ****************************************
#include <iostream>
#include <cmath>
#include <climits>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <string>

using namespace std;

void GetinFile(ifstream&); 	//Function will open input file. 
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
typedef int BitArray[MAX_ROWS][MAX_COLS]; 	//Typedef for maximum # of rows and columns.
bool ReadData(ifstream&, int&, int&, BitArray, BitArray); 	//Function will read input file. 

void PrintinArrays(BitArray, BitArray, int, int);

struct ResultArrays //Structure holding data types for organization. 
{
	BitArray orArray;
	BitArray andArray;
	BitArray xorArray;
	int rows;
	int cols;
};

void Results(BitArray, BitArray, ResultArrays& ); 	//Function will compute Boolean operations. 
void decimvalues(int, int, ResultArrays);	// For decimal values. 
void PrintOutArrays(int, int, ResultArrays);

int main()
{
	BitArray array1;
	BitArray array2;
	ifstream inFile;
	string inputf;
	ResultArrays calcs;
	int rows, cols;
	
	
	cout << endl;
	
	GetinFile(inFile);
    	
	if(ReadData(inFile, rows, cols, array1, array2))
	{
		calcs.rows = rows;
		calcs.cols = cols;
		PrintinArrays(array1, array2, rows, cols);
		
		cout << endl;
		
		Results(array1, array2, calcs);
		PrintOutArrays(rows, cols, calcs);
		decimvalues(rows, cols, calcs);
	}
	
	else
	{
		cout << string(13,'*') << " Input File Is Empty " << string(13,'*') << endl;
    	cout << "==> The input file is empty.\n";
    	cout << "==> Terminating the program.\n";
    	cout << "==> This test is not required for students\n";
    	cout << string(47,'*') << endl << endl;
	}
	return 0;
}


void GetinFile(ifstream& inFile) // function definition to open file. 
{
	string inputf;
	
    cout << "Enter the name of the input file: ";
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
    	
    	cout << "Enter the name of the input file: ";
    	cin >> inputf;
    	inFile.open(inputf.c_str());
    	cout << inputf << endl << endl;	
    } 	
}

// Function definition to read arrays in file. 
bool ReadData(ifstream& inFile, int& rows, int& cols , BitArray array1, BitArray array2)
{
	int j, k;
	
	inFile >> rows;
	inFile.ignore(INT_MAX, '\n');
	
	//Empty file test.
	if(inFile.fail())
	{
		
    	
		return false;
	}
	
	inFile >> cols;
	
	inFile.ignore(INT_MAX, '\n');
	
	for (j = 0; j < rows; j++)
	{
		for (k = 0; k < cols; k++)
		{
			inFile >> array1[j][k];
		}
	}
	
	for (j = 0; j < rows; j++)
	{
		for (k = 0; k < cols; k++)
		{
			inFile >> array2[j][k];
		}
	}
	
	return true;
}

//Function definition to print array outputs.
void PrintinArrays(BitArray array1, BitArray array2, int rows, int cols)
{
	cout << "Initial values of the arrays processed" << endl;
	cout << string(38,'-') << endl;
	cout << setw(2*cols) << left << "Array 1"
	     << "    " << setw(2*cols) << "Array 2" << endl;
	     
	cout << setw(2*cols) << left << string(7,'-')
	     << "    " << setw(2*cols) << string(7,'-') << endl;
	
	int j, k;
	     
	for (j = 0; j < rows; j++)
	{
		for (k = 0; k < cols; k++)
		{
			cout << setw(2) << array1[j][k];
		}	
		cout << "    ";
		
		for (k = 0; k < cols; k++)
		{
			cout << setw(2) << array2[j][k];
		}
		cout<< endl;
	}
	
}

//Function definition for Boolean Calculations.
void Results(BitArray array1, BitArray array2, ResultArrays& calcs)
{
	int j, k, sumArr;
	
	//Boolean Operations
	for (j = 0; j < calcs.rows ; j++)
    {
    	for (k = 0; k < calcs.cols; k++)
        {
        	sumArr = array1[j][k] + array2[j][k];
        	
        	//Calculate Boolean OR
			if(sumArr == 0) 
			{
				calcs.orArray[j][k] = 0;
			}
				
			else if (sumArr == 1)
			{
				calcs.orArray[j][k]= 1;
			}
			
			else if(sumArr == 2)
			{
				calcs.orArray[j][k] = 1;
			}
		}
			
	}
			
	for (j = 0; j < calcs.rows ; j++)
    {
    	for (k = 0; k < calcs.cols; k++)
        {
        	sumArr = array1[j][k] + array2[j][k];		
			
			//Calculate Boolean AND	
			if(sumArr == 0) 
			{
				calcs.andArray[j][k] = 0;
			}
				
			else if (sumArr == 1)
			{
				calcs.andArray[j][k] = 0;
			}
			
			else if(sumArr == 2)
			{
				calcs.andArray[j][k] = 1;
			}
		}
	}
			
	for (j = 0; j < calcs.rows ; j++)
    {
    	for (k = 0; k < calcs.cols; k++)
        {
        	sumArr = array1[j][k] + array2[j][k];
        	
        	//Calculate Boolean XOR
			if(sumArr == 0) 
			{
				calcs.xorArray[j][k] = 0;
			}
				
			else if (sumArr == 1)
			{
				calcs.xorArray[j][k] = 1;
			}
			
			else if(sumArr == 2)
			{
				calcs.xorArray[j][k] = 0;
			}	
		}
	}	
}

//Function definition to print outputs for Boolean operations. 
void PrintOutArrays(int rows, int cols, ResultArrays calcs)
{
	//Headings for OR, AND, XOR outputs.
	cout << "OR, AND and XOR results" << endl;
	cout << string(23,'-') << endl;
	cout << setw(2*cols) << left << "OR"
	     << "    " << setw(2*cols) << "AND"
		 << "    " << setw(2*cols) << "XOR" << endl;
		 
	cout << setw(2*cols) << left << "--"
	     << "    " << setw(2*cols) << "---"
		 << "    " << setw(2*cols) << "---" << endl;
		 
	int j, k;	  
	//Print output arrays.
	for (j = 0; j < rows ; j++)
    {
    	for (k = 0; k < cols; k++)
        {
			cout << calcs.orArray[j][k] << " ";

		}
		
		cout << "    ";
		
		for(k = 0; k < cols; k++)
		{
			cout << calcs.andArray[j][k] << " ";

		}
		
		
		cout << "    ";
		
		for(k = 0; k < cols; k++)
		{
			cout << calcs.xorArray[j][k] << " ";

		}

		cout<<endl;
	}
}

//Function definition to calculate and output decimal equivalents of binary arrays. 
void decimvalues(int rows, int cols, ResultArrays calcs)
{
	cout << endl << endl;
	cout << "Integer Equivalents for the rows" << endl;
	cout << "of the OR, AND and XOR arrays" << endl;
	cout << string(32,'-') << endl;
	
	cout << left;
	cout << setw(8) << "OR" << setw(8) <<  "AND" << setw(8) << "XOR" << endl;
	cout << setw(8) << "--" << setw(8) << "---" << setw(8) << "---" << endl;
	
	int base = 1;
	int result = 0, result2 = 0, result3 = 0;
	int j,k;
	
	for (j = 0; j < rows ; j++)
	{
		result = 0, result2 = 0, result3 = 0;
		base = 1;
		
		for(k = cols - 1; k >= 0; k--)
		{
			result += base*calcs.orArray[j][k];
			base *= 2;
			
			
		}
		
		cout << setw(8) << result;
		base = 1;
		
		for(k = cols - 1; k >= 0; k--)
		{
			result2 += base*calcs.andArray[j][k];
			base *= 2;
			
		}
		
		cout << setw(8) << result2;
		base = 1;
		
		for(k = cols - 1; k >= 0; k--)
		{
			result3 += base*calcs.xorArray[j][k];
			base *= 2;
			
		}
		
		cout << setw(8) << result3 << endl;
	}
	
	
}
	


