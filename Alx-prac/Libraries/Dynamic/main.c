#include "main.h"
#include <dlfcn.h>

/**
* main - uses math functions in dynamic library
* Return: Always 0
*/

int main(void)
{
	int input1, input2, tot;

	void* lib = dlopen("./_mathlib.so", RTLD_LAZY);

	if (!lib)
	{
		printf("Error: could not get library\n");
		return (1);
	}

	printf("Enter first number: ");
	scanf("%d", &input1);
	printf("Enter second number: ");
	scanf("%d", &input2);

	int (*add)(int, int) = dlsym(lib, "add");
	int (*sub)(int, int) = dlsym(lib, "sub");
	int (*mul)(int, int) = dlsym(lib, "mul");
	int (*_div)(int, int) = dlsym(lib, "_div");

	printf("%d + %d = %d\n", input1, input2, add(input1, input2));
	printf("%d - %d = %d\n", input1, input2, sub(input1, input2));
	printf("%d * %d = %d\n", input1, input2, mul(input1, input2));
	printf("%d / %d = %d\n", input1, input2, _div(input1, input2));

	dlclose(lib);

	return (0);
}
