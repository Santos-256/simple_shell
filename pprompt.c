#include "sshell.h"
/**
 * pprompt - A function to display the pprompt
 */
void pprompt(void)
{
	char *str = "#cisfun$ ";

	write(1, str, strlen(str));
}
