#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct process
{
	int pid; //Process ID
	int priority;
	int bTime; //CPU Burst Time
	int wTime; //Time this process executed, if wTime==bTime, process is complete
	int trnTime; //turn around time, time needed for the process to complete
	int wtTime; // Wait Time = Turn around Time - Burst Time
};

/***** Function to print hyphens *****/
void dashes(int d)
{
	printf("\n");
	for(int i = 0; i < d; i++)
	{
		printf("-");
	}
	printf("\n");
}
/**********************************/

void swap(struct process *a, struct process *b)
{
	struct process tmp = *a;
	*a=*b;
	*b=tmp;
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]); 
	int quantum = atoi(argv[2]);
	int avgwt;
	struct process *prc;
	
	prc = malloc(sizeof(struct process) * n); // Memory allocation for n processes.
	
	if (prc == 0)
	{
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		printf("Process %d of %d\n", i+1, n);
		prc[i].pid = i+1;
		printf("\tEnter burst time: ");
   		scanf("%d", &prc[i].bTime);
   		printf("\tEnter Priority: ");
   		scanf("%d", &prc[i].priority);
	}

	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(prc[j].priority > prc[j+1].priority)
			{
				swap(&prc[j], &prc[j+1]);
			}
		}
	}

	int count = 0;
	prc[0].wtTime = 0;

	for(int i = 1; i < n; i++)
	{
		prc[i].wtTime = 0;
		for(int j = 0; j < i; j++)
		{
			prc[i].wtTime += prc[j].bTime;
		}
		count += prc[i].wtTime;
	}

	avgwt = (float)count / n;

	int count2 = 0;
	for (int i = 0; i < n; i++)
	{
		prc[i].trnTime = prc[i].bTime + prc[i].wtTime;
		count2 += prc[i].trnTime;
	}

/******************** Printing Outputs *********************/
	dashes(49);
	printf("| Time (ms) |");
	for (int i = 0; i < n; i++)
	{
		printf("     %d    |", prc[i].bTime);
	}
	dashes(49);
	printf("| PID       |");
	for (int i = 0; i < n; i++)
	{
		printf("      %d    |", prc[i].priority);
	}
	dashes(49);

	printf("\n");
	dashes(70);
	printf("| PID                   |   ");
	for (int i = 0; i < n; i++)
	{
		printf("      %d    |   ", prc[i].pid);
	}
	dashes(70);

	printf("| Wait Time (ms)        |   ");
	for (int i = 0; i < n; i++)
	{
		printf("     %d    |   ", prc[i].wtTime);
	}
	dashes(70);

	printf("| Turn Around Time (ms) |   ");
	for (int i = 0; i < n; i++)
	{
		printf("     %d    |   ", prc[i].trnTime);
	}
	dashes(70);

	printf("\n");
	dashes(38);
	printf("| Average Wait Time (ms) |     %d    |", avgwt);
	dashes(38);
/**********************************************************/
	void free(void*); // Memory deallocation.

	return 0;
}