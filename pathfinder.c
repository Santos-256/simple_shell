#include "sshell.h"
/**
 * pathfinder - A function to find the path
 * @command: The function whose path is to be found
 * Return: path
 */
char *pathfinder(char *command)
{
	char *fullpath = NULL;
	char **env;
	const char delim[] = ":";
	char *token;

	for (env = environ; *env != 0; env++)
	{
		if (strstr(*env, "PATH=") != NULL)
		{
			fullpath = *env + 5;
			break;
		}
	}
	if (fullpath == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable notfound.\n");
		exit(EXIT_FAILURE);
	}
	token = __strtok(fullpath, delim);

	while (token != NULL)
	{
		char *path = malloc(strlen(token) + strlen(command) + 2);

		if (!path)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		sprintf(path, "%s/%s", token, command);

		if (access(path, F_OK) == 0)
		{
			return (path);
		}
		free(path);
		token = __strtok(NULL, delim);
	}
	fprintf(stderr, "Error: Command not found in PATH.\n");
	exit(EXIT_FAILURE);
}
