#include "main.h"

/**
 * print_unsigned - print unsigned number
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates flags
 * @width: width modifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters
 */
int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned long int number = va_arg(types, unsigned long int);
	int x = BUFF_SIZE - 2;

	number = convert_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[x--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number /= 10;
	}
	x++;
	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
/**
* print_octal - prints unsigned number in octal notation
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width modifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters
 */
int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial_number = number;
	int x = BUFF_SIZE - 2;

	UNUSED(width);
	number = convert_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[x--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[x--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & F_HASH && initial_number != 0)
		buffer[x--] = '0';
	x++;
	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - prints unsigned number in hexadecimal notation
 * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width modifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width,
				precision, size));
}
/**
 * print_hexa_upper - prints unsigned number in upper hexadecimal notation
 * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width modifier
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width,
				precision, size));
}
/**
 * print_hexa - prints hexadecimal number in lower or upper
 * @types: arguments
 * @map_to: values of an array
 * @buffer: buffer array
 * @flags: calculates active flags
 * @flag_ch: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of charecters
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial_number = number;
	int x = BUFF_SIZE - 2;

	UNUSED(width);
	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[x--] = map_to[number % 16];
		number /= 16;
	}
	if (flags & F_HASH && initial_number != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}
	x++;
	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
