#include "sshell.h"
void cleanup(char *input, size_t *input_size)
{
	if (input == NULL)
		return;
	free(input);
	*input_size = 0;
	input = NULL;
}


/**
 * main - This is the main entry point for the program
 * @argc: Number of arguments passed
 * @argv: An array of the arguments passed
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t no_read;
	char **args;
	int i;

	while (1)
	{
		cleanup(input, &input_size);
		pprompt();
		no_read = getline(&input, &input_size, stdin);
		if (no_read == -1)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		args = parser_input(input);
		if (args[0] != NULL)
			executioner(args);
		else
			continue;
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	free(input);
	return (0);
}
