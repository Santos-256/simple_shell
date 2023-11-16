#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @s: the string to be duplicated
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int length = 0;
	char *result;

	if (s == NULL)
		return (NULL);
	while (*s++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--s;
	return (result);
}

/**
 *_puts - prints an input string
 *@s: the string to printe
 *
 * Return: void
 */
void _puts(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j] != '\0')
	{
		_putchar(s[j]);
		j++;
	}
}

/**
 * _putchar - writes the character ch to stdout
 * @ch: The character to print
 *
 * Return: 1 (success)
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buf[j++] = ch;
	return (1);
}
