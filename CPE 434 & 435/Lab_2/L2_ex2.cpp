/*
DAN OTIENO
CPE 434-01
LAB 2
Exercise 2
*/
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


/***********************Function for child processes**********************/
void childprocess(int num1, int num2)
{
	int add = num1 + num2;
	int sub = num1 - num2;
	int mul = num1 * num2;

	/*********************New Process for Child 1*************************/
	cout << "------------------I am child 1--------------------" << endl;
	cout << "My Pid is: " << getpid() << endl;
	cout << "Subtraction Result = " << sub << endl;
	cout << "**************************************************" << endl << endl;
	/*********************************************************************/

	/*************************** Child 2 *********************************/
	pid_t pid = fork();

	if(pid == 0)
	{
		cout << "------------------I am child 2--------------------" << endl;
		cout << "My Pid is: " << getpid() << endl;
		cout << "Addition Result = " << add << endl;
		cout << "**************************************************" << endl << endl;
		exit(0);
	}
	else
	{
		wait(0);
		cout << "----------------I am child 1 again----------------" << endl;
		cout << "My Pid is: " << getpid() << endl;
		cout << "Multiplication Result = " << mul << endl;
		cout << "**************************************************" << endl << endl;
		exit(0);
	}
	/***********************************************************************/
}
/*************************************************************************/
/******************************MAIN***************************************/

int main()
{
	
	int firstnum, secondnum;


	cout << "Enter the first number: ";
	cin >> firstnum;
	cout << endl;

	cout << "Enter the second number: ";
	cin >> secondnum;
	cout << endl;

	pid_t mainpid = fork();

	if(mainpid == 0)
	{
		childprocess(firstnum, secondnum);
	}

	else
	{
		cout << "-----------------I am the parent------------------" << endl;
		cout << "My Pid is: " << getpid() << endl << endl;
		wait(0);
		cout << "-----------------I am the parent------------------" << endl;
		cout << "Terminating Program....." << endl;
		cout << "**************************************************" << endl << endl;
		exit(0);
	}
}
/*************************************************************************/
