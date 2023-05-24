#include "shell.h"
/**
 * input_buf - this function buffer chained cmd by reading user input
 * @info: parameter showing a struct containing potential argument
 * @buf: function parameter indicating the address of buffer
 * @len: function parameter showing the address of len variable
 * Return: 0 if successful
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	size_t length = 0;
	ssize_t a = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
	a = getline(buf, &length, stdin);
#else
	a = _getline(info, buf, &length);
#endif
	if (a > 0)
	{
		if ((*buf)[a - 1] == '\n')
		{
			(*buf)[a - 1] = '\0';
			a--;
		}
		info->linecount_flag = 1;
		remove_comments(*buf);
		build_history_list(info, *buf, info->histcount++);
		/* if (_strchr(buf, ';'))*/
		{
			*len =a;
			info->cmd_buf = buf;
		}
	}
	}
	return (a);
}
/**
 * get_input - this function gets a line of input from user
 * @info: parameter struct containing potential argument
 * Return: 0 if successful
 */
ssize_t get_input(info_t *info)
{
	static size_t a, j, len;
	ssize_t b = 0;
	char **buff = &(info->arg), *p;
	static char *buf;

	_putchar(BUF_FLUSH);
	b = input_buf(info, &buf, &len);
	if (b == -1)
		return (-1);
	if (len)
	{
		j = a;
		p = buf + a;

		check_chain(info, buf, &j, a, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		a = j + 1;
		if (a >= len)
		{
			a = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buff = p;
		return (_strlen(p));
	}
	*buff = buf;
	return (b);
}
/**
 * read_buf - this function reads a buffer from file descriptor
 * @info: parameter struct containing potential argument
 * @buf: parameter showing the buffer
 * @i: function parameter indicating the size
 * Return: 0 if successful
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t a = 0;

	if (*i)
		return (0);
	a = read(info->readfd, buf, READ_BUF_SIZE);
	if (a >= 0)
	*i = a;
	return (a);
}
/**
 * _getline - this function gets the next line of input from STDIN
 * @info: parameter struct containing potential argument
 * @ptr: parameter of the address of pointer to buffer, preallocated or NULL
 * @length: function parameter showing the size of preallocated ptr buffer
 * Return: 0 if successful
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	ssize_t a = 0, s = 0;
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	char *p = NULL, *new_p = NULL, *c;
	size_t k;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	a = read_buf(info, buf, &len);
	if (a == -1 || (a == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
/**
 * sigintHandler - this function serves as a signal handler
 * @sig_num: function parameter indicating the signal number
 * Return: void
 */
void sigintHandler(int sig_num)
{
	(void)sig_num;

	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
