#include "shell.h"
/**
 * history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int History(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * pre_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int pre_alias(info_t *info, char *str)
{
	char *a, b;
	int res;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	res = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = b;
	return (res);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (pre_alias(info, str));

	pre_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print- prints an alias string
 * @nod: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print(list_t *nod)
{
	char *a = NULL, *x = NULL;

	if (nod)
	{
		x = _strchr(nod->str, '=');
		for (x = nod->str; x <= a; x++)
			_putchar(*x);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *a = NULL;
	list_t *nod = NULL;

	if (info->argc == 1)
	{
		nod = info->alias;
		while (nod)
		{
			print_alias(nod);
			nod = nod->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		a = _strchr(info->argv[i], '=');
		if (a)
			set_alias(info, info->argv[i]);
		else
			print_alias(nod_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
