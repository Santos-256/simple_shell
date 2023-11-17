#include "sshell.c"

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
	if (lineptr == NULL || n == 0)
	{
		n = 100;
		lineptr = (char *) malloc(sizeof(char) * n);
		if (lineptr == NULL)
		{
			perror("Malloc error");
			return (-1);
		}
	}


