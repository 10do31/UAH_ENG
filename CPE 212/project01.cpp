// Dan Otieno.
// CPE212-01.
// Project_01.
// Program will read image stored in arrays and perform various functions
	//as defined in project1.cpp and main.cpp files.
	
 
#include <iostream>
#include <fstream>
#include <string>

void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS])
{
	ifstream inputs;
	int i, j;
	string line;
	
	inputs.open(imagefile.c_str()); //open input file.
	
	getline(inputs, line);	//Read lines, get characters.
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			inputs >> image[i][j]; // store characters into arrays. 
		}
	}
}


void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
	int i, j;
	int h_image[MAXROWS][MAXCOLS]; //Array to hold flipped characters.
	int col; 
	
	col = MAXCOLS - 1; //decrease columns by 1 as we get character by character.
	
	for(i = 0; i < MAXCOLS; i++)
	{
		for(j = 0; j < MAXROWS; j++)
		{
			h_image[j][i] = image[j][col]; //Switch and Replace image column characters.
		}
		col --;
	}
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			image[i][j] = h_image[i][j]; //values from flipped array stored into
		}									//original array.
	}
	
	
}


void FlipVertical(int image[MAXROWS][MAXCOLS])
{
	int i, j;
	int v_image[MAXROWS][MAXCOLS];
	int row;
	
	row = MAXROWS - 1;
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			v_image[i][j] = image[row][j];
		}
		row --;
	}
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			image[i][j] = v_image[i][j];
		}
	}
}


void RotateCW(int image[MAXROWS][MAXCOLS])
{
	int i, j;
	int cw_image[MAXROWS][MAXCOLS];
	
	for(i = 0; i < MAXCOLS; i++)
	{
		for(j = 0; j < MAXROWS; j++)
		{
			cw_image[i][j] = image[MAXROWS-1-j][i];
		}
	}
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			image[i][j] = cw_image[i][j];
		}
	}
	
}


void RotateCCW(int image[MAXROWS][MAXCOLS])
{
	int ccw_image[MAXROWS][MAXCOLS];
	int i, j;
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			ccw_image[j][i] = image[i][MAXCOLS-1-j];
		}
	}
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			image[i][j] = ccw_image[i][j];
		}
	}
}


void Transpose(int image[MAXROWS][MAXCOLS])
{
	int i, j;
	int transp_image[MAXROWS][MAXCOLS];
	
	//Transpose image.
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			transp_image[i][j] = image[j][i];
		}
	}
	
	for(i = 0; i < MAXROWS; i++)
	{
		for(j = 0; j < MAXCOLS; j++)
		{
			image[i][j] = transp_image[i][j];
		}
	}
	
}


