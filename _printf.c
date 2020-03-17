#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * _printf - simple printf-like replacement
 * @format: selector
 * Return: character count
 */
int _printf(const char *format, ...)
{
	int j, n = 0, i = 0;
	va_list args;
	spec_t specs[] = {
		{"c", s_c},
		{"s", s_s},
		{"i", s_i},
		{"d", s_d},
		{"%", s_z}
	};

	if (format)
	{
		va_start(args, format);
		while (format[i] != '\0')
		{
			j = 0;
			if (format[i] == '%')
			{
				i++;
				while (j < 5)
				{
					if (specs[j].spec[0] == format[i])
					{
						n += specs[j].f(args);
					}
					j++;
				}
			}
			else
			{
				n += _putchar(format[i]);
			}
			i++;
		}
		va_end(args);

		return (n);
	}

	return (-1);
}
