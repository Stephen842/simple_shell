#include "shell.h"
/**
 * is_cmd - this function determines if a file specified by it path
 * is an executable command
 * @info: function parameter indicating the info struct containing potential ar
 * @path: function parameter showing the path to the file
 * Return: 0 if true
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	
	if (!path || stat(path, &st))
		return (0);

	if (S_IFREG & st.st_mode)
		return (1);
	return (0);
}

/**
 * dup_chars - this function duplicate a portion of a string specified by
 * the starting and stopping indices
 * @pathstr: function parameter indicating the PATH string
 * @start: function parameter showing the starting index
 * @stop: function parameter showing the stopping index
 * Return: pointer to a new buffer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	int len = 0;
	static char buf[1024];
	int a = 0,

	for (len = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[len++] = pathstr[a];
	buf[len] = 0;
	return (buf);

}
/**
 * find_path - this function searches for a cmd in the PATH string
 * @info: the info struct containing potential argument
 * @pathstr: parameter indicating the PATH string
 * @cmd: parameter indicating the command to find
 * Return: the full command path
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int a = 0;
	char *path;
	int Curr = 0;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, Curr, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[a])
				break;
			Curr = a;
		}
		a++;
	}
	return (NULL);

}

