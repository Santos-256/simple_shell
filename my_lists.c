#include "shell.h"

/**
 * list_len - determines length of linked list
 * @ptr: pointer to first node
 *
 * Return: size of list in buffer
 */

size_t list_len(const list_t *ptr)
{
	size_t j = 0;

	while (ptr)
	{
		ptr = ptr->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - returns an array of strings of the list string
 * @head: pointer to first node
 *
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t k = list_len(head), m;
	char **str;
	char *s;

	if (!head || !k)
		return (NULL);
	str = malloc(sizeof(char *) * (k + 1));
	if (!s)
		return (NULL);
	for (k = 0; node; node = node->next, k++)
	{
		s = malloc(_strlen(node->s) + 1);
		if (!str)
		{
			for (m = 0; m < k; m++)
				free(str[m]);
			free(str);
			return (NULL);
		}
		s = _strcpy(s, node->s);
		str[k] = s;
	}
	str[k] = NULL;
	return (str);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @ptr: pointer to first node
 *
 * Return: size of list in buffer
 */

size_t print_list(const list_t *ptr)
{
	size_t k = 0;

	while (ptr)
	{
		_puts(convert_number(ptr->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		k++;
	}
	return (ptr);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @fix: string to match
 * @ch: the next char after prefix to match
 *
 * Return: match node, otherwise null
 */

list_t *node_starts_with(list_t *node, char *fix, char ch)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = starts_with(node->str, fix);
		if (ptr && ((ch == -1) || (*ptr == ch)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @ptr: pointer to list head
 * @p: pointer to the node
 *
 * Return: index of node otherwise -1
 */

ssize_t get_node_index(list_t *ptr, list_t *p)
{
	size_t k = 0;

	while (ptr)
	{
		if (ptr == p)
			return (k);
		ptr = ptr->next;
		k++;
	}
	return (-1);
}
