#include <stdio.h>
#include "shell.h"

/**
 * _myhistory - this function is responsible for showing the shell cmd history
 * @info: function parameter indicating a Struct containing potential arguments
 *  Return: 0 if successful
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - this function removes an alias from the list of alias
 * @info: function parameter indicating the parameter structure containing argu
 * @str: function parameter indicating the string alias to be removed
 * Return: 0 if successful
 */

int unset_alias(info_t *info, char *str)
{
	char *a;
	char b;
	int c;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	c = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = b;
	return (c);
}

/**
 * set_alias - this function sets alias to string
 * @info: function parameter indicating a struct containing potential argument
 * @str: function parameter indicating the string alias to be set
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);

}
/**
 * print_alias - this function prints an individual alias from the alias list
 * @node: parameter indicating the alias node
 * Return: 0 if successful
 */

int print_alias(list_t *node)
{
	char *d = NULL;
	char *c = NULL;

	if (node)
	{
		d = _strchr(node->str, '=');
		for (d = node->str; c <= d; c++)
		_putchar(*c);
		_putchar('\'');
		_puts(d + 1);
		_puts("'\n");
		return (0);
	}
	return (1);

}
/**
 * _myalias - this function mimic the behaivour of the alias builtin command
 * @info: function parameter indicating the struct containing potential argum
 * Return: 0 if successful
 */
int _myalias(info_t *info)
{
	int i;
	char *p;

	if (info->argc == 1)
	{
		list_t *node = info->alias;

		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
		{
			set_alias(info, info->argv[i]);

		}
		else
		{
			print_alias(node_starts_with(info->alias, info->argv[i], '='));

		}

	}
	return (0);
}

