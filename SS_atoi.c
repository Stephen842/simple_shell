#include "main.h"

/**
 * interactive - This function returns true if the shell is in interactive mode.
 * @info: The struct address.
 *
 * Return: 1 if the shell is interactive, 0 otherwise.
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - This function checks if a given character is a delimiter.
 * @c: The character to check.
 * @delim: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
    while (*delim != '\0')
    {
        if (c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/**
 * _isalpha - This function checks if a character is an alphabet.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is an alphabet, 0 otherwise.
 */
int _isalpha(int c)
{
    if (isalpha(c))
        return 1;
    else
        return 0;
}

/**
 * _atoi - This function converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int flag = 0;

    while (*s != '\0' && flag != 2)
    {
        if (*s == '-')
            sign *= -1;
        if (*s >= '0' && *s <= '9')
        {
            flag = 1;
            result = result * 10 + (*s - '0');
        }
        else if (flag == 1)
            flag = 2;

        s++;
    }

    if (sign == -1)
        result = -result;

    return result;
}
