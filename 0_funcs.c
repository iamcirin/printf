#include "main.h"


/**
 * char_func - a function that prints a char
 * @list_args: represents a list of arguments
 * @char_string: a pointer to a string
 * @t: int
 * @w: represents the width
 * @p: int param
 * @s: int param
 * Return: returns a number
 */
int char_func(va_list list_args, char char_string[],
	int t, int w, int p, int s)
{
	char c = va_arg(list_args, int);

	return (write_func(c, char_string, t, w, p, s));
}

/**
 * string_func - a function that prnts a string
 * @list_args: list of args
 * @char_string: an array to handle print
 * @t:  gets the number of flags
 * @w: gets the width.
 * @p: get the precise specification
 * @s: gets the size
 * Return: returns an int
 */
int string_func(va_list list_args, char char_string[],
	int t, int w, int p, int s)
{
	int len = 0, i;
	char *str = va_arg(list_args, char *);

	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (p >= 0 && p < len)
		len = p;

	if (w > len)
	{
		if (t & 1)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}


/**
 * percent_func - a function that prints the percent sign
 * @list_args: a list of arguments
 * @string_char: a pointer to an array of char
 * @t:  int param
 * @w: int param
 * @p: an int
 * @s: represents the size
 * Return: returns an int
 */
int percent_func(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	(void)(list_args);
	(void)(string_char);
	(void)(t);
	(void)(w);
	(void)(p);
	(void)(s);
	return (write(1, "%%", 1));
}


/**
 * print_int - a function that prints an int
 * @list_args: represents a list of args
 * @string_char: a pointer to a string of chars
 * @t:  an int
 * @w: an int param
 * @p: an int
 * @s: represents the size - an int
 * Return: returns an int
 */
int print_int(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	int i = 1024 - 2;
	int g = 0;
	long int n = va_arg(list_args, long int);
	unsigned long int num;

	n = convert_number(n, s);

	if (n == 0)
		string_char[i--] = '0';

	string_char[1024 - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		g = 1;
	}

	while (num > 0)
	{
		string_char[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number_func(g, i, string_char, t, w, p, s));
}


/**
 * print_binary - a function that prints an a binary number
 * @list_args: represents a list of args
 * @string_char: a pointer to a string of chars
 * @t:  an int
 * @w: an int param
 * @p: an int
 * @s: represents the size - an int
 * Return: returns the number of chars.
 */
int print_binary(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	unsigned int n, u, i, total_num;
	unsigned int a[32];
	int x;

	(void)(string_char);
	(void)(t);
	(void)(w);
	(void)(p);
	(void)(s);


	n = va_arg(list_args, unsigned int);
	u = 2147483648;
	a[0] = n / u;
	for (i = 1; i < 32; i++)
	{
		u /= 2;
		a[i] = (n / u) % 2;
	}
	for (i = 0, total_num = 0, x = 0; i < 32; i++)
	{
		total_num += a[i];
		if (total_num || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			x++;
		}
	}
	return (x);
}
