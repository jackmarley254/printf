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

	if (format == NULL)
	{
		return (-1);

			va_start(args, format);

		while (*format)
		{
			if (*format == '%')
			{
				write(1, format, 1);
				size++;
			}
			else
			{
				format++;
				if (*format == '\0')
					break;
				if (*format == '%')
				{
					write(1, format, 1);
					size++;
				}
				else if (*format == 'c')
				{
					char c = va_arg(args, int);
					write(1, &c, 1);
					size++;
				}
				else if (*format == 's')
				{
					char *str = va_arg(args, char *);
					int str_len = 0;

					while (str[str_len] != 0);

					str_len++;
					write(1, str, str_len);
					size += str_len;
				}
			}
			format++;
		}
		va_end(args);
	}
		return (size);
}
