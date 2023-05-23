#include "shell.h"

/**
 * is_chain - this function checks if the current char in the buf and next char
 * form a chain
 * @info: the parameter struct containing potential argument
 * @buf: function parameter showing the character  buffer
 * @p: function parameter indicating address of current position in buf
 * Return: 1 if successful
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = '\0';
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = '\0';
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = '\0'; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}
/**
 * check_chain - this function checks if cmd chaining should continue based on
 * previous status
 * @info: the parameter struct containing potential argument
 * @buf: function parameter showing the character buffer
 * @p: parameter showing the address of current position in buf
 * @i: function parameter showing the starting position in buf
 * @len: function parameter showing length of buf
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND && info->status)
	{
		buf[i] = '\0';
		j = len;
	}
	else if (info->cmd_buf_type == CMD_OR && !info->status)
	{
		buf[i] = '\0';
		j = len;
	}

	*p = j;
}
/**
 * replace_alias - this function replaces an aliases in the tokenized string
 * @info: the parameter struct containing potential argument
 * Return: 1 if replaced successfully or 0 if otherwise
 */
int replace_alias(info_t *info)
{
	list_t *node;
	char *p;
	int i;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * replace_vars - this funuction replaces variables in the tokenized string
 * @info: the parameter struct containing potential argument
 * Return: 1 if replaced successfully, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]), _strdup(convert_number(info->status, 10, 0)));
				continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]), _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &(info->argv[i][1]), '=');
		if (node)
		{
			replace_string(&(info->argv[i]), _strdup(_strchr(node->str, '=') + 1));
		continue;
		}
		replace_string(&(info->argv[i]), _strdup(""));
	}
	return (0);
}
/**
 * replace_string - this function replaces string
 * @old: function parameter indicating the address of old string
 * @new: function parameter indicating the address of new string
 * Return: 1 if replaced, 0 if otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
