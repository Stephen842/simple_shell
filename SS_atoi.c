#include "main.h"

/**
 * interactive - This program returns true if the shell is in interactive mode.
 * @info: This function parameter indicates the struct address.
 * Return: 1 if the shell is interactive, else 0.
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - This function checks if a given character c is a delimiter.
 * @c: Function parameter of the character to check.
 * @delim: Function parameter of the delimiter string.
 * Return: 1 if successful, else 0.
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
 * @c: Function parameter of the character to be checked.
 * Return: 1 if successful, else 0.
 */
int _isalpha(int c)
{
    if (isalpha(c))
        return 1;
    else
        return 0;
}

/**
 * _atoi - Function that converts a string to an integer.
 * @s: String to be converted to an integer.
 * Return: 0 if successful.
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
