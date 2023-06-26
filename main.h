#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/**
 * struct select_st - Struct op
 * @placeholder: a member.
 * @select_op: The function associated.
 */

struct select_st
{
	char placeholder;
	int (*select_op)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct select_st select_st_instance - struct op
 * @select_st: The format.
 * @select_st_instance: instance of select_st struct.
 */
typedef struct select_st select_st_instance;

int _printf(const char *format, ...);
int handle_print(const char *string_format, int *n,
va_list list_args, char string_char[], int num, int wid, int prec, int s);




int char_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int string_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int percent_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);

int print_int(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int print_binary(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int print_unsignd(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int oct_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int hexad_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);
int hex_funx_2(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);

int hexa_func(va_list list_args, char map_to[],
char string_char[], int num, char flag_ch, int wid, int prec_t, int s);


int print_n_fun(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);


int ptr_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);

int flag_s(const char *format, int *n);
int calc_wid(const char *format, int *n, va_list list);
int prec_fun(const char *format, int *n, va_list list);
int calc_size(const char *format, int *n);

int reverse_func(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);

int func_rot13(va_list list_args, char string_char[],
	int num, int wid, int prec_t, int s);

int write_func(char c, char string_char[],
	int num, int wid, int prec_t, int s);
int write_num_func(int ind, char bff[], int num, int wid, int prec_t,
	int length, char padd, char extra_c);

int write_pointer_func(char string_char[], int ind, int length,
	int wid, int num, char padd, char extra_c, int padd_start);

	int write_number_func(int check_pos, int ind, char string_char[],
	int num, int wid, int prec_t, int s);

int write_unsgnd(int check_negativ, int ind,
char string_char[],
	int num, int wid, int prec_t, int s);

int check_print(char);
int add_to_hex_func(char, char[], int);
int check_digit(char);

long int convert_number(long int num, int s);
long int convert_unsignd(unsigned long int num, int s);

#endif /* MAIN_H */

