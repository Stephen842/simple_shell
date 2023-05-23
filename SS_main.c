#include "shell.h"
#include <fcntl.h>
/**
 * main - entry point
 * @ac: function parameter indicating argument count
 * @av: function parameter indicating argument vector
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
info_t info[] = { INFO_INIT };
int fd = 2;

fd = fd + 3;

if (ac == 2)
{
fd = open(av[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
{
exit(126);
}
else if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
else
{
return (EXIT_FAILURE);
}
}
info->readfd = fd;
}

populate_env_list(info);
read_history(info);
hsh(info, av);

return (EXIT_SUCCESS);
}
