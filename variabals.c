#include "shell.h"

/**
 * is_chain - checks if current character in buf is a chain delim
 * @info: the struct
 * @buf: the char buffer
 * @ptr: address of new position in buffer(&ptr)
 *
 * Return: 1 if chain delim, otherwise 0
 */
int is_chain(info_t *info, char *buf, size_t *ptr)
{
	size_t k = *ptr;

	if (buf[j] == '|' && buf[k + 1] == '|')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';')
	{
		buf[k] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = k;
	return (1);
}

/**
 * check_chain - checks chaining based on last status
 * @info: the struct of parameter
 * @buf: the char buffer
 * @ptr: address of current position in buffer (&ptr)
 * @initial: Initial position in buffer
 * @longi: length of the buffer
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *ptr,
		size_t initial, size_t longi)
{
	size_t k = *ptr;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[initial] = 0;
			k = longi;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[initial] = 0;
			k = longi;
		}
	}
	*ptr = k;
}

/**
 * replace_alias - takes place of an aliases in the tokenized string
 * @info: the struct of parameters
 *
 * Return: 1 if the alias is replaced, otherwise 0
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *ch;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ch = _strchr(node->str, '=');
		if (!ch)
			return (0);
		ch = _strdup(ch + 1);
		if (!p)
			return (0);
		info->argv[0] = ch;
	}
	return (1);
}

/**
 * replace_vars - replaces variabals in the tokenized string
 * @info: the struct of parameters
 *
 * Return: 1 if var is replaced, otherwise 0
 */
int replace_vars(info_t *info)
{
	int j = 0;
	list_t *node;

	for (j = 0; info->argv[j]; j++)
	{
		if (info->argv[j][0] != '$' || !info->argv[j][1])
			continue;
		if (!_strcmp(info->argv[j], "$?"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[j], "$$"))
		{
			replace_string(&(info->argv[j])
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
		if (node)
		{
			replace_string(&(info->argv[j]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[j], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - replaces string
 * @bef: address of old string to be replaced (&end)
 * @aft: new string to replace
 *
 * Return: 1 if the old string is replaced, otherwise 0
 */

int replace_string(char **bef, char *aft)
{
	free(*bef);
	*bef = aft;
	return (1);
}
