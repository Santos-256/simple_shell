#include "shell.h"

/**
 * clear_info - modifies info_t struct
 * @info: struct address info
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - modifies info_t struct
 * @info: struct address
 * @av: argument vector
 */

void set_info(info_t *info, char **av)
{
	int k = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (k = 0; info->argv && info->argv[k]; k++);
		info->argc = k;
		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct of the program
 * @info: struct address
 * @fr: true if freeing all fields
 */
void free_info(info_t *info, int fr)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		f (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
