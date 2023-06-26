#include "main.h"

/* PRINT UNSIGNED NUMBER */
/**
 * print_unsigned - this prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer arr to handle print
 * @flags:  Calc active flags
 * @width: retrieve width
 * @precision: Precision spec
 * @size: Size specifier
 * Return: Num of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMB IN OCTAL  **/
/**
 * print_octal - Prints an unsigned num in octal notation
 * @types: List of arguments
 * @buffer: Buffer arr to handle print
 * @flags:  Calc active flags
 * @width: retrieve width
 * @precision: Precision spec
 * @size: Size specifier
 * Return: Num of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUM IN HEXADECIMAL **/
/**
 * print_hexadecimal - this Prints an unsigned number in hexadecimal notation
 * @types: Lista of args
 * @buffer: Buffer Array to handle print
 * @flags:  Calc active flags
 * @width: retrieve width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRINT UNSIGNED NUM IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - this Prints an unsigned num in upper hexadecimal notation
 * @types: Lista of args
 * @buffer: Buffer arr to handle print
 * @flags:  Calc active flags
 * @width: retrieve width
 * @precision: Precision spec
 * @size: Size specifier
 * Return: Num of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*** PRINT HEXX NUM IN LOWER OR UPPER */
/**
 * print_hexa - Prints a hexadecimal num in lower or upper
 * @types: Lista of args
 * @map_to: Array of values to map the num
 * @buffer: the Buffer array to handle print
 * @flags:  Calc active flags
 * @flag_ch: Calc active flags
 * @width: retrieve width
 * @precision: Precision spec
 * @size: Size specifier
 * @size: Size specifications
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
