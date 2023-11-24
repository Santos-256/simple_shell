#include "sshell.h"
/**
 * pprompt - This is a function to display the shell
 */
void pprompt(void)
{
	char *p = "#cisfun$ ";

	write(1, p, strlen(p));
}
