#include "sshell.h"

/**
 * pprompt - A function that runs prints the prompt
 */
void pprompt(void)
{
	char *prompt = "#cisfun$ ";
	write(1, prompt, strlen(prompt));
}
