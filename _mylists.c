#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: string field of node
 * @n: number of node index used by history
 *
 * Return: size of list in buffer
 */

list_t *add_node(list_t **head, const char *str, int n)
{
	list_t *n_d; /* nd = new_head */

	if (!head)
		return (NULL);
	n_d = malloc(sizeof(list_t));
	if (!n_d)
		return (NULL);
	_memset((void *)n_d, 0, sizeof(list_t));
	n_d->n = n;
	if (str)
	{
		n_d->str = _strdup(str);
		if (!n_d->str)
		{
			free(n_d);
			return (NULL);
		}
	}
	n_d->next = *head;
	*head = n_d;
	return (n_d);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @n: number of node index used by history
 *
 * Return: size of list in buuffer
 */

list_t *add_node_end(list_t **head, const char *str, int n)
{
	list_t *node;
	list_t *n_d;

	if (!head)
		return (NULL);
	node = *head;
	n_d = malloc(sizeof(list_t));
	if (!n_d)
		return (NULL);
	_memset((void *)n_d, 0, sizeof(list_t));
	n_d->n = n;
	if (str)
	{
		n_d->str = _strdup(str);
		if (!n_d->str)
		{
			free(n_d);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_d;
	}

	else
		*head = n_d;
	return (n_d);
}

/**
 * print_list_str - prints only the string element of a list_t linked list
 * @ptr: pointer to first node
 *
 * Return: size of list
 */

size_t print_list_str(const list_t *ptr)
{
	size_t j = 0;


	while (ptr)
	{
		_puts(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		j++;
	}
	return (j);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (j == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		j++;
		prev_node = node;
		node = node->next;
	}
}

/**
 * free_list - frees all nodes of a list in buffer
 * @head_p: address of pointer to head node
 *
 * Return: void
 */

void free_list(list_t **head_p)
{
	list_t *node, *next_node, *head;

	if (!head_p || !*head_p)
		return;
	head = *head_p;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_p = NULL;
}
