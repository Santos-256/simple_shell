#include "shell.h"

/**
 * interactive - Determines if the shell is running in interactive mode
 * @info: a pointer to a structure
 * containing information about the shell
 * Return: 1 if the shellis in interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ctr: the character to check
 * @delim: the delimeter string
 * Return: 1 if the character is a delimiter, 0 otherwise
 */

int is_delim(char ctr, char *delim)
{
	while (*delim)
		if (*delim++ == ctr)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @ctr: input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int ctr)
{
	if ((ctr >= 'a' && ctr <= 'z') || (ctr >= 'A' && ctr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int k, sing = 1, flag = 0, ret;
	unsigned int result = 0;

	for (k = 0;  str[k] != '\0' && flag != 2; k++)
	{
		if (str[k] == '-')
			sing *= -1;


		if (str[k] >= '0' && str[k] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[k] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sing == -1)
		ret = -result;
	else
		ret = result;
	return (ret);
}
