#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PROCESSES 100

struct process {
    int pid;            // Process ID
    int burst_time;    
    int priority;
    int working_time;   //if working_time == burst_time, process is complete
    int t_round;        // time needed for the process to complete
    int arrival_time;  
    int waiting_time;   
    int remaining_time; 
};

void swap(struct process* a, struct process* b){
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_priority(struct process *processes, int n)
 {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
           if (processes[i].priority < processes[j].priority) {
               swap(&processes[i], &processes[j]);
            }
        }
    }
}

void dashes(int d)
{
 printf("\n");
 for(int i = 0; i < d; i++)
 {
     printf("-");
 }
 printf("\n");
}

void tableSteps(int *pid, int *time, int n)
{
    printf("\n");

    dashes(70);
    printf("| Time     |  ");
    for (int i = 0; i < n; i++) {
        printf("%5d |", time[i]);
    }
    dashes(70);
    printf("| PID      |  ");
    for (int i = 0; i < n; i++) {
        printf("%5d |", pid[i]);
    }
    dashes(70);
}

void table(struct process *processes, int n, int any) {
    int i;
    printf("\n");

    dashes(70);
    printf("| PID                |");
    for (int i = 0; i < n; i++) {
 printf("%7d |", processes[i].pid);
}

dashes(70);

    printf("| Wait Time(ms)      |");
    int waiting_time = 0;
for (i = 0; i < n; i++) 
{
    processes[i].waiting_time = processes[i].t_round - processes[i].burst_time;
 printf("%7d |", processes[i].waiting_time);
}

dashes(70);

    printf("|Turn Around Time(ms)|");

int t_round=0;
for (int i = 0; i < n; i++)
 {
     processes[i].t_round = processes[i].working_time - processes[i].arrival_time;
 printf("%7d |", processes[i].t_round);
    }


    dashes(70);
    printf("\n");

    dashes(70);
printf("|Average Wait Time(ms)     |");
{
    int total_waiting_time = 0;

    for (int i = 0; i < n; i++) 
    {
        total_waiting_time += processes[i].waiting_time;
    }

    
   printf(" %f | ", (float) total_waiting_time / n);
     
    }
    dashes(70);


}

int main(int argc, char* argv[]) {
 

    // Accept details of each process
    struct process *processes;

    int n = atoi(argv[1]); //number of process
   int quantum_time = atoi(argv[2]);

    processes = malloc(sizeof(struct process) *n);
     if(processes == 0)
     {
         exit(1);
     }


    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        processes[i].pid = i + 1;
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].working_time = 0;
        processes[i].t_round = 0;
        processes[i].waiting_time = 0;
        processes[i].arrival_time = 0;
    }

    // Round Robin Algorithm
    int time = 0, count = 0, remain = n;
    int numSteps = 0;
    for (int i = 0; i < n; i++)
    {
        numSteps += ceil((double)processes[i].burst_time / quantum_time);
    }
    int pidStep[numSteps], timeStep[numSteps];
    int counter = 0;
    while (remain > 0) 
    {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum_time) 
                {
                    time += quantum_time;
                    processes[i].remaining_time -= quantum_time;
                    pidStep[counter] = processes[i].pid;
                    timeStep[counter] = quantum_time;
                    counter++;

                } else {
                    pidStep[counter] = processes[i].pid;
                    timeStep[counter] = processes[i].remaining_time;
                    counter++;
                    time += processes[i].remaining_time;
                    processes[i].working_time = time;
                    processes[i].t_round = processes[i].working_time - processes[i].arrival_time;
                    processes[i].remaining_time = 0;
                    processes[i].waiting_time = processes[i].t_round - processes[i].burst_time;
                    remain--;
                }
            }
        }
    }


tableSteps(pidStep, timeStep, numSteps);
table(processes, n, quantum_time);
 //sort_by_priority(processes, n);


     void free(void*);
    return 0;
}
