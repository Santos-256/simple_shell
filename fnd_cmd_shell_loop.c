#include "shell.h"

/**
 * hsh - main shell loop program
 * @info: the parameter & info struct as return
 * @av: the argument vector of the main shell loop
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t q = 0;
	int output = 0;

	while (q != -1 && output != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		q = get_input(info);
		if (q != -1)
		{
			set_info(info, av);
			output = find_builtin(info);
			if (output == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (output == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (output);
}

/**
 * find_builtin - finds a builtin command in buffer
 * @info: the parameter & return info struct
 *
 * Return: 0 if builtin executed with no error, 1 if builtin but with error.
 * -2 if builtin signals exit()
 *
 * -1 if builtin not found
 */
int find_builtin(info_t *info)
{
	int j, built_in_output = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (j = 0; builtintbl[j].type; j++)
	{
		if (_strcmp(info->argv[0], builtintbl[j].type) == 0)
		{
			info->line_count++;
			built_in_output = builtintbl[j].func(info);
			break;
		}
	}
		return (built_in_output);
}

/**
 * find_cmd - finds a command in PATH in the buffer
 * @info: the parameter & info struct as return
 *
 * Return: void
 */

void find_cmd(info_t *info)
{
	char *path = NULL;
	int q, r;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (q = 0, r = 0; info->arg[q]; q++)
		if (!is_delim(info->arg[q], " \t\n"))
			r++;
	if (!r)
		return;
	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an execution thread to run command
 * @info: the parameter & info struct as return
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error:");
		return;
	}
		if (my_pid == 0)
		{
			if (execve(info->path, info->argv, get_environ(info)) == -1)
			{
				free_info(info, 1);
				if (errno == EACCES)
					exit(126);
			}
		}
		else
		{
			wait(&(info->status));
			if (WIFEXITED(info->status))
			{
				info->status = WEXITSTATUS(info->status);
				if (info->status == 126)
					print_error(info, "Permission denied\n");
			}
		}
}
