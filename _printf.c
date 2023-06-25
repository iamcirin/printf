#include "main.h"

void print_t(char str_char[], int *j);

/**
 * _printf - a function that prints input to stdout
 * @format: a pointer to string.
 * Return: returns an int - a number of printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_number = 0;
	int t, wid, prec, size, j = 0;
	int *c = &j;
	va_list list_args;
	char string_h[1024];

	if (format == NULL)
		return (-1);

	va_start(list_args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			string_h[j] = format[i];
			j++;

			if (j == 1024)
				print_t(string_h, &j);

			chars_number++;
		}
		else
		{
			if (*c > 0)
				write(1, &string_h[0], *c);
			*c = 0;

			t = flag_s(format, &i);
			wid = calc_wid(format, &i, list_args);
			prec = prec_fun(format, &i, list_args);
			size = calc_size(format, &i);
			++i;
			printed = handle_print(format, &i, list_args, string_h,
				t, wid, prec, size);
			if (printed == -1)
				return (-1);
			chars_number += printed;
		}
	}


	if (*c > 0)
		write(1, &string_h[0], *c);
	*c = 0;

	va_end(list_args);

	return (chars_number);
}

/**
 * print_t - a function that prints the contents of the buffer_str
 * @buffer_str: a pointer to string
 * @j: pointer to integer.
 */
void print_t(char buffer_str[], int *j)
{
	if (*j > 0)
		write(1, &buffer_str[0], *j);

	*j = 0;
}
