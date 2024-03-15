
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "lab4.h"

int main(void)
{
	int id;
	struct info* ctrl;

	if ((id = shmget(KEY, MSIZ, 0)) < 0)
	{
		printf("An error has occurred...closing program\n");
		exit(1);
	}
	
	ctrl = (struct info*) shmat(id, 0, 0);

	if (ctrl <= (struct info*)(0))
	{
		printf("An error has occurred...closing program\n");
		exit(1);
	}

	printf("------------------------------------------------\n");
	printf("******************* PROCESS B ******************\n");
	printf("------------------------------------------------\n");

	while(1)
	{
		while(ctrl->flag == 0 && ctrl->flag != -1);
		if(ctrl->choice == 1)
		{
			ctrl->sum = ctrl->num1 + ctrl->num2; // calculate and store sum
			printf("------------------------------------------------\n");
			printf("Sum of %f and %f = %f\n", ctrl->num1, ctrl->num2, ctrl->sum);
			printf("------------------------------------------------\n");
			ctrl->flag = 0; // set the flag for process A
		}
		else if(ctrl->choice == -1)
		{
			ctrl->sum = ctrl->num1 + ctrl->num2; // calculate and store sum
			printf("Sum of %f and %f = %f\n", ctrl->num1, ctrl->num2, ctrl->sum);
			printf("Thank you, Exiting program now....\n");
			exit(0);
		}
	}
	
	shmdt(ctrl);
	exit(0);
}