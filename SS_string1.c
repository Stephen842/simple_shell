#include "shell.h"
/**
 * _strcpy - this function copies a string
 * @dest: parameter showing the destination of the copied string
 * @src: parameter showing the the source of the copied string
 * Return: 0 if successful
 */
char *_strcpy(char *dest, char *src)
{
char *ret = dest;

if (dest == src || src == NULL)
return (dest);

while ((*dest++ = *src++))
return (ret);
}

/**
 * _strdup - this function duplicates a string by dynamically allocating memory
 * to the duplicated string
 * @str: function parameter showing the string to duplicate
 * Return: 0 if successful
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (str[length])
length++;

ret = malloc(sizeof(char) * (length + 1));
if (ret == NULL)
return (NULL);

_strcpy(ret, (char *)str);
return (ret);
}

/**
 * _puts - this function prints a null terminated string to standard output
 * @str: function parameter showing the string to be printed
 * Return: void
 */
void _puts(char *str)
{
if (str == NULL)
return;
while (*str)
putchar(*str++);
}

/**
 * _putchar - this function writes the character  to stdout
 * @c: function parameter indicating The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
return (putchar(c));
}

