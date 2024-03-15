#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t pid = 0;

void fnKill(int killSignal)
{
	printf("\n.....Kill signal received.....%d\n", killSignal);

	printf(".....Executing child kill process.....\n");
	kill(pid, SIGTERM);
	wait(0);
	printf(".....Child kill process complete.....\n");

	printf("\tDying process %d\n", getpid());
	exit(0);
}


void fnKillChild(int killSignal)
{
	printf(".....Parent has submitted child kill request.....\n");
	printf("\tDying process %d\n", getpid());
	exit(0);
}


void myFunction(int sigVal) // Slightly modified from demo.
{
	printf(".....Kill signal received.....%d\n", sigVal);
	printf("Now you can kill me...\n");
	signal(SIGINT, fnKill);
}


void fnProtect(int sigVal)
{
	if(pid == 0)
	{
		return;
	}
	else if (pid > 0)
	{
		printf("\n!Please wait for process to complete. System is protected!\n");
	}
}

int main()
{
	pid = fork();

	if(pid == 0) 
	{
		signal(SIGINT, fnProtect);
		signal(SIGTERM, fnKillChild);
		while(1);
	}
	else
	{
		signal(SIGINT, fnProtect);
		signal(SIGALRM, myFunction);
		alarm(10);
		while(1);
	}
	while(1);
	return(0);
}













































/*#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t pid = 0;
void kill_func(int killSignal);
void child_kill_func(int killSignal);
void myFunction(int sigVal);
void printProtect(int sigVal);

int main()
{
	pid = fork();
	if(pid == 0) // child
	{
		signal(SIGINT, printProtect);
		signal(SIGTERM, child_kill_func);
		while(1);
	}
	else // parent
	{
		signal(SIGINT, printProtect);
		signal(SIGALRM, myFunction);
		alarm(10);
		while(1);
	}
	while(1);
	return(0);
}


void kill_func(int killSignal)
{
	printf("Received kill signal %d\n", killSignal);
	printf("Killing child process...\n");
	kill(pid, SIGTERM);
	wait(0);
	printf("Child process killed\n");
	printf("\tDying process %d\n", getpid());
	exit(0);
}


void child_kill_func(int killSignal)
{
	printf("Requested termination from parent process\n");
	printf("\tDying process %d\n", getpid());
	exit(0);
}


void myFunction(int sigVal)
{
	printf("Program can now be terminated...\n");
	signal(SIGINT, kill_func);
}


void printProtect(int sigVal)
{
	if(pid == 0) // child
	{
		return;
	}
	else if (pid > 0)
	{
		printf("\nDetected SIGINT in process %d. System is still protected!\n", getpid());
	}
}*/