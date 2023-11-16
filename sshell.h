#ifndef SSHELL_H
#define SSHELL_H
#define MAX_INPUT_LEN 256

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void pprompt(void);
char **parser_input(char *input);
void executioner(char **args);
char *pathfinder(char *command);
char *__strtok(char *str, const char *delimeters);
ssize_t grabline(char **lineptr, size_t *b, FILE *stream);
void exit_execution(char **args);
void cd_execution(char **args);
#endif
