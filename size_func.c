#include "main.h"

/**
 * calc_size - a function that calculates size to cast the argument
 * @format: a pointer to a string
 * @number: number of args.
 * Return: int.
 */
int calc_size(const char *format, int *number)
{
	int m = *number + 1;
	int s = 0;

	if (format[m] == 'l')
		s = 2;
	else if (format[m] == 'h')
		s = 1;

	if (s == 0)
		*number = m - 1;
	else
		*number = m;

	return (s);
}

