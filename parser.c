#include "sshell.h"
/**
 * parser_input - A function that parses the input
 * @input: The input string to be parsed and tokenised
 * Return: An array of strings
 */
char **parser_input(char *input)
{
	const char delim[] = " \t\n";
	char **args = malloc(sizeof(char *));
	int argcount;
	char *token;

	if (!args)
	{
		perror("Memorry allocation error");
		exit(EXIT_FAILURE);
	}
	argcount = 0;
	token = __strtok(input, delim);
	while (token != NULL)
	{
		args[argcount++] = strdup(token);
		args = realloc(args, (argcount + 1) * sizeof(char *));

		if (!args)
		{
			perror("Memmory allocation error");
			exit(EXIT_FAILURE);
		}
		token = __strtok(NULL, delim);
	}
	args[argcount] = NULL;
	return (args);
}
