#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address of the pointer
 * @p: address of the pointer to be freed
 *
 * Return: 1 if freed, otherwise 0.
 */

int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
