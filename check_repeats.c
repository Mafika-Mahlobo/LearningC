#include <stdio.h>

/**
* main - check for repeated digits in a number
*
* Return: No return vlaue
*/
int main()
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	int rem;

	int seen[10] = {0};

	while (n > 0)
	{
		rem = n % 10;
		if (seen[rem] == 1)
		{
			break;
		}
		seen[rem] = 1;
		n = n / 10;
	}
	if (n == 0)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
	putchar('\n');
	return (0);
}


