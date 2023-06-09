#include "shell.h"

/**
 * main - this is the entry point of this shell
 * @ac: function parameter indicating argument count
 * @av: function parameter indicating argument vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int b = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (b)
			: "r" (b));

	if (ac == 2)
	{
		b = open(av[1], O_RDONLY);
		if (b == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = b;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
