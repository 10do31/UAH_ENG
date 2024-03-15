/*
DAN OTIENO
CPE 434-01
LAB 3
Exercise 1
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define L_MAX 100

int fWait = 1;
int fRun = 1;

void fnIn(char *myFileName)
{
	int fIn = open(myFileName, O_RDONLY);
	dup2(fIn, 0);
	close(fIn);
}

void fnOut(char *myFileName)
{
	int fOut = open(myFileName, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(fOut, 1);
	close(fOut);
}

void fnRun(char *myArgs[])
{
	pid_t pid;

	if(strcmp(myArgs[0], "exit") != 0)
	{
		pid = fork();

		if(pid < 0)
		{
			fprintf(stderr, "Child process failed");
		}
		else if(pid == 0)
		{
			execvp(myArgs[0], myArgs);
		}
		else 
		{
			if(fWait)
			{
				waitpid(pid, NULL, 0);
			}
			else
			{
				fWait = 0;
			}
		}
		fnIn("/dev/tty");
     	fnOut("/dev/tty");
	}

	else
	{
		fRun = 0;
	}		
}

void fnpipe(char *myArgs[])
{
	int fds[2];
	pipe(fds);

	if(pipe(fds) == -1)
	{
		printf("Error executing piping process");
		exit(0);
	}

	dup2(fds[1], 1);
	close(fds[1]);

	//printf("myArgs = %s\n", *myArgs);

	fnRun(myArgs);

	dup2(fds[0], 0);
	close(fds[0]);
}

char * fnToken(char *input)
{
    int i;
    int j = 0;

    char *token = (char *)malloc((L_MAX * 2) * sizeof(char));

    // add spaces around special characters
    for (i = 0; i < strlen(input); i++) 
    {
        if (input[i] != '>' && input[i] != '<' && input[i] != '|') 
        {
            token[j++] = input[i];
        } 
        else 
        {
            token[j++] = ' ';
            token[j++] = input[i];
            token[j++] = ' ';
        }
    }
    token[j++] = '\0';

    // add null to the end
    char *end;
    end = token + strlen(token) - 1;
    end--;
    *(end + 1) = '\0';

    return token;
}



int main(void)
{
	char *myArgs[L_MAX];

	while (fRun) 
	{
 		printf("MyBash$: ");
 		fflush(stdout);
 		char input[L_MAX];

 		// Get user input
 		fgets(input, L_MAX, stdin);

 		char *ftoken; //Tokens.

    	ftoken = fnToken(input);

    	if(ftoken[strlen(ftoken) - 1] == '&')
    	{
    		fWait = 0;
    		ftoken[strlen(ftoken) - 1] = '\0';
    	}

        char *myTemp = strtok(ftoken," ");
        int counter = 0;

 		while(myTemp)
 		{
 			if(*myTemp == '<')
 			{
 				fnIn(strtok(NULL, " "));
 			}
 			else if(*myTemp == '>')
 			{
 				fnOut(strtok(NULL, " "));
 			}
 			else if(*myTemp == '|')
 			{
 				myArgs[counter] = NULL;
 				fnpipe(myArgs);
 				counter = 0;
 			}
 			else
 			{
 				myArgs[counter] = myTemp;
 				counter++;
 			}

 			myTemp = strtok(NULL, " ");
 		}

 		myArgs[counter] = NULL;

 		fnRun(myArgs);
	}

	return 0;
}
