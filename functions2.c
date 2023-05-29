#include "main.h"

/**
 * print_pointer - prints the value of a pointer variable
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width specifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters printed.
 */
int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = 0, p = ' ';
	int i = BUFF_SIZE - 2, len = 2, p_start = 1;
	unsigned long number;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	number = (unsigned long)address;

	while (number > 0)
	{
		buffer[i--] = map_to[number % 16];
		number /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (flags & F_PLUS)
		c = '+', len++;
	else if (flags & F_SPACE)
		c = ' ', len++;
	i++;
	return (write_pointer(buffer, i, len, width, flags, p, c, p_start));
}
/**
 * print_non_printable - prints ascii codes in hexa of non-printable chareters
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width specifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0, os = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		if (is_printable(s[i]))
			buffer[i + os] = s[i];
		else
			os += append_hexa_code(s[i], buffer, i + os);
		i++;
	}
	buffer[i + os] = '\0';
	return (write(1, buffer, i + os));
}
/**
 * print_reverse - prints reverse string.
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width specifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char *s, a;
	int i, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		a = s[i];

		write(1, &a, 1);
		counter++;
	}
	return (counter);
}
/**
 * print_rot13string - print a string in rot13.
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width specifier
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of charecter
 */
int print_rot13string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int i, a;
	int counter = 0;
	char *s;
	char c;
	char inputS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outputS[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (a = 0; inputS[a]; a++)
		{
			if (inputS[a] == s[i])
			{
				c = outputS[a];
				write(1, &c, 1);
				counter++;
				break;
			}
		}
		if (!inputS[a])
		{
			c = s[i];
			write(1, &c, 1);
			counter++;
		}
	}
	return (counter);
}
