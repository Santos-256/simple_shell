#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line,
 * preceded in the program with line numbers, initially 0.
 * @info: Structure containing potential arguments.
 * Used to maintain the program prototype.
 * Return: 0 if success
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - deletes an alias from string
 * @info: parameter struct
 * @str: the string alias
 * Return: 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *ptr, ch;
	int result;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	ch = *ptr;
	*ptr = 0;
	result = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = ch;
	return (result);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: 0 (success), 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));


	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node to print out
 * Return: 0 (success), 1 on error
 */

int print_alias(list_t *node)
{
	char *ptr = NULL, *p = NULL;
	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (p = node->str; p <= ptr; p++)
			_putchar(*p);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - replicates the alias builtin.
 * @info: Structure containing potential arguments.
 * Used to maintain the program prototype.
 * Return: Always 0 (success)
 */

int _myalias(info_t *info)
{
	int a = 0;
	char *ptr = NULL;
	list_t *node = NULL;


	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}

		return (0);
	}

	for (a = 1; info->argv[a]; a++)
	{
		ptr = _strchr(info->argv[a], '=');
		if (ptr)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}
	return (0);
}
