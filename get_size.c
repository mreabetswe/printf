#include "main.h"

/**
 * get_size - calculates the size to cast the argument
 * @format: Formatted string
 * @i: arguments to be printed.
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int sz = 0;
	int argList = *i + 1;

	if (format[argList] == 'l')
		sz = S_LONG;
	else if (format[argList] == 'h')
		sz = S_SHORT;
	if (sz == 0)
		*i = argList - 1;
	else
		*i = argList;
	return (sz);
}

