#include "shell.h"

/**
 * _eputs - this function is used to print a string to the standard error
 * @str: function parameter showing the string to be printed
 * Return: 0 if successful
 */
void _eputs(char *str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] != '\0')
    {
        _eputchar(str[i]);
        i++;
    }
}

/**
 * _eputchar - this function write a character to the standard error
 * @c: function parameter indicating the character to be printed
 * Return: 0 if successful
 */
int _eputchar(char c)
{
    return write(STDERR_FILENO, &c, 1);
}

/**
 * _putfd - this function write a character to a specific file descriptor
 * @c: function parameter of the function to print
 * @fd: function parameter of the file descriptor
 * Return: 1 if successful
 */
int _putfd(char c, int fd)
{
    return write(fd, &c, 1);
}

/**
 * _putsfd - the function is use to print a string to a specific file descriptor
 * @str: parameter showing the string to be printed
 * @fd: function parameter of the file descriptor
 * Return: the number of strings inputted
 */
int _putsfd(char *str, int fd)
{
    int i = 0;
    int count = 0;

    if (!str)
        return 0;

    while (str[i] != '\0')
    {
        if (_putfd(str[i], fd) == -1)
            return -1;
        count++;
        i++;
    }

    return count;
}

