#include "shell.h"
/**
 * interactive - this program returns true if the shell is in interactive mode
 * @info: this function parameter indicate the struct address
 * Return: 1 if the shell is interactive, else otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this function check if a given character c is a delimiter
 * @c: function parameter of the character to check
 * @delim: function parameter of the delimiter string
 * Return: 1 if successful, else 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim++)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - this function checks if a character is an alphabet
 * @c: function parameter of the character to be checked
 * Return: 1 if successful else 0
 */
int _isalpha(int c)
{
	if (isalpha(c))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that convert a string to an interger.
 * @s: string to be converted to an interger
 * Return: 0 if successful
 */
int _atoi(char *s)
{
	int a;
	int sign = 1;
	int f = 0;
	int output;
	unsigned int res = 0;

	for (a = 0; s[a] != '\0' && f != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			f = 1;
			res *= 10;
			res += (s[a] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}

