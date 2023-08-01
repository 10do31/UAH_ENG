// ****************************************
// Program Title: Stock calculations.
// Project FIle: Project_03.cpp
// Name: Dan Otieno
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 01/24/20
// program description: Company stock value Calculator.
// Program performs calculations involving purchase and sale of stock.
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	
	cout<< endl << string(25,'*')<< endl;
	cout<< "Stock Calculations" << endl; // Program Header
	cout<< string(25,'*')<< endl << endl;
	
	string stock;						// Stock name.
	int shares;							// Number of shares.
	float shareprice;					// Price per share. 
	float sellprice;					// Sell price per share.
	float purch_comm;
	float total_purch;
	float sell_comm;
	float total_sell;
	float prof_loss;
	float tax;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the name of the stock: ";
	cin >> stock;					// Reads the name of stock entered.
	cout << stock << endl;			// Echo print.
	cout << "Enter the number of shares purchased: ";
	cin >> shares;					// Provides number of shares bought.
	cout << shares << endl;	
	cout << "Enter the buy price per share: ";
	cin >> shareprice;				// Price per share.
	cout << shareprice << endl;
	cout << "Enter the sell price per share: ";	
	cin >> sellprice;				// Sell price per share.
	cout << sellprice << endl << endl;

	purch_comm = 2.0/100 * shareprice * shares;		// Broker purchase commission.
	total_purch = shareprice * shares + purch_comm;	// Total cost of purchase.
	sell_comm = 1.5/100 * sellprice * shares;		// Broker sell commission.
	total_sell = sellprice * shares - sell_comm;	// Total stock sale return.
	prof_loss = total_sell - total_purch;			// Net profit/loss.
	tax = 25.0/100 * prof_loss;						// Tax on profit/Tax credit on loss.
	
	
	cout << "Results for " << shares << " shares of " << stock << ":" << endl;
	cout << string(35,'-') << endl;					// Output Header.
	
	cout << left << setfill('.');
	cout << setw(20) << "Buy Commission" << "$" << purch_comm << endl;
	cout << setw(20) << "Total Cost" << "$" << total_purch << endl;
	cout << setw(20) << "Sell Commission" << "$" << sell_comm << endl;
	cout << setw(20) << "Total Return" << "$" << total_sell << endl;
	cout << setw(20) << "Net Profit/Loss" << "$" << prof_loss << endl;
	cout << setw(20) << "Tax/Credit" << "$" << tax << endl << endl;
	
	return 0;
	
	
	
	
}

