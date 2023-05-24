#include "shell.h"
/**
 * bfree - this function frees the memory pointed to by the pointer and set the
 * pointer to null
 * @ptr: function parameter showing the address of the pointer to free
 * Return: 0 if successful
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
