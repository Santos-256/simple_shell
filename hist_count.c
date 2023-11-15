#include "shell.h"

/**
 * get_history_file - gets the history file from buffer
 * @info: parameter struct
 *
 * Return: allocated string containg history file on success
 */

char *get_history_file(info_t *info)
{
	char *ptr, *ch;

	ch = _getenv(info, "HOME=");
	if (!ch)
		return (NULL);
	ptr = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));

	if (!ptr)
		return (NULL);
	buf[0] = 0;
	_strcpy(ptr, ch);
	_strcat(ptr, "/");
	_strcat(ptr, HIST_FILE);
	return (ptr);
}

/**
 * write_history - creates a file with history,
 * or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, -1 otherwise
 */

int write_history(info_t *info)
{
	ssize_t fil_des;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);


	fil_des = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fil_des == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fil_des);
		_putfd('\n', fil_des);
	}

	_putfd(BUF_FLUSH, fil_des);
	close(fil_des);
	return (1);
}


/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */

int read_history(info_t *info)
{
	int j, cncld = 0, linecount = 0;
	ssize_t fil_des, longi, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fil_des = open(filename, O_RDONLY);
	free(filename);
	if (fil_des == -1)
		return (0);
	if (!fstat(fil_des, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (longi <= 0)
		return (free(buf), 0);
	close(fil_des);

	for (j = 0; j < fsize; j++)
		if (buf[j] == '\n')
		{
			buf[j] = 0;
			build_history_list(info, buf + cncld, linecount++);
			last = j + 1;
		}
	if (last != j)
		build_history_list(info, buf + cncld, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - builds history linked list
 * @info: Structure containing potential arguments.
 * @buf: buffer
 * @linecount: the history linecount, histcount in buffer
 *
 * Return: Always 0 on success
 */

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list
 * after changes have been made
 * Return: the new historytcount from buffer
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int j = 0;

	while (node)
	{
		node->num = j++;
		node = node->next;
	}
	return (info->histcount = j);
}
