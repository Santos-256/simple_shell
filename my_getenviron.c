#include "shell.h"

/**
 * get_environ - returns the string array copy of the env
 * @info: Structure containing potential arguments
 * Used to maintain the prototype.
 * Return: Always 0 on success
 */

char **get_env(info_t *info)
{
	if (!info->env || info->env_changed)
	{
		info->env = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->env);
}

/**
 * _unsetenv - Deletes an environment variable
 * @info: Structure containing potential arguments.
 * Used to * maintain theprototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t k = 0;
	char *ptr;

	if (!node || !var)
		return (0);
	while (node)
	{
		ptr = starts_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), k);
			k = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		k++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Modifies and initializes a new environment variable
 * or an existing one
 * @info: Structure containing potential arguments
 * maintains prototype.
 * @var: the string environ
 * @value: the string env var value
 *  Return: Always 0 on success
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *ptr;

	if (!var || !value)
		return (0);
	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->env;

	while (node)
	{
		ptr = starts_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
