#include "main.h"

/**
 * calc_wid - a function that alculates the width
 * @string_w: a pointer to an array of chars.
 * @n: pointer to int.
 * @list_args: list of arguments.
 *
 * Return: width.
 */
int calc_wid(const char *string_w, int *n, va_list list_args)
{
	int m;
	int w = 0;

	for (m = *n + 1; string_w[m] != '\0'; m++)
	{
		if (check_digit(string_w[m]))
		{
			w *= 10;
			w += string_w[m] - '0';
		}
		else if (string_w[m] == '*')
		{
			m++;
			w = va_arg(list_args, int);
			break;
		}
		else
			break;
	}

	*n = m - 1;

	return (w);
}

