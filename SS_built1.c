#include <stdio.h>
#include "shell.h"
/**
 * _myhistory - this function is responsible for showing the shell cmd history
 * @info: function parameter indicating a Struct containing potential arguments
 *  Return: 0 if successful
 */

int _myhistory(info_t *info)
{
list_t *node = info->history;
int count = 0;

while (node != NULL)
{
printf("%d %s\n", count, node->str);
node = node->next;
count++;
}

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
list_t **head = &(info->alias);
list_t *current = *head;
list_t *prev = NULL;

while (current != NULL)
{
if (_strcmp(current->str, str) == 0)
{
if (prev == NULL)
*head = current->next;
else
prev->next = current->next;

free(current->str);
free(current);
return (0);
}

prev = current;
current = current->next;
}
return (1);
}

/**
 * set_alias - this function sets alias to string
 * @info: function parameter indicating a struct containing potential argument
 * @str: function parameter indicating the string alias to be set
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
list_t *new_node = malloc(sizeof(list_t));
list_t **head = &(info->alias);
list_t *current = *head;

if (new_node == NULL)
return (1);

new_node->str = _strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (1);
}
new_node->next = NULL;
if (current == NULL)
{
*head = new_node;
}
else
{
while (current->next != NULL)
current = current->next;

current->next = new_node;
}
return (0);
}
/**
 * print_alias - this function prints an individual alias from the alias list
 * @node: parameter indicating the alias node
 * Return: 0 if successful
 */

int print_alias(list_t *node)
{
if (node != NULL)
{
printf("%s\n", node->str);
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
		while (node != NULL)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i] != NULL; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p != NULL)
		{
			*p = '\0';
			unset_alias(info, info->argv[i]);
			*p = '=';
			set_alias(info, info->argv[i]);

		}
		else
		{
			print_alias(node_starts_with(info->alias, info->argv[i], '='));

		}

		return (0);
	}
}

