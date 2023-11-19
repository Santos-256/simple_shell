#include "sshell.h"
/**
 * main - This is the main entry point to the program
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	
	while(1)
	{
		pprompt();
		if (read_input() == EOF)
			break;
	}
	return (0);
}
