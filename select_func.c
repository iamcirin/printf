#include "main.h"
/**
 * handle_print - a function that prints an argument based on its type
 * @string_format: a pointer to a formatted string.
 * @list_args: a list of arguments.
 * @n: an integer.
 * @string_char: string_char array to handle print.
 * @t: int param
 * @w: represents the width
 * @p: int param
 * @s: intparam
 * Return: returns an int;
 */
int handle_print(const char *string_format, int *n,
va_list list_args, char string_char[], int t, int w, int p, int s)
{
	int i, len = 0, char_number_printed = -1;
	select_st_instance select_func[] = {
		{'s', string_func}, {'c', char_func}, {'i', print_int},
		{'b', print_binary}, {'%', percent_func}, {'d', print_int},
		{'u', print_unsignd}, {'o', oct_func}, {'x', hexad_func}, {'p', ptr_func},
		{'X', hex_funx_2}, {'r', reverse_func}, {'R', func_rot13},
		{'S', print_n_fun}, {'\0', NULL}
	};
	for (i = 0; select_func[i].placeholder != '\0'; i++)
		if (string_format[*n] == select_func[i].placeholder)
			return (select_func[i].select_op(list_args, string_char, t, w, p, s));

	if (select_func[i].placeholder == '\0')
	{
		if (string_format[*n] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (string_format[*n - 1] == ' ')
			len = len + write(1, " ", 1);
		else if (w)
		{
			--(n);
			while (string_format[*n] != ' ' && string_format[*n] != '%')
				--(n);
			if (string_format[*n] == ' ')
				--(n);
			return (1);
		}
		len += write(1, &string_format[*n], 1);
		return (len);
	}

	return (char_number_printed);
}


