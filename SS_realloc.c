#include "shell.h"
/**
 * _memset - this function fills a block of memory with a constant byte
 * @s: parameter showing the pointer to the memory area
 * @b: parameter showing the byte to fill *s with
 * @n: parameter of the amount of bytes to be filled
 * Return: s as a pointer
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
*(s + i) = b;
return (s);
}

/**
 * ffree -this function frees dynamically allocated array of strings
 * @pp: function parameter indicating string of strings
 * Return: void
 */

void ffree(char **pp)
{
char **tmp = pp;

if (!pp)
return;
while (*pp)
{
free(*pp);
pp++;
}
free(tmp);
}

/**
 * _realloc - this function reallocates a block of memory to a new size
 * @ptr: function parameter indicating a pointer
 * @old_size: function parameter indicating the byte size of previous block
 * @new_size: function parameter indicating the byte size of new block
 * Return: void
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr = NULL;
char *destination;
unsigned int i;

if (!ptr)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
return (ptr);

new_ptr = malloc(new_size);
if (!new_ptr)
return (NULL);

destination = new_ptr;

for (i = 0; i < old_size && i < new_size; i++)
destination[i] = ((char *)ptr)[i];

free(ptr);
return (new_ptr);
}

