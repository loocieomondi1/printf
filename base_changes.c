#include "main.h"
/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list args)
{
	unsigned int num;
	int len;
	char *octal_rep;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	octal_rep = &num;
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';
	free(octal_rep);
	return (len);
}

/**
 * print_hex - Prints a representation of a decimal number on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rep = &num;
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	return (len);
}


/**
 * print_a_heX - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_a_hex(va_list args)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rep = &num;
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	return (len);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num % 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}

/**
 * base_len - afunctions that determines the base
 * @num - number to determine its base
 * @base: the desired base to be
 *
 * Retur: lenth of the integer
 */
int base_len(int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
		num = num / base;
	return (i);
}
