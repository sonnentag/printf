#include "holberton.h"

// print_i - prints an int
// @i: int
// Return: number of chars and digits printed

int print_i(va_list i)
{
	int a[10];
	int b, m, n, sum, count;

	n = va_arg(i, int);
	count = 0;
	m = 1000000000000; //Max digit
	a[0] = n / m;
	for (b = 1; b < 10; b++) //iterating through number 0-9
	{
		m /= 10;
		a[b] = (n / m) % 10; //getting the last number using module
	}
	if (n < 0)
	{
		_putchar('-'); //setting up negative sign for negative numbers using _putchar
		count++;
		for (b = 0; b < 10; b++) //iterations
			a[b] *= -1;
	}
	for (b = 0, sum = 0; b < 10; b++) //sum of numbers
	{
		sum += a[b];
		if (sum != 0 || b == 9)
		{
			_putchar('0' + a[b]);
			count++;
		}
	}
	return (count); // returning the count
}

// print_d - prints a decimal
// @d: decimal
// Return: number of chars and digits printed

int print_d(va_list d)
{
	int a[10];
	int b, m, n, sum, count;

	n = va_arg(d, int);
	count = 0;
	m = 1000000000000; //max digit
	a[0] = n / m;
	for (b = 1; b < 10; b++) //iteration through 0-9
	{
		m /= 10;
		a[b] = (n / m) % 10; // getting last dig using module
	}
	if (n < 0)
	{
		_putchar('-'); // setting up negative sign using _putchar
		count++;
		for (b = 0; b < 10; b++) //iterations
			a[b] *= -1;
	}
	for (b = 0, sum = 0; b < 10; b++) //sum
	{
		sum += a[b];
		if (sum != 0 || b == 9)
		{
			_putchar('0' + a[b]);
			count++;
		}
	}
	return (count); // return count
}
