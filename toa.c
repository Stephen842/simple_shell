#include "shell.h"
/**
 * interactive - returns true if shell is interactive mode
 * @information: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}
/**
 * is_delim - checks if character is a delimeter
 * @a: the char to check
 * @dem: the delimeter string
 * Return: 1 if true, 0 if false
 */
int dem(char a, char *dem)
{
	while (*dem)
		if (*dem++ == a)
			return (1);
	return (0);
}
/**
 * alpha - checks for alphabetic character
 * @y: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int alpha(int y)
{
	if ((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * con - converts a string to an integer
 * @x: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int con(char *x)
{
	int i, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (i = 0; x[i] != '\0' && flag != 2; i++)
	{
		if (x[i] == '-')
			sign *= -1;

		if (x[i] >= '0' && x[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (x[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}

