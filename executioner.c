#include "sshell.h"
/**
 * executioner - A program that executes a file by creating a process
 * @args: It takes in an array of strings
 */
void executioner(char **args)
{
	pid_t child_pid;
	char *fullpath;

	if (args[0] == NULL)
		return;
	if (strcmp(args[0], "exit") == 0)
	{
		exit_execution(args);
		return;
	}
	if (strcmp(args[0], "cd") == 0)
	{
		cd_execution(args);
		return;
	}
	fullpath = pathfinder(args[0]);
	if (fullpath == NULL)
		return;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(fullpath, args, environ) == -1)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
