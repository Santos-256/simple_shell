#include "sshell.h"
/**
 * grabline - This is an implementation of getline function
 * @lineptr: A pointer to the string of characters
 * @b: size of characters passed
 * @stream: Source of the character or string to be read
 * Return: Number of characters read
 */

ssize_t grabline(char **lineptr, size_t *b, FILE *stream)
{
	size_t characters_read = 0;
	int f;

	if (*lineptr == NULL || *b == 0)
	{
		*b = 128;
		*lineptr = (char *)malloc(*b);
		if (*lineptr == NULL)
		{
			perror("malloc");
			return (-1);
		}
	}
	while ((f = fgetc(stream)) != EOF && f != '\n')
	{
		if (characters_read == *b - 1)
		{
			*b *= 2;
			*lineptr = (char *) realloc(*lineptr, *b);
			if (*lineptr == NULL)
			{
				perror("realloc");
				return (-1);
			}
		}
		(*lineptr)[characters_read++] = (char)f;
	}
	if (characters_read == 0 && f == EOF)
	{
		return (-1);
	}
	(*lineptr)[characters_read] = '\0';
	return (characters_read);
}
