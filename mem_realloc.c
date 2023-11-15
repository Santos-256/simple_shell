#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@ptr: the pointer to the memory area
 *@b: the byte to fill *ptr with
 *@num: the amount of bytes to be filled
 *Return: (ptr) a pointer to the memory area ptr
 */

char *_memset(char *ptr, char b, unsigned int num)
{
	unsigned int j;

	for (j = 0; j < num; j++)
		ptr[j] = b;
	return (ptr);
}

/**
 * ffree - frees a string of strings in buffer
 * @strstr: string of strings
 */

void ffree(char **strstr)
{
	char **ret = strstr;

	if (!strstr)
		return;
	while (*strstr)
		free(*strstr++);
	free(ret);
}
/**
 * _realloc - reallocates a block of memory in program
 * @p: pointer to previous malloc'ated block
 * @old_size: byte size of previous block in buffer
 * @new_size: byte size of new block in buffer
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!p)
		return (malloc(new_size));
	if (!new_size)
		return (free(p), NULL);
	if (new_size == old_size)
		return (p);
	p = malloc(new_size);
	if (!ptr)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		ptr[old_size] = ((char *)p)[old_size];
	free(p);
	return (ptr);
}
