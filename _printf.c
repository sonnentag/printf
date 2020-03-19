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
	int x = 0, n = 0, i = 0;
	va_list args;

	if (format)
	{
		va_start(args, format);
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;
				if (!format[i])
					return (-1);

				if (format[i] == '%')
					n += _putchar(format[i]);
				else
				{
					x = get_spec(format[i], args);
					if (x > 0)
						n += x;
					else
					{
						n += _putchar(format[i - 1]);
						n += _putchar(format[i]);
					}
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

/**
 * get_spec - get specifier function
 * @s: provided format specifier
 * @args: provided arg
 * Return: character count
 */
int get_spec(char s, va_list args)
{
	int j = 0, n = 0;
	spec_t specs[] = {
		{"c", s_c},
		{"s", s_s},
		{"i", s_i},
		{"d", s_d},
		{"%", s_z},
		{NULL, NULL}
	};

	while (specs[j].spec)
	{
		if (specs[j].spec[0] == s)
		{
			n += specs[j].f(args);
		}
		j++;
	}

	return (n);
}
