#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments.
 * Used to maintain theprototype.
 * Return: 0 (success)
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - searches the value of an environment  variable in the list
 * @info: Structure containing potential arguments.
 * Used to maintain the prototype
 *
 * @name: environment variable name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - modifies environment variables in the program
 * @info: Structure containing potential arguments
 * Used to maintain the program prototype.
 *
 * Return: 0 (success)
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - deletes one or more environment variable
 * @info: Structure containing potential arguments.
 * Used to maintain the program prototype.
 *
 * Return: 0 (success)
 */

int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}

	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);
	return (0);
}

/**
 * populate_env_list - populates environ linked list
 * with the values from an array
 * @info: Structure containing potential arguments
 *  Used to maintain the program prototype.
 *  Return: Always 0 if success
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t t;

	for (t = 0; environ[t]; t++)
		add_node_end(&node, environ[t], 0);
	info->env = node;
	return (0);
}

