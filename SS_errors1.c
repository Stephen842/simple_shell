#include "shell.h"
#include <limits.h>
/**
 * _erratoi - this function convert a string to an interger
 * @s: parameter showing the string to be converted
 * Return: 0 if successful
 */
int _erratoi(char *s)
{
	unsigned long int result = 0;
	int a = 0;

	if (*s == '+')
		s++;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] >= '0' && s[a] <= '9')
		{
			result *= 10;
			result += (s[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_error - this function print an error message
 * @info: parameter showing a struct containing potential argument
 * @estr: parameter showing specified error string
 * Return: 0 if successful
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - this function print a decimal number to a file descriptor
 * @input: parameter showing the input
 * @fd: parameter indicating file descriptor
 * Return: the number of char printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a;
	unsigned int _abs_;
	int counted = 0;
	unsigned int current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		counted++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			counted++;
		}
		current %= a;
	}
	__putchar('0' + current);
	counted++;

	return (counted);

}
/**
 * convert_number - this function convert a number to a string
 * @num: parameter showing the number
 * @base: funnction parameter
 * @flags: parameter indicating arguments flags
 * Return: a string
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	char *array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = (-num);
		sign = '-';
	}

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}
/**
 * remove_comments- this function replaces the first occurence of a char in str
 * @buf: parameter indicating the address of the modified string
 * Return: 0 if successful
 */
void remove_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
	{
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
	}
}

