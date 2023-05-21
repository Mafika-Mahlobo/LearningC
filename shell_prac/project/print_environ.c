#include <stdio.h>
#include <unistd.h>

extern char **environ; 

void print_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
