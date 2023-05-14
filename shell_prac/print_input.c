#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
* main - takes user inpout from input command and print it
* Return: Always 0
*/

int main()
{
	char  *command = NULL;

	size_t len = 0;
	

	while (1)
	{
		printf("$ ");
		my_getline(&command, &len, stdin);

		if (strcmp(command, "exit\n") == 0)
			break;

		printf("%s", command);
		
	}
	free(command);
	return (0);

}
