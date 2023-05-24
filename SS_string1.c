#include "shell.h"
/**
 * _strcpy - this function copies a string
 * @dest: parameter showing the destination of the copied string
 * @src: parameter showing the the source of the copied string
 * Return: 0 if successful
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);

}

/**
 * _strdup - this function duplicates a string by dynamically allocating memory
 * to the duplicated string
 * @str: function parameter showing the string to duplicate
 * Return: 0 if successful
 */
char *_strdup(const char *str)
{
	char *a;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	for (len++; len--;)
		a[len] = *--str;
	return (a);

}

/**
 * _puts - this function prints a null terminated string to standard output
 * @str: function parameter showing the string to be printed
 * Return: void
 */
void _puts(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}

}

/**
 * _putchar - this function writes the character  to stdout
 * @c: function parameter indicating The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	static char b[WRITE_BUF_SIZE];
	static int a;

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, b, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		b[a++] = c;
	return (1);

}

