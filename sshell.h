#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/** A struct for variables**/
/**
 * struct all_thee - A struct containing all the necessary arguments
 */
typedef struct all_thee
{
	int argc;
	char **argsv;
	char *in_str;
} info_def;

void pprompt(void);
ssize_t read_input(info_def *info);
char **parser_input(info_def *info);
void args_free(info_def *info);
int executioner(info_def *info);
void intialiser(info_def *info);

#endif
