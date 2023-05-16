#include "shell.h"
/**
 **mem_set - fills memory with a constant byte
 *@a: the pointer to the memory area
 *@b: the byte to fill *a with
 *@c: the amount of bytes to be filled
 *Return: (a) a pointer to the memory area s
 */
char *mem_set(char *a, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		a[i] = b;
	return (a);
}
/**
 * set_free - frees a string of strings
 * @ss: string of strings
 */
void set_free(char **ss)
{
	char **x = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(x);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @oldSize: byte size of previous block
 * @newSize: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
