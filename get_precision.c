#include "main.h"

/**
 * get_precision - calculates printing precision
 * @format: formatted string
 * @i: arguments to be printed.
 * @list: arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int p = -1;
	int argList = *i + 1;

	if (format[argList] != '.')
		return (p);
	p = 0;

	for (argList += 1; format[argList] != '\0'; argList++)
	{
		if (is_digit(format[argList]))
		{
			p *= 10;
			p = p + format[argList] - '0';
		}
		else if (format[argList] == '*')
		{
			argList++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = argList - 1;
	return (p);
}
