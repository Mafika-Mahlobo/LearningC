#include "arr.h"

int main()
{
	int max;
	int arr[5] = {4, 14, 3, 6, 7};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("The largest number of the array is: %d\n", largest(arr, &max, size));

	return (0);
}
