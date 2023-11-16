#include "sshell.h"
/**
 * __strtok - An impelematation of strtok
 * @str: string to be tokenised
 * @delimeters: The delimeters for tokenisation
 * Return: Tokenised string
 */
char *__strtok(char *str, const char *delimeters)
{
	static char *current;
	char *token_start = current;

	if (str != NULL)
	{
		current = str;
	}
	while (*current != '\0' && strchr(delimeters, *current) != NULL)
	{
		current++;
	}
	if (*current == '\0')
	{
		return (NULL);
	}
	while (*current != '\0' && strchr(delimeters, *current) == NULL)
	{
		current++;
	}
	if (*current != '\0')
	{
		*current = '\0';
		current++;
	}
	return (token_start);

}
