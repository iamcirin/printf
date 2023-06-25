#include "main.h"


/**
 * ptr_func - a function that dereference a pointer
 * @list_args: list of args
 * @string_char: a pointer to string
 * @t: int param
 * @w: represents the width
 * @p: int param
 * @s: int param
 * Return: returns an int - number of characters
 */
int ptr_func(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	char l = 0, d = ' ';
	int dig = 1022, len = 2, d_stt = 1; /* len=2, for '0x' */
	char array_p[] = "0123456789abcdef";
	unsigned long number_memory_address;
	void *ptr = va_arg(list_args, void *);

	(void)(w);
	(void)(s);

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	string_char[1023] = '\0';
	(void)(p);

	number_memory_address = (unsigned long)ptr;

	while (number_memory_address > 0)
	{
		string_char[dig--] = array_p[number_memory_address % 16];
		number_memory_address = number_memory_address / 16;
		len++;
	}

	if ((t & 4) && !(t & 1))
		d = '0';
	if (t & 2)
	{	l = '+';
		len++;
	}
	else if (t & 16)
	{
		l = ' ';
		len++;
	}


	dig++;

	return (write_pointer_func(string_char, dig, len,
		w, t, d, l, d_stt));
}


/**
 * print_n_fun - a function that prints ascii code in hexadecimal
 * @list_args: a list of args
 * @string_char: an array of chars
 * @t: int param
 * @w: int param
 * @p: int param
 * @s: int param
 * Return: returns the number of chars
 */
int print_n_fun(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	int i = 0, z = 0;
	char *str = va_arg(list_args, char *);

	(void)(t);
	(void)(w);
	(void)(p);
	(void)(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (check_print(str[i]))
			string_char[i + z] = str[i];
		else
			z += add_to_hex_func(str[i], string_char, i + z);

		i++;
	}

	string_char[i + z] = '\0';

	return (write(1, string_char, i + z));
}

/**
 * reverse_func - a function that prints the reverse of an array of chars.
 * @list_args: list of args
 * @string_char: a pointer to an array of characters
 * @t: int param
 * @w: represents the width
 * @p: int param
 * @s: int param
 * Return: returns the number of chars
 */

int reverse_func(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	char *m;
	int i, num = 0;

	(void)(string_char);
	(void)(t);
	(void)(w);
	(void)(s);

	m = va_arg(list_args, char *);

	if (m == NULL)
	{
		(void)(p);

		m = ")Null(";
	}
	for (i = 0; m[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char c = m[i];

		write(1, &c, 1);
		num++;
	}
	return (num);
}

/**
 * func_rot13 - a function that displays a string in rot13.
 * @list_args: list of args
 * @string_char: a pointer to an array of char
 * @t: int param
 * @w: int param
 * @p: int param
 * @s: int param
 * Return: returns number of chars
 */
int func_rot13(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	char *m;
	unsigned int i, j;
	char x;
	int num_count = 0;
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	m = va_arg(list_args, char *);
	(void)(string_char);
	(void)(t);
	(void)(w);
	(void)(p);
	(void)(s);

	if (m == NULL)
		m = "(AHYY)";
	for (i = 0; m[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == m[i])
			{
				x = output[j];
				write(1, &x, 1);
				num_count++;
				break;
			}
		}
		if (!input[j])
		{
			x = m[i];
			write(1, &x, 1);
			num_count++;
		}
	}
	return (num_count);
}
