#include "shell.h"

/**
 * _eputs - prints the string input
 * @s: printed string
 * Return: void
 */

void _eputs(char *s)
{
	int m = 0;

	if (!s)
		return;
	while (s[m] != '\0')
	{
		_eputchar(s[m]);
		m++;
	}
}

/**
 * _eputchar - writes the character ch to std error
 * @ch: The character to be printed
 * Return: 1 on success, otherwise -1 on error.
 * and errno is set neseserilly.
 */

int _eputchar(char ch)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		buf[a++] = ch;
	return (1);
}

/**
 * _putfil_des - writes the character ch to given file descriptor
 * @ch: The char to be printed
 * @fil_des: The file descriptor
 * Return: 1 on success, otherwise -1 on error.
 * and errno is set nesesarilly.
 */

int _putfil_des(char ch, int fil_des)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fil_des, buf, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		buf[a++] = ch;
	return (1);
}

/**
 * _putsfil_des - prints the string input
 * @s: the string to be printed
 * @fil_des: the filedescriptor
 * Return: character number
 */

int _putsfil_des(char *s, int fil_des)
{
	int a = 0;

	if (!s)
		return (0);
	while (*s)
	{
		a += _putsfil_des(s++, fil_des);
	}
	return (a);
}
