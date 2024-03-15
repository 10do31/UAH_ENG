/*
DAN OTIENO
CPE 434-01
LAB 2
Exercise 3
*/
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void chTest(int);

/*********************Function to generate number of processes*********************/
void nForks()
{
	pid_t pid = fork();
  
	if(pid == 0)
	{
		cout << "Parent: Pid = " << getppid() << "|" << "\tChild: Pid = " << getpid() << "|" << endl;
    exit(0);
	}
}

/********************************************************************************/
/**********************************MAIN******************************************/

int main()
{
	
	int n;

	cout << "Please enter an even number: ";
	cin >> n;
 
   
  if(!(n%2 == 0))
  {
    cout << "Error!" << endl;
    cout << "Odd number entered!" << endl;
		cout << "Terminating Program...." << endl;
		exit(0);
  }
  
  else if(n%2 == 0)
  {
    cout << endl << "|There are " << n << " total number of processes|" << endl;
    cout << "-------------------------------------------" << endl;
    
    for(int i = 0; i<n; i++)
	  {
      nForks();
	  }
  }

  exit(0);
}