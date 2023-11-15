#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter
 * @buf: address of buffer(&buf)
 * @logi: address of longi variable
 *
 * Return: bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t v = 0;
	size_t longi_p = 0;

	if (!*longi)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
		#if USE_GETLINE
		v = getline(buf, &longi_p, stdin);
		#else
		v = _getline(info, buf, &longi_p);
		#endif
		if (v > 0)
		{
			if ((*buf)[v - 1] == '\n')
			{
				(*buf)[v - 1] = '\0';
				v--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*longi = v;
				info->cmd_buf = buf;
			}
		}
	}
		return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct info
 *
 * Return: bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t j, k, longi;
	ssize_t v = 0;
	char **buf_b = &(info->arg), *ptr;

	_putchar(BUF_FLUSH);
	v = input_buf(info, &buf, &longi);
	if (v == -1)
		return (-1);
	if (longi)
	{
		k = j;
		ptr = buf + k;

		check_chain(info, buf, &k, j, longi);
		while (k < longi)
		{
			if (is_chain(info, buf, &k))
				break;
			k++;
		}
		j = k + 1;
		if (j >= longi)
		{
			j = longi = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_b = ptr;
		return (_strlen(ptr));
	}
	*buf_b = buf;
	return (v);
}

/**
 * read_buf - reads a buffer content
 * @info: parameter struct
 * @buf: buffer
 * @z: size
 *
 * Return: v
 */

ssize_t read_buf(info_t *info, char *buf, size_t *z)
{
	ssize_t v = 0;

	if (*z)
		return (0);
	v = read(info->readfd, buf, READ_BUF_SIZE);
	if (v >= 0)
		*z = v;
	return (v);
}

/**
 * _getline - gets the next line of input from standard input
 * @info: parameter struct info
 * @p: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated p buffer if not NULL
 *
 * Return: str
 */
int _getline(info_t *info, char **p, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, longi;
	size_t k;
	ssize_t v = 0, s = 0;
	char *ptr = NULL, *new_p = NULL, *ch;

	ptr = *p;
	if (ptr && length)
		str = *length;
	if (j == longi)
		j = longi = 0;
	v = read_buf(info, buf, &longi);
	if (v == -1 || (v == 0 && longi == 0))
		return (-1);
	ch = _strchr(buf + j, '\n');
	k = ch ? 1 + (unsigned int)(ch - buf) : longi;
	new_p = _realloc(ptr, str, str ? str + k : k + 1);
	if (!new_p)
		return (ptr ? free(ptr), -1 : -1);
	if (str)
		_strncat(new_p, buf + j, k - j);
	else
		_strncpy(new_p, buf + j, k - j + 1);
	str += k - j;
	j = k;
	ptr = new_p;


	if (length)
		*length = str;
	*p = ptr;
	return (str);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_n: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_n)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
