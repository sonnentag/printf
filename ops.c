#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * s_z - printing % sign
 * @args: Provided argument
 * Return: 1
 */
int s_z(va_list args)
{
	UNUSED(args);

	_putchar('%');

	return (1);
}

/**
 * s_c - printing char
 * @args: char
 * Return: 1
 */
int s_c(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);

	return (1);
}

/**
 * s_s - printing string
 * @args: string
 * Return: character count
 */
int s_s(va_list args)
{
	unsigned int c;
	char *s;

	s = va_arg(args, char *);
	c = 0;
	if (!s)
		s = "(null)";
	while (s[c] != '\0')
	{
		_putchar(s[c]);
		c++;
	}

	return (c);

}

/**
 * s_i - prints an int
 * @i: int
 * Return: number of chars and digits printed
 */
int s_i(va_list i)
{
	int a[10];
	int b, m, n, sum, count;

	n = va_arg(i, int);
	count = 0;
	m = 1000000000000; /* Max digit */
	a[0] = n / m;
	for (b = 1; b < 10; b++) /* iterating through number 0-9 */
	{
		m /= 10;
		a[b] = (n / m) % 10; /* getting the last number using module */
	}
	if (n < 0)
	{
		_putchar('-'); /* setting up sign for negative numbers using _putchar */
		count++;
		for (b = 0; b < 10; b++) /* iterations */
			a[b] *= -1;
	}
	for (b = 0, sum = 0; b < 10; b++) /* sum of numbers */
	{
		sum += a[b];
		if (sum != 0 || b == 9)
		{
			_putchar('0' + a[b]);
			count++;
		}
	}
	return (count); /* returning the count */
}

/**
 * s_d - prints a decimal
 * @d: decimal
 * Return: number of chars and digits printed
 */
int s_d(va_list d)
{
	int a[10];
	int b, m, n, sum, count;

	n = va_arg(d, int);
	count = 0;
	m = 1000000000000;
	a[0] = n / m;
	for (b = 1; b < 10; b++)
	{
		m /= 10;
		a[b] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		for (b = 0; b < 10; b++)
			a[b] *= -1;
	}
	for (b = 0, sum = 0; b < 10; b++)
	{
		sum += a[b];
		if (sum != 0 || b == 9)
		{
			_putchar('0' + a[b]);
			count++;
		}
	}
	return (count);
}
