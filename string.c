#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to be checked
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str++)
		j++;
	return (j);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs in buffer
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return: negative if str1 < str2,
 * positive if str1 > str2, zero if str1 == str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (result);
}
