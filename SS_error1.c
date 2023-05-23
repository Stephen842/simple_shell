#include "shell.h"
#include <limits.h>
/**
 * _erratoi - this function convert a string to an interger
 * @s: parameter showing the string to be converted
 * Return: 0 if successful
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return ((int)result);
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
int count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;

if (input < 0)
{
_abs_ = (unsigned int)(-input);
__putchar('-');
count++;
}
else
_abs_ = (unsigned int)input;

current = _abs_;

if (current >= 10)
count += print_d(current / 10, fd);

__putchar('0' + (current % 10));
count++;

return (count);
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
char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = (unsigned long)(-num);
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
int i;

for (i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}

