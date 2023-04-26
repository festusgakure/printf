#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int (*_specifier(const char *))(va_list);
int p_unsigned(va_list args);

/**
 * struct fn - structure to specify the printer
 * @comp: character to be compared
 * @p: function for  printing
 */
typedef struct fn
{
	char *comp;
	int (*p)(va_list);
} fn_comp;

int p_char(va_list);
int p_str(va_list);
int p_cent(va_list);
int p_int(va_list);
int p_dec(va_list);
int p_unsigned(va_list);
int p_octal(va_list args)
#endif
