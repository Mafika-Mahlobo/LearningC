#include <stdio.h>

/**
* main - reverse a list of numbers
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int nums[] = {34, 56, 54, 32, 67, 89, 90, 32, 21}; 

	int i;

	for (i = sizeof(nums - 1); i > -1; i--)
	{
		if (i == 0)
		{
			printf("%d", nums[i]);
		}
		else
		{
			printf("%d, ", nums[i]);
		}
	}
	putchar('\n');
	return (0);
}
