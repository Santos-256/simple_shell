#include "sshell.h"
/**
 * parser_input - A function to pass the input
 * @info: A definition struct
 * Return: An array of strings
 */
char **parser_input(info_def *info)
{
	char *token;
	int token_counter = 0;
	char delim[] = " \t\n";

	if (info->in_str == NULL)
		return (NULL);
	(info->argsv) = malloc(sizeof(char *));
	if ((info->argsv) == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	token = strtok(info->in_str, delim);
	while (token != NULL)
	{
		(info->argsv)[token_counter++] = strdup(token);
		(info->argsv) = realloc((info->argsv), (token_counter + 1) * sizeof(char *));
		if ((info->argsv) == NULL)
		{
			perror("realloc");
			free(token);
			free(info->in_str);
		}
		token = strtok(NULL, delim);
	}
	(info->argsv)[token_counter] = NULL;
	free(token);
	free(info->in_str);
	return (info->argsv);
}

/**
 * args_free - A function to free the args
 * @info: struct input
 */
void args_free(info_def *info)
{
	int i;

	if ((info->argsv) == NULL)
		return;
	for (i = 0; (info->argsv)[i] != NULL; i++)
		free((info->argsv)[i]);
	free(info->argsv);
	info->argsv = NULL;
}
