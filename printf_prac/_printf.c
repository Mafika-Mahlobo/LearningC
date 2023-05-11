#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	int num_chars_printed = 0;

	const char* current_char = format;
	
	while (*current_char != '\0')
	{
		if (*current_char == '%')
		{
			current_char++;
			switch (*current_char)
			{
				case 's':
				{
					char* string_arg = va_arg(args, char*);
					int string_length = 0;
					while (string_arg[string_length] != '\0')
						string_length++;

					num_chars_printed += write(STDOUT_FILENO, string_arg, string_length);
					break;

				}
				case 'd':
				case 'i':
				{
					int int_arg = va_arg(args, int);
					int num_digits = 0;
					if (int_arg == 0)
						num_digits = 1;
					else
					{
						int temp = int_arg;
						while (temp != 0)
						{
							temp /= 10;
							num_digits++;
						}
					}
					char* int_string = (char*) malloc((num_digits + 1) * sizeof(char));
					int i = num_digits - 1;
					if (int_arg == 0)
					{
						int_string[0] = '0';
						i = 0;
					}
					else
					{
						int temp = int_arg;
						while (temp != 0)
						{
							int_string[i] = (char) ((temp % 10) + '0');
							temp /= 10;
							i--;
						}
					}
					num_chars_printed += write(STDOUT_FILENO, int_string, num_digits);
					free(int_string);
					break;
				}
				case 'f':
				{
					double double_arg = va_arg(args, double);
					int whole_part = (int) double_arg;
					int fractional_part = (int) ((double_arg - whole_part) * 1000000);
					char whole_string[20] = {0};
					char fractional_string[20] = {0};
					int whole_length = 0;
					int fractional_length = 0;
					if (whole_part == 0)
					{
						whole_string[0] = '0';
						whole_length = 1;
					}
					else
					{
						int i = 0;
						while (whole_part != 0)
						{
							whole_string[i] = (char) ((whole_part % 10) + '0');
							whole_part /= 10;
							i++;
						}
						whole_length = i;
						for (int j = 0; j < i / 2; j++)
						{
							char temp = whole_string[j];
							whole_string[j] = whole_string[i - j - 1];
							whole_string[i - j - 1] = temp;
						}
					}
					if (fractional_part == 0)
					{
						fractional_string[0] = '0';
						fractional_length = 1;
					}
					else
					{
						int i = 0;
						while (fractional_part != 0)
						{
							fractional_string[i] = (char) ((fractional_part % 10) + '0');
							fractional_part /= 10;
							i++;
						}
						fractional_length = i;
						for (int j = 0; j < i / 2; j++)
						{
							char temp = fractional_string[j];
							fractional_string[j] = fractional_string[i - j - 1];
							fractional_string[i - j];
						}
					}
				
				}
			}
		}
	}
	va_end(args);

	return (num_chars_printed);
}



