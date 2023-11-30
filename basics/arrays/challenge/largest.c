#include "arr.h"

int largest(int arr[], int *max, int size)
{
	unsigned int i = 0;
	*max = *arr;

	for (; i < size; i++)
	{
		if (*(arr + i) > *max)
			*max = *(arr + i);
	}

	return (*max);
}

