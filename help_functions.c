#include "main.h"

/**
 * check_print - a function that checks if a char is printable
 * @b: a char to check.
 * Return: returns an int
 */
int check_print(char b)
{
	if (b >= 32 && b < 127)
		return (1);

	return (0);
}

/**
 * add_to_hex_func - a function that appends ascci code in hexadecimal code
 * @string_char: a pointer to an array.
 * @n:int param.
 * @encoding: ASSCI code.
 * Return: returns 3 (an int)
 */
int add_to_hex_func(char encoding, char string_char[], int n)
{
	char arr_mp[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (encoding < 0)
		encoding *= -1;

	string_char[n] = '\\';
	n++;
	string_char[n] = 'x';
	n++;

	string_char[n] = arr_mp[encoding / 16];
	n++;
	string_char[n] = arr_mp[encoding % 16];

	return (3);
}

/**
 * check_digit - checks if a character is digit
 * @c: a charracter to check
 * Return: returns an int
 */

int check_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number - a function that converts a number
 * @number: an int param to convert.
 * @s: int param
 * Return: returns an int
 */
long int convert_number(long int number, int s)
{
	if (s == 2)
		return (number);
	else if (s == 1)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_unsignd - a function that converts a number
 * @number: int param to convert
 * @s: int param
 * Return: returns an int
 */
long int convert_unsignd(unsigned long int number, int s)
{
	if (s == 2)
		return (number);
	else if (s == 1)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
