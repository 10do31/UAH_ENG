// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
Date::Date()
{
	month = 1;
	day = 1;
	year = 1900;
}

Date::Date(int initMonth, int initDay, int initYear)
{
	month = initMonth;
	day = initDay;
	year = initYear;	
}

Date::Date(int initMonth, int initYear)
{
	month = initMonth;
	day = 1;
	year = initYear;
}

// ************** TRANSFORMERS **************
void Date::SetDate(int Month, int Day, int Year)
{
	month = Month;
	day = Day;
	year = Year;
}

void Date::IncrementDate()
{
	day++;
	
    switch (month)
	{
		case JAN:	if(day > 31)
					{
						day = 1;
						month ++;	
					}			
		break;
		
		case FEB:	if(day > 28)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case MAR:	if(day > 31)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case APR:	if(day > 30)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case MAY:	if(day > 31)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case JUN:	if(day > 30)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case JUL:	if(day > 31)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case AUG:	if(day > 31)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case SEP:	if(day > 30)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case OCT:	if(day > 31)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case NOV:	if(day > 30)
					{
						day = 1;
						month++;	
					}			
		break;
		
		case DEC:	if(day > 31)
					{
						day = 1;
						month = 1;
						year++;	
					}			
		break;
	}
}

// ************** OBSERVERS *******************
void Date::WriteNumberFormat() const
{
	cout << setfill('0') << right;
	cout << setw(2) << month << "/" << setw(2) << day << "/"
	     << setw(2) << year;
	cout << setfill(' ') << endl;
}

void Date::WriteNameFormat() const
{
	switch (month)
	{
		case JAN:	cout << "January" << " " << day << "," << " " << year << endl;
		break;
		
		case FEB:	cout << "February" << " " << day << "," << " " << year << endl;
		break;
		
		case MAR:	cout << "March" << " " << day << "," << " " << year << endl;
		break;
		
		case APR:	cout << "April" << " " << day << "," << " " << year << endl;
		break;
		
		case MAY:	cout << "May" << " " << day << "," << " " << year << endl;
		break;
		
		case JUN:	cout << "June" << " " << day << "," << " " << year << endl;
		break;
		
		case JUL:	cout << "July" << " " << day << "," << " " << year << endl;
		break;
		
		case AUG:	cout << "August" << " " << day << "," << " " << year << endl;
		break;
		
		case SEP:	cout << "September" << " " << day << "," << " " << year << endl;
		break;
		
		case OCT:	cout << "October" << " " << day << "," << " " << year << endl;
		break;
		
		case NOV:	cout << "November" << " " << day << "," << " " << year << endl;
		break;
		
		case DEC:	cout << "December" << " " << day << "," << " " << year << endl;
		break;
	}
	     
}

bool Date::SameDate(Date otherDate) const
{
	return(month == otherDate.month && day == otherDate.day && year == otherDate.year);
}

bool Date::BeforeDate(Date otherDate) const
{
	// Function value == true if this date is earlier than other date.
	
	return(month < otherDate.month || month == otherDate.month && day < otherDate.day
	       || month == otherDate.month && day == otherDate.day && year < otherDate.year);
}

bool Date::AfterDate(Date otherDate) const
{
	// Function value == true if this date is later than other date.
	
	return(month > otherDate.month || month == otherDate.month && day > otherDate.day
	       || month == otherDate.month && day == otherDate.day && year > otherDate.year);
}



