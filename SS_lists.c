#include "shell.h"

/**
 * add_node - this function adds a node to the start of the list
 * @head: parameter showing the address of pointer to head node
 * @str: function parameter showing str field of node
 * @num: parameter indicating the node index used by history
 * Return: 0 if successful
 */

list_t *add_node(list_t **head, const char *str, int num)
{
        list_t *new_node;

        if (!head)
                return NULL;

        new_node = malloc(sizeof(list_t));
        if (!new_node)
                return NULL;

        new_node->str = (str) ? _strdup(str) : NULL;
        new_node->num = num;
        new_node->next = *head;
        *head = new_node;

        return (new_node);
}

/**
 * add_node_end - this function adds a node to the end of the list
 * @head: parameter showing the address of pointer to head node
 * @str: function parameter showing str field of node
 * @num: parameter indicating the node index used by history
 * Return: 0 if successful
 */

list_t *add_node_end(list_t **head, const char *str, int num)
{
        list_t *new_node, *node;

        if (!head)
                return NULL;

        new_node = malloc(sizeof(list_t));
        if (!new_node)
                return NULL;

        new_node->str = (str) ? _strdup(str) : NULL;
        new_node->num = num;
        new_node->next = NULL;

        if (*head == NULL)
        {
                *head = new_node;
                return new_node;
        }

        node = *head;
        while (node->next != NULL)
                node = node->next;

        node->next = new_node;
	        return new_node;
}

/**
 * print_list_str - this function prints the str element of a linked list
 * @h: function parameter showing pointer to first node
 * Return: 0 if successful
 */
size_t print_list_str(const list_t *h)
{
        size_t count = 0;

        while (h)
        {
                _puts((h->str) ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                count++;
        }

        return count;
}
/**
 * delete_node_at_index - this function deletes node at given indexin the list
 * @head: parameter indicating the address of pointer to first node
 * @index: this parameter shows index of node to delete
 * Return: 1 if successful
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
        list_t *node, *prev_node;
        unsigned int i;

        if (!head || !*head)
                return 0;

        if (index == 0)
        {
                node = *head;
                *head = (*head)->next;
                free(node->str);
                free(node);
                return 1;
        }

        prev_node = *head;
        node = (*head)->next;
        i = 1;

        while (node)
        {
                if (i == index)
                {
                        prev_node->next = node->next;
                        free(node->str);
                        free(node);
                        return 1;
                }

                prev_node = node;
                node = node->next;
		                i++;
        }

        return 0;
}

/**
 * free_list - this function frees allocated memory for a node in the link list
 * @head_ptr: function parameter indicating the address of pointer to head node
 * Return: void
 */
void free_list(list_t **head_ptr)
{
        list_t *node, *next_node;

        if (!head_ptr || !*head_ptr)
                return;

        node = *head_ptr;
        while (node)
        {
                next_node = node->next;
                free(node->str);
                free(node);
                node = next_node;
        }

        *head_ptr = NULL;
}
