#include <stdio.h>
#include "my_head.h"

int main(void)
{
	int n = 10;
	my_printf("the value of %d mod 2 is %d\n", n,  (n % 2));
	return (0);
}
