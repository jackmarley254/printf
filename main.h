#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

int get_size(const char *format, int *i);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);

int handle_print(const char *format, int *i, va_list list, int buffer, int flags, int width, int precision, int size);

int percent_handler(const char *format, va_list list, int *i);

int print_percent(va_list l, flags_t *f);

/* utils.c */
int _strlen(const char *);
int print(char *);
char *itoa(long int, int);

/* printf.c */
int _printf(const char *, ...);

/* print_percent */
int print_percent(va_list l, flags_t *f);

/* print_address */
int print_address(va_list l, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* get_flag */
int get_flag(char s, flags_t *f);

/* printers */
int print_integer(va_list);
int print_binary(va_list);
int print_rot(va_list);
int print_octal(va_list);
int print_hexadecimal_low(va_list);
int print_hexadecimal_upp(va_list);
int print_pointer(va_list);
int print_rev_string(va_list);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int count_digit(int i);

/* _putchar.c */
int _putchar(char);
int buffer(char);

/**
 * struct _format - Typedef struct
 *
 * @type: Format
 * @f: The function associated
 **/
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;

#endif
