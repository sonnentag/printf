#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>

#define UNUSED(x) (void)(x)

/**
 * struct specs - typedef struct specs and spec_t
 *
 * @spec: specifier from %placeholder
 * @f: The function associated
 */
typedef struct specs
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);

int (*get_spec(char s))(va_list);

int s_c(va_list args);
int s_s(va_list args);
int s_i(va_list i);
int s_d(va_list d);
int s_z(va_list args);

int _putchar(char);

#endif
