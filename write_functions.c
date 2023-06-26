#include "main.h"

/**
 * write_func - a function that writes a string
 * @c: a char.
 * @string_char: san array of string
 * @t: int param.
 * @w: int param.
 * @p: int param
 * @s: int param
 * Return: returns a number of chars.
 */
int write_func(char c, char string_char[],
	int t, int w, int p, int s)
{
	int i = 0;
	char k = ' ';

	(void)(p);
	(void)(s);

	if (t & 4)
		k = '0';

	string_char[i] = c;
	i++;
	string_char[i] = '\0';

	if (w > 1)
	{
		string_char[1023] = '\0';
		for (i = 0; i < w - 1; i++)
			string_char[1022 - i] = k;

		if (t & 1)
			return (write(1, &string_char[0], 1) +
					write(1, &string_char[1023 - i], w - 1));
		else
			return (write(1, &string_char[1023 - i], w - 1) +
					write(1, &string_char[0], 1));
	}

	return (write(1, &string_char[0], 1));
}


/**
 * write_number_func - a function that writes a number
 * @check_neg: int param
 * @d: int param.
 * @char_string: a pointer to an array of chars
 * @t:  Calculates active t
 * @w: int param
 * @p: int param
 * @s: int param
 *
 * Return: Number of chars printed.
 */
int write_number_func(int check_neg, int d, char char_string[],
	int t, int w, int p, int s)
{
	int len = 1024 - d - 1;
	char k = ' ', d_ch = 0;

	(void)(s);

	if ((t & 4) && !(t & 1))
		k = '0';
	if (check_neg)
		d_ch = '-';
	else if (t & 2)
		d_ch = '+';
	else if (t & 16)
		d_ch = ' ';

	return (write_num_func(d, char_string, t, w, p,
		len, k, d_ch));
}

/**
 * write_num_fun - Write a number using a bufffer
 * @d: int num
 * @char_string: a pointerto char
 * @t: int param
 * @w: int param
 * @prec: int param
 * @len: length
 * @dd: a char
 * @rax: a char
 *
 * Return: Number of printed chars.
 */
int write_num_func(int d, char char_string[],
	int t, int w, int prec,
	int len, char dd, char rax)
{
	int i, d_strt = 1;

	if (prec == 0 && d == 1022 && char_string[d] == '0' && w == 0)
		return (0);
	if (prec == 0 && d == 1022 && char_string[d] == '0')
		char_string[d] = dd = ' ';
	if (prec > 0 && prec < len)
		dd = ' ';
	while (prec > len)
		char_string[--d] = '0', len++;
	if (rax != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			char_string[i] = dd;
		char_string[i] = '\0';
		if (t & 1 && dd == ' ')
		{
			if (rax)
				char_string[--d] = rax;
			return (write(1, &char_string[d], len) + write(1, &char_string[1], i - 1));
		}
		else if (!(t & 1) && dd == ' ')
		{
			if (rax)
				char_string[--d] = rax;
			return (write(1, &char_string[1], i - 1) + write(1, &char_string[d], len));
		}
		else if (!(t & 1) && dd == '0')
		{
			if (rax)
				char_string[--d_strt] = rax;
			return (write(1, &char_string[d_strt], i - d_strt) +
				write(1, &char_string[d], len - (1 - d_strt)));
		}
	}
	if (rax)
		char_string[--d] = rax;
	return (write(1, &char_string[d], len));
}

/**
 * write_unsgnd - a function that write unsigned number
 * @check_neg: an int num
 * @d: int param
 * @char_string: Array of chars
 * @t: int param
 * @w: int param
 * @p: int param
 * @s: int param
 *
 * Return: returns an int.
 */
int write_unsgnd(int check_neg, int d,
	char char_string[],
	int t, int w, int p, int s)
{

	int len = 1023 - d, i = 0;
	char ddt = ' ';

	(void)(check_neg);
	(void)(s);

	if (p == 0 && d == 1022 && char_string[d] == '0')
		return (0);

	if (p > 0 && p < len)
		ddt = ' ';

	while (p > len)
	{
		char_string[--d] = '0';
		len++;
	}

	if ((t & 4) && !(t & 1))
		ddt = '0';

	if (w > len)
	{
		for (i = 0; i < w - len; i++)
			char_string[i] = ddt;

		char_string[i] = '\0';

		if (t & 1)
		{
			return (write(1, &char_string[d], len) + write(1, &char_string[0], i));
		}
		else
		{
			return (write(1, &char_string[0], i) + write(1, &char_string[d], len));
		}
	}

	return (write(1, &char_string[d], len));
}

/**
 * write_pointer_func - a funtion that prints a pointer
 * @char_string: a pointer to an array of char
 * @d: int param
 * @len: int param - length
 * @w: int param
 * @t: int param
 * @ddt: int param
 * @rax: int param
 * @ddt_strt: int param
 * Return: returns an int
 */
int write_pointer_func(char char_string[], int d, int len,
	int w, int t, char ddt, char rax, int ddt_strt)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			char_string[i] = ddt;
		char_string[i] = '\0';
		if (t & 1 && ddt == ' ')/* Asign extra char to left of char_string */
		{
			char_string[--d] = 'x';
			char_string[--d] = '0';
			if (rax)
				char_string[--d] = rax;
			return (write(1, &char_string[d], len) + write(1, &char_string[3], i - 3));
		}
		else if (!(t & 1) && ddt == ' ')
		{
			char_string[--d] = 'x';
			char_string[--d] = '0';
			if (rax)
				char_string[--d] = rax;
			return (write(1, &char_string[3], i - 3) + write(1, &char_string[d], len));
		}
		else if (!(t & 1) && ddt == '0')
		{
			if (rax)
				char_string[--ddt_strt] = rax;
			char_string[1] = '0';
			char_string[2] = 'x';
			return (write(1, &char_string[ddt_strt], i - ddt_strt) +
				write(1, &char_string[d], len - (1 - ddt_strt) - 2));
		}
	}
	char_string[--d] = 'x';
	char_string[--d] = '0';
	if (rax)
		char_string[--d] = rax;
	return (write(1, &char_string[d], 1023 - d));
}

