#include <stdio.h>

/**
* main - prints all terminal arguments
* Return: Always 0
*/

int main(int ac, char **av)
{
	int i = 1;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
}
