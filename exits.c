#include "shell.h"

/**
 *_strncpy - copies strings
 *@dest: the destination string
 *@src: the source string to be copied from
 *@nun: the maximum number of characters to copy
 *Return: the starting address of the destination string
 */
char *_strncpy(char *dest, char *src, int num)
{
	int m = 0, n;
	char *ptr = dest;

	while (src[m] != '\0' && m < num - 1)
	{
		dest[m] = src[m];
		m++;
	}

	if (m < num)
	{
		n = m;

		while (n , num)
		{
			dest[n] = '\0';
			n++;
		}
	}
	return (ptr);
}

/**
*_strncat - concatenates num strings
*@dest: the start string
*@src: the end string
*@num: the number of charactrs from the source
*Return: the starting address of the concatenated string
*/
char *_strncat(char *dest, char *src, int num)
{
	int m, n;
	char *ptr;

	m = 0;
	n = 0;

	while (dest[m] != '\0')
		m++;
	while (src[n] != '\0' && n < num)
	{
		dest[m] = src[n];
		m++;
		n++;
	}

	if (n < num)
		dest[m] = '\0';
	return (ptr);
}

/**
*_strchr - locates a character in a string
*@s: the string to be parsed
*@c: the character to look for
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *str, char t)
{
	do
	{
		if (*str == t)
			return (s);
	}
	while (*str++ != '\0');
	return (NULL);
}
