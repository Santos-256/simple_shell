#include "sshell.h"
int check_executable(char *path)
{
	if (path == NULL)
	{
		return (1);
	}
	if (access(path, F_OK | X_OK) == 0)
	{
		return (0);
	}
	return (1);
}
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
	
	if (check_executable(command) == 0)
		return (command);
	for (env = environ; *env != 0; env++)
	{
		if (strstr(*env, "PATH=") != NULL)
		{
			fullpath = strdup(*env + 5);
			break;
		}
	}
	if (fullpath == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable notfound.\n");
		return (NULL);
	}
	token = strtok(fullpath, delim);
	while (token != NULL)
	{
		char *path = malloc(strlen(token) + strlen(command) + 2);
		
		if (!path)
		{
			perror("Memory allocation error");
			free(fullpath);
			return (NULL);
		}
		sprintf(path, "%s/%s", token, command);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(fullpath);
			return (path);
		}
		free(path);
		token = strtok(NULL, delim);
	}
	fprintf(stderr, "./hsh : No such file or directory");
	free(fullpath);
	return (NULL);
}
