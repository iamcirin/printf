#include "main.h"

/**
 * flag_s - a function that calculates flags
 * @format: Formatted string in which to print the arguments
 * @i: int parameter.
 * Return: an int
 */
int flag_s(const char *format, int *i)
{

	int k, l;
	int m = 0;
	const char operators[] = {'-', '+', '0', '#', ' ', '\0'};
	const int num_arr[] = {1, 2, 4, 8, 16, 0};

	for (l = *i + 1; format[l] != '\0'; l++)
	{
		for (k = 0; operators[k] != '\0'; k++)
			if (format[l] == operators[k])
			{
				m |= num_arr[k];
				break;
			}

		if (operators[k] == 0)
			break;
	}

	*i = l - 1;

	return (m);
}
