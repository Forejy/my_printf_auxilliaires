

#include <zconf.h>
#include "../Includes/Functions.h"

void	test_format_suite(char flag, va_list ap)
{
	if (flag == 's')
		my_putstr(va_arg(ap, char *));
}

void	test_format(char flag, va_list ap)
{
	if (flag == 'c')
		my_putchar(va_arg(ap, char));
	test_format_suite(flag, ap);
}

void	test_function_with_va_arg(char *format, ...)
{
	va_list ap;

	va_start(ap, format);


	while (*format)
	{
		test_format(*format, ap);
		format++;
	}

}