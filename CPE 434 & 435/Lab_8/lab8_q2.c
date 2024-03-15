#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char ch;

void fnKill(int killSignal)
{
	printf("\n.....Kill signal %d received.....\n", killSignal);
	printf("Dying process PID: %d\n", getpid());
	printf("\nProgram exited successfully.....\n");
	exit(0); 
}

void tBomb(int sigVal)
{
	printf("\n.....Signal %d received.....\n", sigVal);
	signal(SIGALRM, fnKill); 	
	alarm(10);

	while(1)
	{
		ch = '1' + 'A' + (random() % 36);
		printf("%c", ch);
	}
	exit(1);
}


int main()
{
	printf(".....Idle time, I'm doing nothing.....\n");
	signal(SIGINT, tBomb); 
	while(1);
	return -1;
}


