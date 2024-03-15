/*
DAN OTIENO
CPE 434-01
LAB 2
Exercise 1
*/
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*******Function for fork********/
void forkprogram()
{
	int val = 0;
	pid_t pid = fork();

	if(pid == 0)
	{
		val += 2;
		cout << "**********I am the child************" << endl << endl;
		cout << "My Pid is " << getpid() << " and Val = " << val << endl;
    	cout << endl;
		cout << "************************************" << endl << endl;
	}
	else
	{
		val += 5;
		cout << "**********I am the parent************" << endl << endl;
		cout << "My Pid is " << getpid() << " and Val = " << val << endl;
    	cout << endl;
		cout << "************************************" << endl << endl;
	}

}
/************************************************/
/*********************MAIN***********************/
int main()
{
	forkprogram();

	return 0;
}
