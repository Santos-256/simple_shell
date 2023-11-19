#include "sshell.h"

/**
 * grabline - A function that acts like the getline function
 * @lineptr: A pointer that points to a pointer pointing to the first charaacter of the line
 * @n: A pointer pointing to the size of the lineptr
 * @stream: The stream from which the line is going to be read
 * Return: The number of bytes read from the line
 */

ssize_t grabline(char **lineptr, size_t *n, FILE *stream)
{
	// Checking if the buffer is empty
	char *temp;
	int c;
	size_t i = 0;
	if (*lineptr == NULL || *n == 0)
	{
		*n = 100;
		*lineptr = (char *) malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Malloc error");
			return (-1);
		}
	}
	while ((c = fgetc(stream) != EOF) && (c != '\n'))
	{
		// Resizing the buffer in case the string is longer
		if (i + 1 >= *n)
		{
			*n *= 2;
			temp = (char *) realloc(*lineptr, *n);
			if (temp == NULL)
			{
				perror("Realloc error");
				return (-1);
			}
			*lineptr = temp;
		}
		(*lineptr)[i++] = (char)c;
	}
	if (c == EOF && i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
