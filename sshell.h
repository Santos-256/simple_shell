#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//A struct with all the user defined variables

typedef struct info
{
	//read_input
	char **lineptr;
	size_t size;
	FILE *stream;

} info_def;

ssize_t read_input();
ssize_t grabline(char **lineptr, size_t *n, FILE *stream);
void pprompt(void);



#endif
