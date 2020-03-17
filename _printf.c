#include "t_p.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int j, n = 0, i = 0;
	va_list args;
	spec_t specs[] = {
		{"c", s_c},
		{"s", s_s},
		{"%", s_z},
		{NULL, NULL}
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
				while (j < 3)
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

