#include "sshell.h"

/**
 * grabline - A function used as the getlne function.
 *
 */
int main(void)
{
	char *lineptr = "this is apedo";
	size_t n = 0; 
	ssize_t n_read;

	n_read = getline(&lineptr, &n, stdin);

	if (n_read == -1)
	{
		printf("Error on getline");
		return -1;
	}
	else
	{
		printf("n_read_____ %lu\n",n_read);
	}
	free(lineptr);
	return (0);
}
