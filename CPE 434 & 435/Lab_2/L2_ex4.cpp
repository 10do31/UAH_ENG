/*
DAN OTIENO
CPE 434-01
LAB 2
Exercise 4
*/
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


/**************ORPHAN FUNCTION*************/
void orphan()
{
	pid_t o_pid = fork();

	if(o_pid > 0)
	{
		cout << "Orphan parent PID: " << getpid() << endl; //Orphan's parent.
	}
	else if(o_pid == 0)
	{
		sleep(25);
		cout << "Orphan child PID: " << getpid() << endl; //Orphan child.
	}
}

/**************ZOMBIE FUNCTION*************/
void zombie()
{
	pid_t z_pid = fork();

	if(z_pid > 0)
	{
		cout << "Zombie PID: " << getpid() << endl; //Zombie's parent.
		sleep(30);
	}
	else
	{
		exit(0); //Zombie child.
	}
}

/**************BEAUTY FUNCTION*************/
void beaut()
{
		sleep(40);
		cout << "Sleeping Beauty PID: " << getpid() << endl;
}

/**************MAIN FUNCTION*************/
main( )
{
	pid_t or_pid = fork();

	if(or_pid == 0)
	{
		orphan();  //Call Orphan function in Main.
		exit(0);
	}

	wait(0);   //Wait for previous process to complete.

	zombie();  //Call Zombie function in Main.

	wait(0);   //Wait for previous process to complete.

	beaut();   //Call Sleeping Beauty function in Main.

	exit(0);	
}
/********************************************/