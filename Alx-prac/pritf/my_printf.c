#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int my_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int written = vfprintf(stdout, format, args);
	va_end(args);
	return (written);
}
