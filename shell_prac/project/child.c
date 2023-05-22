#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

int child_process(char *command)
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
			return (1);
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
