#include "shell.h"

/**
 * _strncpy - this function copies a string from it source to it destination
 * @dest: function parameter indicating the destination of the string
 * @src: function parameter showing the source of the string
 * @n: parameter of the number of the char to be copied
 * Return: 0 if successful
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
 * _strncat - this function concatenate two string
 * @dest: parameter showing the dest of the file
 * @src: parameter showing the source of the string
 * @n: the number of string to be copied
 * Return: 0 if successful
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = _strlen(dest);
	int i, j;

	for (i = dest_len, j = 0; j < n && src[j] != '\0'; i++, j++)
		dest[i] = src[j];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strchr - this function searches for the first occurence of a character
 * @s: parameter showing the string to be parsed
 * @c: parameter showing the character to be searched
 * Return: 0 if successful
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}

