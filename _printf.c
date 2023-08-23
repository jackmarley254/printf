#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Is a character string. The format string
 * is composed of zero or more directives
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/
int _printf(const char *format, ...)
{
	int size = 0;
	va_list args;
	char c;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				size++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					write(1, str, 1);
					str++;
					size++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				size++;
			}
		}
		else
		{
			write(1, format, 1);
			size++;
		}

		format++;
	}
	va_end(args);
	return (size);
}
