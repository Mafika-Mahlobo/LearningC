#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
* main - runs a command in 5 different processes
* Return: Always 0
*/

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	pid_t pid;
	
	int i;

	for (i = 0; i < 5; i++) 
	{
		pid = fork();

		if (pid ==  0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}

