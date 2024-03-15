
#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdlib.h>
#define key ((key_t)(1234))
#define charMAX 100

struct text_message { 
	long mymsg_type;
	char mymsg_text[charMAX];
};

int main()
{
	struct text_message message;
	int msid = msgget(key, 0666 | IPC_CREAT);

	printf("----------------------------------------------\n");
	printf("******** Android has entered the chat ********\n");
	printf("----------------------------------------------\n");

	while(1)
	{
		printf("Waiting for Apple....Apple is typing...\n\n");
		msgrcv(msid, &message, sizeof(message), 1, 0);

		if(strcmp(message.mymsg_text, "Exit\n") == 0)
		{
			printf("\nApple has left the chat...\n");
			printf("Exiting program now...\n");
			msgctl(msid, IPC_RMID, 0);
			exit(0);
		}
		printf("Apple chatted: %s\n", message.mymsg_text);
		
		printf("Android: ");
		fgets(message.mymsg_text, charMAX, stdin);
		message.mymsg_type = 2;
		msgsnd(msid, &message, sizeof(message), 0);

		if(strcmp(message.mymsg_text, "Exit\n") == 0)
		{
			printf("\nApple has left the chat...\n");
			printf("Exiting program now...\n");
			msgctl(msid, IPC_RMID, 0);
			exit(0);
		}
	}
	msgctl(msid, IPC_RMID, 0);

	return 0;
}