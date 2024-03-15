using namespace std;
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*******Function for fork********/
void forkprogram()
{
	int val = 10; //Initialize val, I just picked 10 instead of 0.
	pid_t pid = fork();

	/* Val is not updated by writing any data, 
	will use this to check if Heap and Stack are the same*/
	cout << "PID: " << getpid() << "\tVal before data is written: " << val << endl;

	if(pid != 0) // Parent process to update val variable.
	{
		val += 5;
		cout << "PID: " << getpid() << "\tval after data is written by parent process: " << val << endl;
	}
	else
	{
		// else, print variable using child process.
		cout << "PID: " << getpid() << "\tChild process prints val after parent process: " << val << endl;
	}

}
/************************************************/
/*********************MAIN***********************/
int main()
{
	forkprogram(); //Call function in Main.

	return 0;
}