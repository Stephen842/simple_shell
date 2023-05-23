#include "shell.h"
/**
 * _strlen - this function calculate the lenght of a string by iterating over
 * each character until the null terminator is encounter
 * @s: parameter showing the string whose length to be checked
 * Return: the lenght of a string
 */
int _strlen(char *s)
{
int length = 0;

if (s == NULL)
return (0);

while (*(s + length) != '\0')
length++;

return (length);
}

/**
 * _strcmp - thid function does lexicogarphic comparison of two strings.
 * @s1: parameter showing the first string to be compared
 * @s2: parameter showing the second string to be compared
 * Return: 0 if successful
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && (*s1 == *s2))
{
s1++;
s2++;
}

return ((*s1 - *s2));
}

/**
 * starts_with - this function checks if a sting is a prefix of another string
 * @haystack: parameter indicating the string to search
 * @needle: function parameter showing the substring to find
 * Return: 0 if successful
 */

char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
{
if (*needle != *haystack)
return (NULL);

needle++;
haystack++;
}

return ((char *) haystack);
}

/**
 * _strcat - this function concatenates two strings by appending one to the end
 * of another
 * @dest: parameter showing the destination buffer
 * @src: function parameter indicating the source buffer
 * Return: 0 if successful
 */

char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;

while (*src)
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (ret);
}

