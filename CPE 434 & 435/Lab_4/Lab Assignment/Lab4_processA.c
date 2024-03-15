
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "lab4.h"

int main(void)
{  
    int  i, id  ;
    struct info *ctrl;
    
	// create the shared memory segment 
	// .. id is the file identifier of the shared memory segment 
	// .. if the key is shared, any process can attach to this shared memory segment 
	// .. 0666 is the file permission for the shared memory segment
    if ( (id = shmget( KEY,MSIZ,IPC_CREAT | 0666) ) < 0 )
    {
	   //error…; 
	   printf("An error has occurred...closing program\n");
	   exit(1) ; 
    }

	// attach a local pointer to the shared memory segment created
	// .. exit if fails
    if ( (ctrl = (struct info *) shmat( id, 0, 0)) <= (struct info *) (0) )
	{
		//error … ; 
     	printf("Another error has occurred...closing program\n");
		exit(1) ;  
	}

	printf("---------------------------\n");
	printf("******** PROCESS A ********\n");
	printf("---------------------------\n");
	
	while(1)
	{
		printf("Enter the first number: ");
		scanf("%f", &ctrl->num1);
		printf("Enter the second number: ");
		scanf("%f", &ctrl->num2);
		printf("---------------------------\n");
		printf("Value 1: %f\n", ctrl->num1);
		printf("Value 2: %f\n", ctrl->num2);
		printf("---------------------------\n");
		fflush(stdout);
		ctrl->flag = 1;
		printf("Would you like to continue? Yes(1) | No(-1): \n");
		scanf("%i", &ctrl->choice);
		if(ctrl->choice == 1)
		{
			ctrl->flag = 1;
		}

		if(ctrl->choice == -1)
		{
			ctrl->flag = -1;
			printf("Thank you, Exiting program now....\n");
			fflush(stdout);
			//now detach the pointer from the shared memory
			shmdt(ctrl);
			//let us delete the shared memory
			shmctl(id,IPC_RMID,NULL);
			exit(0);
		}
	}
}