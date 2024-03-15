#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

struct process
{
	int pid;
	int bTime; // burst time.
	int trnTime; // turn around time
	int wtTime; // Wait Time = Turn around Time - Burst Time
	int remTime; //Remaining time.
	int wrkTime;//Working time.
	int priority;
	int arrTime;
};

void dashes(int d)
{
	printf("\n");
	for(int i = 0; i < d; i++)
	{
		printf("-");
	}
	printf("\n");
}

void swap(struct process *a, struct process *b)
{
	struct process tmp = *a;
	*a=*b;
	*b=tmp;
}

int main(int argc, char* argv[])
{

	int n = atoi(argv[1]); // number of processes
	int quantum = atoi(argv[2]); // quantum time unit
	int avgwt = 0;
	struct process *p;
	
	// Allocating memory for n number of processes
	p = malloc(sizeof(struct process) * n);

	
	if (p == 0)
	{
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		printf("Process %d of %d\n", i+1, n);
		p[i].pid = i+1;
		printf("\tEnter burst time: ");
   	scanf("%d", &p[i].bTime);
   	p[i].remTime = p[i].bTime;
		p[i].wrkTime = p[i].trnTime = p[i].wtTime = p[i].arrTime = 0;

	}
	int count = 0, currTime = 0, nSteps = 0, rem = n;

	for(int i = 0; i < n; i++)
	{
		nSteps += ceil((double)p[i].bTime / quantum);
	}

	int pSteps[nSteps], tSteps[nSteps], count2 = 0;

   while (rem > 0) 
   {
      for (int i = 0 ; i < n; i++) 
      {
         if (p[i].remTime > 0) 
         {
            if (p[i].remTime > quantum) 
            {
               currTime += quantum;
               p[i].remTime -= quantum;
               pSteps[count2] = p[i].pid;
               tSteps[count2] = quantum;
               count2++;
            }
            else 
            {
               pSteps[count2] = p[i].pid;
               tSteps[count2] = p[i].remTime;
               count2++;
               currTime += p[i].remTime;
               p[i].wrkTime = currTime;
               p[i].trnTime = p[i].wrkTime - p[i].arrTime;
               p[i].remTime = 0;
               p[i].wtTime = p[i].trnTime - p[i].bTime;
               rem--;
            }
         }
      }
   }

   for(int i = 0; i < n-1; i++)
   {
   	for(int j = i+1; j < n; j++)
   	{
   		if(p[i].priority < p[j].priority)
   		{
   			swap(&p[i], &p[j]);
   		}
   	}
   }

   for (int i = 0; i < n ; i++)
   {
   		p[i].trnTime = p[i].bTime + p[i].wtTime;
   }
	
	for (int i = 0; i < n; i++)
	{
		avgwt += p[i].wtTime;
	}
	avgwt = avgwt / n;

	/******************** Printing Outputs *********************/
	dashes(110);
	printf("| Time (ms) |");
	for (int i = 0; i < nSteps; i++)
	{
		printf("     %d    |", tSteps[i]);
	}

	dashes(110);
	printf("| PID      |");
	for (int i = 0; i < nSteps; i++)
	{
		printf("      %d    |", pSteps[i]);
	}
	dashes(110);

	printf("\n");
	dashes(70);
	printf("| PID                   |   ");
	for (int i = 0; i < n; i++)
	{
		printf("      %d    |   ", p[i].pid);
	}
	dashes(70);

	printf("| Wait Time (ms)        |   ");
	for (int i = 0; i < n; i++)
	{
		printf("     %d    |   ", p[i].wtTime);
	}
	dashes(70);

	printf("| Turn Around Time (ms) |   ");
	for (int i = 0; i < n; i++)
	{
		printf("     %d    |   ", p[i].trnTime);
	}
	dashes(70);

	printf("\n");
	dashes(45);
	printf("| Average Wait Time (ms) |     %f    |", (float)avgwt);
	dashes(45);
	printf("| Quantum Time (ms)      |     %f    |", (float)quantum);
	dashes(45);
/**********************************************************/
	void free(void*);
}

