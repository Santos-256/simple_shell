#include "sshell.h"

/**
 *  main - This is the main entry point to the program
 *
 *  Return: (0) on success
 */
int main(void)
{
	info_def *info;

	info = malloc(sizeof(info_def));
	if (info == NULL)
	{
		perror("malloc");
		return (-1);
	}
	while (1)
	{
		pprompt();
		if (read_input(info) == -1)
		{
			perror("read_input");
			free(info->in_str);
			free(info);
			return (-1);
		}
		parser_input(info);
		executioner(info);
		args_free(info);

	}
	if ((info->in_str) != NULL)
		free(info->in_str);
	free(info);
	return (0);
}
