using namespace std;
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	pid_t pid, x;

	cout << "The pid of the parent is " << getpid() << endl;

	for(x = 1; x <= 10; x++)
	{
		pid = fork();
		
		if (pid == 0 ) /* we are the child */
		{
			cout << "Process Id: " << getpid() << "\tX: " << x << endl;
			exit(0);
		}
		
	}

	return 0;	

}
