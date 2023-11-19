#include "sshell.h"

/**
 * read_input - This is a function to read the input from the user
 * @info: Takes in the struct and reads the information
 * Return: Number of lines read 
 */
ssize_t read_input()
{
	char *lineptr = NULL;
	size_t size =0;
	ssize_t no_read;

	no_read = getline(&lineptr, &size, stdin);
	if(no_read == -1)
	{
		perror("getline");
		return (-1);
	}
	return (no_read);
}
