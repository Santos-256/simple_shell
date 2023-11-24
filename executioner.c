#include "sshell.h"

/**
 * executioner - A function to execute the files
 * @info: a struct containing all
 * Return: 0 when successful
 */

int executioner(info_def *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if ((info->argsv)[0] == NULL)
			return (0);
		if (execve(((info->argsv)[0]), (info->argsv), NULL) == -1)
		{
			perror("Execve");
			return (-1);
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}

