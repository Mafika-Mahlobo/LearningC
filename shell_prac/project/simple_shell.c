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

	char *argv[] = {NULL};

	ssize_t read;

	size_t len = 0;
	
	pid_t child_pid;

	if (isatty(0))
		printf("#csifun ");

	while ((read = getline(&command, &len, stdin)) != -1)
	{
		if ((strcmp(command, "exit\n")) == 0)
			break;

		if (read != -1)
		{
			if (command[read - 1] == '\n')
				command[read - 1] = '\0';
		}

		child_pid = fork();
		
		if (child_pid == 0)
		{

			if (execve(command, argv, NULL) == -1)
			{
				perror("./shell");
				return (1);
			}	
		}
		else
		{
			wait(NULL);
			printf("#cisfun$ ");
		}
	}	
	free(command);
	return (0);
}
