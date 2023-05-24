#include "shell.h"
/**
 * clear_info - this funnction create a struct by setting various field to zero
 * @info: function parameter indicating a struct address
 * Return: 0 if successful
 */

void clear_info(info_t *info)
{
	info->path = NULL;
	info->argc = 0;
	info->arg = NULL;
	info->argv = NULL;
}
/**
 * set_info - this function initializes info_t struct with information from arg
 * @info: parameter showing structure address
 * @av: this parameter is an argument vector
 * Return: 0 if successful
 */

void set_info(info_t *info, char **av)
{
	int i;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}

}
/**
 * free_info - this function frees allocated memory and reset field in the info
 * @info: struct address
 * @all: show true if freeing all fields
 * Return: 0 if successful
 */
void free_info(info_t *info, int all)
{
	info->path = NULL;
	ffree(info->argv);
	info->argv = NULL;

	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);

	}
}
