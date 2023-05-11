#include <unistd.h>
#include <stdio.h>

/**
* main - get parent process ID
* Return: Always 0
*/

int main(void)
{
	printf("%u\n", getppid());

	return (0);
}
