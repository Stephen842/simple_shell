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
	int a = 0;
	int b;
	char *c = dest;

	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}

	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}

	return (c);
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
	char *c = dest;
	int a = 0;
	int b = 0;

	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (c);

}

/**
 * _strchr - this function searches for the first occurence of a character
 * @s: parameter showing the string to be parsed
 * @c: parameter showing the character to be searched
 * Return: 0 if successful
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

