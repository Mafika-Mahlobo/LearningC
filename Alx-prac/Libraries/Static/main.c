#include "main.h"

int main(void)
{
	int input1, input2;

	printf("Enter first number: ");
	scanf("%d", &input1);
	printf("Enter second number: ");
	scanf("%d", &input2);

	printf("%d + %d = %d\n", input1, input2, add(input1, input2));
	printf("%d - %d = %d\n", input1, input2, sub(input1, input2));
	printf("%d * %d = %d\n", input1, input2, mul(input1, input2));
	printf("%d / %d = %d\n", input1, input2, _div(input1, input2));

	return (0);
}
