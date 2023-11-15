#include "shell.h"

/**
 * _erratoi - converts a string to an integer in the program
 * @s: the string to be converted
 * Return: -1 on error, 0 if no numbers in string
 * converted number otherwise
 */

int _erratoi(char *s)
{
	int a = 0;
	unsigned long int ret = 0;

	if (*s == '+')
		s++;

	for (a = 0;  s[a] != '\0'; a++)
	{
		if (s[a] >= '0' && s[a] <= '9')
		{
			ret *= 10;
			ret += (s[a] - '0');
			if (ret > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (ret);
}

/**
 * print_error - prints an error message after execution of the program
 * @info: the parameter
 * @errostr: string containing specified error type
 * @errostr: string containing specified error type
 * Return: -1 on error, 0 if no numbers in string
 * converted number otherwise
 */

void print_error(info_t *info, char *errostr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(errostr);
}

/**
 * print_d - function prints a decimal value int in base 10
 * @input: the input value to be printed
 * @fil_des: the filedescriptor
 * Return: printed charater
 */

int print_d(int input, int fil_des)
{
	int (*__putchar)(char) = _putchar;
	int a, output = 0;
	unsigned int _abs_, current;

	if (fil_des == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		output++;
	}
	else
		_abs_ = input;
	current = _abs_;

	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			output++;
		}
		current %= a;
	}
	__putchar('0' + current);
	output++;
	return (output);
}

/**
 * convert_number - the function that converts numbers, a clone of atois
 * @n: number to be converted
 * @base: base
 * @flags: argument
 * Return: string on success
 */

char *convert_number(long int n, int base, int flags)
{
	static char *ptr;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long v = n;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		v = -n;
		sign = '-';
	}
	ptr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

		do
		{
			*--p = ptr[v % base];
			v /= base;
		}
		while (v != 0);
		if (sign)
			*--p = sign;
		return (p);
}

/**
 * remove_comments - removes comments in the program
 * @buff: modifies string address
 * Return: Always 0 on success
 */

void remove_comments(char *buff)
{
	int a;

	for (a = 0; buff[a] != '\0'; a++)
		if (buff[a] == '#' && (!a || buff[a - 1] == ' '))
		{
			buff[a] = '\0';
			break;
		}
}
