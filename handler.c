#include "main.h"

/**
 * handler - Format controller for processing variable arguments
 * @str: String format
 * @list: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 **/
int handler(const char *str, va_list list)
{
	int size, i, aux;

	size = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			aux = percent_handler(str, list, &i);
			if (aux == -1)
				return (-1);

			size += aux;
			continue;
		}

		_putchar(str[i]);
		size = size + 1;
	}


	return (size);
}
