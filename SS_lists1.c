#include "shell.h"

/**
 * list_len - this function determines length of linked list
 * @h: parameter showing the pointer to first node
 * Return: 0 if successful
 */
size_t list_len(const list_t *head)
{
    size_t len = 0;
    const list_t *node = head;

    while (node != NULL)
    {
        len++;
        node = node->next;
    }

    return len;
}

/**
 * list_to_strings - this function convert str field of each node in the linked
 * list into an array of string
 * @head: parameter showing thee pointer to first node
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
    size_t len = list_len(head);
    char **strs = NULL;
    list_t *node = head;
    size_t i = 0;

    if (len == 0)
        return NULL;

    strs = malloc(sizeof(char *) * (len + 1));
    if (strs == NULL)
        return NULL;

    while (node != NULL)
    {
        strs[i] = _strdup(node->str);
        if (strs[i] == NULL)
        {
            while (i > 0)
                free(strs[--i]);
            free(strs);
            return NULL;
        }

        node = node->next;
        i++;
    }

    strs[i] = NULL;
        return strs;
}
/**
 * print_list - this function prints all elements of a list_t linked list
 * @h: function parameter indicating the pointer to first node
 * Return: 0 if successful
 */

size_t print_list(const list_t *head)
{
    size_t len = list_len(head);
    const list_t *node = head;
    size_t i;

    for (i = 0; i < len; i++)
    {
        _puts(convert_number(node->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(node->str ? node->str : "(nil)");
        _puts("\n");
        node = node->next;
    }

    return len;
}

/**
 * node_starts_with - this function searches for a node whose string start at a
 * given prefix and matches a character
 * @node: function parameter indicating the pointer to list head
 * @prefix: function parameter indicating string to match
 * @c: function parameter showing the next character after prefix to match
 * Return: 0 if successful
 */

list_t *node_starts_with(list_t *head, char *prefix, char c)
{
    list_t *node = head;

    while (node != NULL)
    {
        if (starts_with(node->str, prefix) && (c == -1 || node->str[_strlen(prefix)] == c))
            return node;

        node = node->next;
    }

    return NULL;
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
            return index;

        current = current->next;
        index++;
    }

    return -1;
}

