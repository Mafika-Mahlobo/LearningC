#include <stdio.h>

/*
* *Create - creates an array and populates it with number
* Return: array with numbers
*/

int *create()
{
	static int arr[10];
	unsigned int i = 0;
	unsigned int num = 1;

	while (i < 10)
	{
		arr[i] = num;
		i++;
		num++;
	}

	return (arr);
}

/*
* main - prints array content
* Return: Always 0
*/

int main()
{
	int *values = create();
	unsigned int i;

	for (i = 0; i < 10; i++)
	{
		if (i < 9)
			printf("%d ", values[i]);
		else
			printf("%d\n", values[i]);
	}

	return (0);
}
