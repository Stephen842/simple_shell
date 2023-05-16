#include "shell.h"

/**
 **_stringncopy - copies a string
 *@des: the destination string to be copied to
 *@src: the source string
 *@x: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_stringcopy(char *des, char *src, int x)
{
	int i, j;
	char *s = des;

	i = 0;
	while (src[i] != '\0' && i < x - 1)
	{
		des[i] = src[i];
		i++;
	}
	if (i < x)
	{
		j = i;
		while (j < x)
		{
			des[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strn_cat - concatenates two strings
 *@des: the first string
 *@src: the second string
 *@x: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *strn_cat(char *des, char *src, int x)
{
	int i, j;
	char *s = des;

	i = 0;
	j = 0;
	while (des[i] != '\0')
		i++;
	while (src[j] != '\0' && j < x)
	{
		des[i] = src[j];
		i++;
		j++;
	}
	if (j < x)
		des[i] = '\0';
	return (s);
}

/**
 **str_chr - locates a character in a string
 *@a: the string to be parsed
 *@b: the character to look for
 *Return: (a pointer to the memory area a
 */
char *str_chr(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
