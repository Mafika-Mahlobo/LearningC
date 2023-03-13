#include <stdio.h>

int main(){
/*
 * Common Datatypes 
 Tasks
 print int and sizeof
 print double (2 decimal places) and sizeof
 print  float (1 decimal place) and sizeof
 print char and number stored as

*/
	
	int number = 25;
	printf("int: %d", number);
       	printf(", size: %zu\n\n", sizeof(number));

	double number1 = 13.57;
	printf("Double: %.2lf", number1);
	printf(", size: %zu\n\n", sizeof(number1));

	float number2 = 10.9f;
	printf("Float: %.1lf", number2);
	printf(", size: %zu\n\n", sizeof(number2));

	char chaOne = 'k';
	printf("Char: %c", chaOne);
	printf(", stored as: %d\n", chaOne);	
		
	return 0;
}
