#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
* main - takes user inpout from input stream and print it
* Return: Always 0
*/

int main(int argc, char **argv)
{
	char  *stream = NULL;

	size_t len = 0;
	

	while (1)
	{
		printf("$ ");
		getline(&stream, &len, stdin);
		printf("%s", stream);
	}
	free(stream);
	return (0);

}
