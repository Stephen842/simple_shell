#include "shell.h"

/**
 * _myenv - this function print the current environment
 * @info: function parameter indicating struct containing potential argument
 * Return: 0 if sucessfully
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - function returns the value of an environment variable by it name
 * @info: function parameter indicating structure containing potential argument
 * @name: function parameter indicating the name of the environment variable
 * Return: the value of the environment
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - this function is use to create a new variable or
 * to modify an existing one
 * @info: function parameter indicating a struct containing potential arguments
 * Return: 0 if successful
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (setenv(info->argv[1], info->argv[2], 1) == -1)
		return (0);
	return (1);
}

/**
 * _myunsetenv - this function is responsible for removing one or more
 * environment variable
 * @info: function parameter indicating struct containing potential argument
 * Return: 0 if successful
 */

int _myunsetenv(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (a = 1; a < info->argc; a++)
	{
		if (unsetenv(info->argv[a]) == -1)
		{
			perror("unsetenv");
			return (1);
		}
	}
	return (0);
}

/**
 * populate_env_list - this function is use to populate the list of env variabl
 * @info: function parameter of a structure containing potential argument
 * Return: 0 if successfully
 */

int populate_env_list(info_t *info)
{
	size_t a;
	list_t *node = NULL;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);

	info->env = node;
	return (0);
}

