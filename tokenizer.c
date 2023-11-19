#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @s: the input string
 * @delim: the delimeter string
 * Return: a pointer to an array of strings, otherwise NULL on failure
 */
char **strtow(char *s, char *delim)
{
	int o, p, q, r, numwords = 0;
	char **str;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	s = 0;
	for (o = 0; s[o] != '\0'; o++)
	{
		if (!is_delim(s[o], delim)  && (is_delim(s[o + 1], delim) || !s[o + 1]))
			numwords++;
	}
	if (numwords == 0)
		return (NULL);
	str = malloc((1 + numwords) * sizeof(char *));
	if (!str)
		return (NULL);
	for (o = 0, p = 0; p < numwords; p++)
	{
		while (is_delim(s[o], delim))
			o++;
		q = 0;
		while (!is_delim(s[o + q], delim) && s[o + q])
			q++;
		str[p] = malloc((q + 1) * sizeof(char));
		if (!str[p])
		{
			for (q = 0; q < p; q++)
				free(str[q]);
			free(str);
			return (NULL);
		}
		for (r = 0; r < q; r++)
			str[p][r] = s[o++];
		str[p][r] = 0;
	}
	str[p] = NULL;
	return (str);
}

/**
 * **strtow2 - splits a string into words
 * @s: the input string
 * @delim: the delimeter
 * Return: a pointer to an array of strings, otherwise NULL on failure
 */
char **strtow2(char *s, char delim)
{

	int o, p, q, r, n_words = 0;
	char **str;

	if (s == NULL || s[0] == 0)
	return (NULL);
	for (o = 0; s[o] != '\0'; o++)
	if ((s[o] != delim && s[o + 1] == delim) ||
			(s[o] != delim && !s[o + 1]) || s[o + 1] == delim)
		n_words++;
	if (n_words == 0)
		return (NULL);
	str = malloc((1 + n_words) * sizeof(char *));
	if (!str)
		return (NULL);
	for (o = 0, p = 0; p < n_words; p++)
	{
		while (s[o] == delim && s[o] != delim)
			o++;
		q = 0;
		while (s[o + q] != delim && s[o + q] && s[o + q] != delim)
			q++;
		str[p] = malloc((q + 1) * sizeof(char));
		if (!str[p])
		{
			for (q = 0; q < p; q++)
				free(str[q]);
			free(str);
			return (NULL);
		}
		for (r = 0; r < q; r++)
			str[p][r] = s[o++];
		str[p][r] = 0;
	}
	str[p] = NULL;
	return (str);
}
