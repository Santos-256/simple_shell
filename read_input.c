#include "sshell.h"
#define buff_size 100
/**
 * read_input - A function to read the input from the user
 * @info: A struct for defined variables
 * Return: Number of bytes read
 */
ssize_t read_input(info_def *info)
{
	char *lineptr = NULL;
	size_t size = 0;
	ssize_t no_read;

	info->in_str = NULL;
	no_read = getline(&lineptr, &size, stdin);
	if (no_read == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			return (-1);
		}
		perror("getline");
	}
	info->in_str = lineptr;
	return (no_read);
}
