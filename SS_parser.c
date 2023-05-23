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
if (!path || stat(path, &st) != 0)
return (0);

return (S_ISREG(st.st_mode));
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
int length = stop - start;
char *buf = malloc((length + 1) * sizeof(char));
int i;
if (buf == NULL)
return (NULL);

for (i = 0; i < length; i++)
buf[i] = pathstr[start + i];
buf[length] = '\0';
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
int start = 0;
int i = 0;
char *path = NULL;

if (!pathstr)
return (NULL);

if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}

while (pathstr[i] != '\0')
{
if (pathstr[i] == ':')
{
path = dup_chars(pathstr, start, i);
if (path == NULL)
return (NULL);

if (_strlen(path) == 0)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}

if (is_cmd(info, path))
return (path);

start = i + 1;
}

i++;

}
return (NULL);
}

