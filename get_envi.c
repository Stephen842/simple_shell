#include "shell.h"
/**
 * get_env - returns the string array copy of our environ
 * @infor: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_env(info_t *infor)
{
	if (!infor->environ || infor->env_changed)
	{
		infor->environ = list_to_strings(infor->env);
		infor->env_changed = 0;
	}

	return (infor->environ);
}

/**
 * unset_env - Remove an environment variable
 * @infor: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @v: the string env var property
 */
int unset_env(info_t *infor, char *v)
{
	list_t *node = infor->env;
	size_t i = 0;
	char *p;

	if (!node || !v)
		return (0);

	while (node)
	{
		p = starts_with(node->str, v);
		if (p && *p == '=')
		{
			infor->env_changed = delete_node_at_index(&(infor->env), i);
			i = 0;
			node = infor->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * set_env - Initialize a new environment variable,
 *             or modify an existing one
 * @infor: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @v: the string env var property
 * @val: the string env var value
 *  Return: Always 0
 */
int set_env(info_t *infor, char *v, char *val)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!v || !val)
		return (0);

	buf = malloc(_strlen(v) + _strlen(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, v);
	_strcat(buf, "=");
	_strcat(buf, val);
	node = infor->env;
	while (node)
	{
		p = starts_with(node->str, v);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			infor->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(infor->env), buf, 0);
	free(buf);
	infor->env_changed = 1;
	return (0);
}
