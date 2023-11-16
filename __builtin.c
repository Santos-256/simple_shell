#include "sshell.h"
/**
 * exit_execution - A function to implement the exit built in
 * @args: array of characters to be checked
 */
void exit_execution(char **args)
{
	if (args[1] != NULL)
	{
		int exxitstatus = atoi(args[1]);

		exit(exxitstatus);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
/**
 * cd_execution - A function to implement the cd builtin
 * @args: array of characters to be checked
 */
void cd_execution(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Error: Missing argument for cd .\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
