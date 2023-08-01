// ****************************************
// Program Title: Functions Program.
// Project File: Project 07
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 03/03/20
// Program description: Program performs various tasks through 
// various functions.
// ****************************************
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void fcn_pi();
void fcn_coin();
void fcn_dieroll();
void menu();
int get_int();
const int MENU1 = 1;
const int MENU2 = 2;
const int MENU3 = 3;
const int EXIT = 4;

int main()
{
	int choice, itr = 0, i;
	double x_coord, y_coord, pi, z, sumsqxy;
	int seed, count, heads, tails;
	char ch;
	
	// Setup the random number generator starting point by obtaining a seed
	cout << endl;
	cout << "Enter in the seed(integer > 0) for the random number generator: ";
	cin >> seed;
	cout << seed << endl << endl; // echo print out the value entered
	srand(seed); // use the seed entered to initialize the generator
	
	menu();
	choice = get_int();
	
	while (choice != 4)
	{
		if (choice == 1)
		{
			
			fcn_pi();
		}
	
		else if (choice == 2)
		{
			fcn_coin();	
		}
	
		else if (choice == 3)
		{
			fcn_dieroll();
		}
		
		else
		{
			cout << string(15,'*') << " Invalid Integer " << string(15,'*') << endl;
			cout << "==> Invalid integer entered.\n";
			cout << "==> Please try again...\n";
			cout << string(47,'*') << endl << endl;
		}	
		
		menu();
		choice = get_int();
	
	}
	
	cout << "Exit selected.  Exiting the program now..." << endl << endl;
		
	return 0;
}

void menu()
{
	// Print Menu for selection
	cout << string(26,'*') << endl;
	cout << string(6,'*') << " Menu Options " << string(6,'*') << endl;
	cout << string(26,'*') << endl;
	cout << MENU1 << ") Approximate PI\n";
	cout << MENU2 << ") Flip a fair coin\n";
	cout << MENU3 << ") Toss a fair 4-sided die\n";
	cout << EXIT << ") Exit\n"; 
	cout << string(26,'*') << endl << endl;
	cout << "Enter your choice: ";
}

int get_int()
{
	int choice;
	char ch;
	cin >> choice;
	
	while (cin.fail())
	{
		cin.clear();
		cin >> ch;
		cout << ch << endl << endl;
		cout << string(14,'*') << " Invalid Character " << string(14,'*') << endl;
		cout << "==> Invalid character(s) entered.\n";
		cout << "==> Please try again...\n";
		cout << string(47,'*') << endl << endl;
			
		menu();
		cin >> choice;
			
	}
	
	cout << choice << endl << endl; //Echo Print user choice.
	return choice;
}


void fcn_pi()
{					
	int itr, i;
	double count = 0, x_coord, y_coord, pi, z, sumsqxy;
	
	cout << "Monte Carlo Method for finding PI has been selected" << endl << endl;
	cout << "Number of iterations: ";
	cin >> itr;
	cout << itr << endl << endl;
						
	for (i = 0; i<itr; i++)
	{
		x_coord = double(rand())/double(RAND_MAX); // value is 0 to 1
		y_coord = double(rand())/double(RAND_MAX); // value is 0 to 1
		sumsqxy = pow(x_coord,2) + pow(y_coord,2);
		z = sqrt(sumsqxy);
							
		if (z<=1)
		{
			count++;
		}
								
	}
	pi = 4.0 * count/itr;
	cout << fixed << left << showpoint << setprecision(6);
	cout << string(10,'*') << " Option 1: Calculating PI " << string(10,'*') << endl;
	cout << "For " << itr << " iterations, pi is about " << pi << endl;
	cout << string(46,'*') << endl << endl;
}

void fcn_coin()
{
	int flips, i;
	double h_percent, t_percent;
	int heads = 0, tails = 0;
	
	cout << "Flipping of a fair coin has been selected" << endl << endl;
	cout << "How many flips of the coin? ";
	cin >> flips;
	cout << flips << endl << endl;
						
						
	for (i = 0; i < flips; i++)
	{
		double x = double(rand())/double(RAND_MAX); // value is 0 to 1
							
		if (x <= 0.5)
		{
			heads ++;
		}
		else if (x > 0.5)
		{
			tails ++;
		}
	
	}
	
	h_percent = heads * 100.0/flips; // Heads percentage
	t_percent = tails * 100.0/flips; // Tails percentage
	cout << fixed << left << showpoint << setprecision(4);
	cout << string(10,'*') << " Option 2: Flipping a Coin " << string(10,'*') << endl;
	cout << "For " << flips << " flips of a fair coin:\n";
	cout << "Heads percentage: " << h_percent << endl;
	cout << "Tails percentage: " << t_percent << endl;
	cout << string(47,'*') << endl << endl;
}
						
void fcn_dieroll()
{
	int toss, side1 = 0, side2 = 0, side3 = 0, side4 = 0;
	double sd1p, sd2p, sd3p, sd4p;
	
	cout << "Tossing of a fair 4-sided die has been selected" << endl << endl;
	cout << "How many times do you want to roll the die? ";
	cin >> toss;
	cout << toss << endl << endl;
	
	for (int i = 0; i < toss; i++)
	{
		double rndm = double(rand())/double(RAND_MAX); // value is 0 to 1
		
		if (rndm < 0.25)
		{
			side1 ++;
		}
		else if (rndm >= 0.25 && rndm < 0.5)
		{
			side2 ++;
		}
		else if (rndm >= 0.5 && rndm < 0.75)
		{
			side3 ++;
		}
		else if (rndm >= 0.75)
		{
			side4 ++;
		}

	}

	sd1p = (side1 * 100.0)/toss; // Side 1 percentage
	sd2p = (side2 * 100.0)/toss; // Side 2 percentage
	sd3p = (side3 * 100.0)/toss; // Side 3 percentage
	sd4p = (side4 * 100.0)/toss; // Side 4 percentage
	
	cout << fixed << left << showpoint << setprecision(4);
	cout << string(10,'*') << " Option 3: Tossing a Die " << string(10,'*') << endl;
	cout << "For " << toss << " rolls of a fair die:\n";
	cout << "Side 1 percentage: " << sd1p << endl;
	cout << "Side 2 percentage: " << sd2p << endl;
	cout << "Side 3 percentage: " << sd3p << endl;
	cout << "Side 4 percentage: " << sd4p << endl;
	cout << string(45,'*') << endl << endl;

}
							
							
						
						
						
							
						

