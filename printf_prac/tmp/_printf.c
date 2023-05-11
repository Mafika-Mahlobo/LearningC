#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;

    int count = 0, num_digits, temp, i;
    char* digits_str;

    va_start(args, format);

    while (*format)
    {
        char *str;
	int num;
        char c;

        if (*format == '%')
	{
            format++;

            switch (*format)
	    {
		    case 's':
		    {
		    	str = va_arg(args, char*);
			while (*str)
			{
				write(1, str, 1);
				count++;
				str++;
			}
			break;
		    }
		    case 'd':
		    {
		    	num = va_arg(args, int);
			if (num < 0)
			{
				write(1, "-", 1);
				count++;
				num = -num;
			}
			if (num == 0)
			{
				write(1, "0", 1);
				count++;
			}

			else
			{
				num_digits = 0;
				temp = num;
				while (temp)
				{
					num_digits++;
					temp /= 10;
				}
			    	digits_str = malloc(num_digits + 1);
			    	digits_str[num_digits] = '\0';
			    	for (i = num_digits - 1; i >= 0; i--)
			    	{
					digits_str[i] = '0' + num % 10;
				    	num /= 10;
				}
			    	str = digits_str;
			    	while (*str)
				{
					write(1, str, 1);
				    	count++;
				    	str++;
			    	}
			    	free(digits_str);
		    	}
		    }
		    break;

               	    case 'c':
		    {
		 	c = (char) va_arg(args, int);
                    	write(1, &c, 1);
                    	count++;
                    	break;
		    }
                    default:
		    	write(1, format - 1, 1);
                    	count++;
                    	break;
            	}
        }
	else
	{
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

