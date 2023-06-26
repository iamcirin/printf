#include "main.h"

/**
 * prec_fun - a function that calculates the precision
 * @format: a pointer to a char array
 * @j: a pointer to int
 * @list_args: list of args
 * Return: returns an int p.
 */
int prec_fun(const char *format, int *j, va_list list_args)
{
	int n = *j + 1;
	int p = -1;

	if (format[n] != '.')
		return (p);

	p = 0;

	for (n += 1; format[n] != '\0'; n++)
	{
		if (check_digit(format[n]))
		{
			p *= 10;
			p += format[n] - '0';
		}
		else if (format[n] == '*')
		{
			n++;
			p = va_arg(list_args, int);
			break;
		}
		else
			break;
	}

	*j = n - 1;

	return (p);
}

