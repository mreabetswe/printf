#include "main.h"

/**
 * handle_print - It prints out arguments
 * @fmt: Formatted character string, that returns the number of characters printed.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: An array to handle print.
 * @flags: Calculates active flags
 * @width:calculates width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2 if successful
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int e, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (e = 0; fmt_types[e].fmt != '\0'; e++)
		if (fmt[*ind] == fmt_types[e].fmt)
			return (fmt_types[e].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[e].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
