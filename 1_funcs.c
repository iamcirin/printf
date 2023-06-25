#include "main.h"


/**
 * print_unsignd - a function that prints unsigned int
 * @list_args: a list of args
 * @string_char: a pointer to char
 * @t: an int param
 * @w: an int param
 * @p: an int param
 * @s: represents the size
 * Return: returns an int
 */
int print_unsignd(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	int i = 1024 - 2;
	unsigned long int number = va_arg(list_args, unsigned long int);

	number = convert_unsignd(number, s);

	if (number == 0)
		string_char[i--] = '0';

	string_char[1024 - 1] = '\0';

	while (number > 0)
	{
		string_char[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_unsgnd(0, i, string_char, t, w, p, s));
}

/**
 * oct_func - a function that prints an unsigned int in oct
 * @list_args: list of args
 * @string_char: a pointer to an array of string
 * @t: int param
 * @w: int param
 * @p: int param
 * @s: int param
 * Return: returns a number of characters
 */
int oct_func(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{

	int i = 1024 - 2;
	unsigned long int number = va_arg(list_args, unsigned long int);
	unsigned long int init_number = number;

	(void)(w);

	number = convert_unsignd(number, s);

	if (number == 0)
		string_char[i--] = '0';

	string_char[1024 - 1] = '\0';

	while (number > 0)
	{
		string_char[i] = (number % 8) + '0';
		i--;
		number = number / 8;
	}

	if (t & 8 && init_number != 0)
		string_char[i] = '0';
		i--;

	i++;

	return (write_unsgnd(0, i, string_char, t, w, p, s));
}

/**
 * hexad_func - a function that prints an unsigned number in hexadecimal
 * @list_args: a list of args
 * @string_char: a pointer to an array of chars
 * @t: an int param
 * @w: an int param
 * @p: an int param
 * @s: a size
 * Return: returns an int
 */
int hexad_func(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	char hex_numbers[] = "0123456789abcdef";

	return (hexa_func(list_args, hex_numbers, string_char,
		t, 'x', w, p, s));
}

/**
 * hex_funx_2 - a function that prints an unsigned number
 * @list_args: a list of args
 * @string_char: a pointer to char array
 * @t: int param
 * @w: int param
 * @p: int param
 * @s: represents the size
 * Return: returns an int
 */
int hex_funx_2(va_list list_args, char string_char[],
	int t, int w, int p, int s)
{
	char hex_numbers[] = "0123456789abcdef";

	return (hexa_func(list_args, hex_numbers, string_char,
		t, 'X', w, p, s));
}


/**
 * hexa_func - a function that prints an hex num in upper or lower case
 * @list_args: a list of args
 * @map_to: a pointer to an array of chars
 * @string_char: a pointer to an array on=f chars
 * @t: int param
 * @t_ch: int param
 * @w: int param
 * @p: int param
 * @s: int param
 * Return: returns a number of chars
 */
int hexa_func(va_list list_args, char map_to[], char string_char[],
	int t, char t_ch, int w, int p, int s)
{
	int i = 1024 - 2;

	unsigned long int number = va_arg(list_args, unsigned long int);
	unsigned long int init_number = number;

	(void)(w);

	number = convert_unsignd(number, s);

	if (number == 0)
		string_char[i--] = '0';

	string_char[1024 - 1] = '\0';

	while (number > 0)
	{
		string_char[i--] = map_to[number % 16];
		number = number / 16;
	}

	if (t & 8 && init_number != 0)
	{
		string_char[i] = t_ch;
		i--;
		string_char[i] = '0';
		i--;
	}

	i++;

	return (write_unsgnd(0, i, string_char, t, w, p, s));
}
