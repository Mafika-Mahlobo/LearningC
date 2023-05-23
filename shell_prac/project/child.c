#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
* child_process - takes user command and runs in new process
* @command: pointer to character (user cammnad)
* Return: No return value
*/
void child_process(char *command)
{
	pid_t child_pid;

	char *argv[] = {NULL};

	char *env[] = {NULL};

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command, argv, env) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
