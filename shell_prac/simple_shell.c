#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
* main - simple shell to run  commands with full path
* Return: Always 0
*/

int main()
{
	char  *command = NULL;

	ssize_t read;

	size_t len = 0;
	
	pid_t child_pid;

	int status;
	

	while (1)
	{
		printf("$ ");

		read = my_getline(&command, &len, stdin);

		if (strcmp(command, "exit\n") == 0)
			break;

		if (read != -1)
		{
			if (command[read - 1] == '\n')
				command[read - 1] = '\0';
		}
			
		char *argv[] = {command, NULL};

		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				printf("%s\n", argv[0]);
				return (1);
			}

		}
		else
			wait(&status);
			printf("Retured with status code: %d\n", status);
		
	}

	free(command);
	return (0);

}
