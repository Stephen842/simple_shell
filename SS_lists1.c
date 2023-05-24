#include "shell.h"

/**
 * list_len - this function determines length of linked list
 * @h: parameter showing the pointer to first node
 * Return: 0 if successful
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}

	return (len);
}

/**
 * list_to_strings - this function convert str field of each node in the linked
 * list into an array of string
 * @head: parameter showing thee pointer to first node
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	char **strs;
	list_t *node = head;
	size_t a = list_len(head);
	char *str;
	size_t b;

	if (!head || !a)
		return (NULL);
	strs = malloc(sizeof(char *) * (a + 1));
	if (!strs)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[a] = str;
	}
	strs[a] = NULL;
	return (strs);
}

/**
 * print_list - this function prints all elements of a list_t linked list
 * @h: function parameter indicating the pointer to first node
 * Return: 0 if successful
 */

size_t print_list(const list_t *h)
{
	size_t a;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - this function searches for a node whose string start at a
 * given prefix and matches a character
 * @node: function parameter indicating the pointer to list head
 * @prefix: function parameter indicating string to match
 * @c: function parameter showing the next character after prefix to match
 * Return: 0 if successful
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *a = NULL;

	while (node)
	{
		a = starts_with(node->str, prefix);
		if (a && ((c == -1) || (*a == c)))
			return (node);
		node = node->next;
	}
	return (NULL);

}

/**
 * get_node_index - function parameter gets the index of a node in a linked lis
 * @head: function parameter showing the pointer to list head
 * @node: function parameter indicating the pointer to the node
 * Return: 0 if successful
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;
	list_t *current = head;

	while (current != NULL)
	{
		if (current == node)
			return (index);

		current = current->next;
		index++;
	}

	return (-1);
}

