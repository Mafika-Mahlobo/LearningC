#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _itoa(int num, char *str)
{
	int count = 0, sign, digit;
        char *p, temp;

	if (num < 0)
		sign = -1;
	else
		sign = 1;

	
	if (num == 0)
	{
		*str++ = '0';
		count++;
	}

	while (num != 0)
	{

		digit =  num % 10;
		*str++ = '0' + (sign * digit);
                num /= 10;
                count++;
	}


	if (sign < 0)
	{
		*str++ = '-';
                count++;
	}

	for (*p = str - count; p < str / 2; p++)
	{
		temp = *p;
                *p = *(str - (p - (str - count)) - 1);
                *(str - (p - (str - count)) - 1) =  temp;
	}

	return (count);
}


int _printf(const char *format, ...)
{
	char *p;
	int c, count = 0; len = 0;
	char *s;

	va_list args;

	va_start(args, format);

	for (*p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			switch (*++p)
			{
				case 'c':
					c = va_arg(args, int);
					write(STDOUT_FILENO, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (s[len] != '\0')
					{
						len++;
					}

					write(STDOUT_FILENO, s, len);
					count += len;
					break;
				default:
					write(STDOUT_FILENO, p, 1);
					count++;

			}
		}
		else
		{
			write(STDOUT_FILENO, p, 1);
			count++;
		}
	}

	va_end(args);

	return (count);

}

