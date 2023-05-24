#include "shell.h"

/**
 * get_history_file - this function construct path to the history file
 * @info: parameter struct containing potential argument
 * Return: 0 if successful
 */
char *get_history_file(info_t *info)
{
	char *b;
	char *d;

	d = _getenv(info, "HOME=");
	if (!d)
		return (NULL);

	b = malloc(sizeof(char) * (strlen(d) + strlen(HIST_FILE) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	_strcpy(b, d);
	_strcat(b, "/");
	_strcat(b, HIST_FILE);

	return (b);
}

/**
 * write_history - this function write the cmd history to a file
 * @info: the parameter struct containing potential argument
 * Return: 1 if successful
 */
int write_history(info_t *info)
{
	char *file = get_history_file(info);
	ssize_t fd;
	list_t *node = NULL;

	if (!file)
		return (-1);

	fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);

}
/**
 * read_history - this function read the cmd history from a file
 * @info: the parameter struct containing potential argument
 * Return: 0 if successful
 */
int read_history(info_t *info)
{
	int i;
	int last = 0;
	int linecount = 0;
	ssize_t fd;
	ssize_t rdlen;
	ssize_t fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);

}
/**
 * build_history_list - this function adds entry to a history linked list
 * @info: function parameter of a Structure containing potential argument
 * @buf: parameter showing a buffer
 * @linecount: parameter of the history linecount, histcount
 * Return: 0 if zero
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *a = NULL;

	if (info->history)
		a = info->history;
	add_node_end(&a, buf, linecount);

	if (!info->history)
		info->history = a;
	return (0);

}
/**
 * renumber_history - this function renumbers the history linked list changes
 * @info: function parameter Structure containing potential arguments.
 * Return: 0 if successful
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int a = 0;

	while (node)
	{
		node->num = a++;
		node = node->next;
	}

	info->histcount = a;

	return (info->histcount);
}

