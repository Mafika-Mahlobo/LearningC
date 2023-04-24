#include <stdio.h>

/**
main - request user input and give some back
*/

int main(void)
{
	int val1, val2;

	printf("Enter first number: ");
	scanf("%d", &val1);
	printf("Enter second number: ");
	scanf("%d", &val2);
	printf("sum: %d\n", (val1 + val2));

	return (0);
}
