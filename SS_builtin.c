#include "shell.h"

/**
 * _myexit - This function is responsible for handling the exit command
 * @info: Function parameter that indicates the struct containing potential arg
 * Return: 0 if successful.
 */
int _myexit(info_t *info)
{
	int exit_check;

	if (info->argv[1])
	{
		exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			_eputs(info->argv[1]);
			print_error(info, "number not allowed: ");
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - This function handles the change directory command in the shell.
 * @info: Function parameter indicating the struct containing potential args.
 * Return: 0 if successful.
 */
int _mycd(info_t *info)
{
	char *dir;
	char buffer[1024];
	char *s = getcwd(buffer, 1024);
	int chdir_ret;

	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "cannot cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		setenv("OLDPWD", _getenv(info, "PWD="), 1);
		setenv("PWD", getcwd(buffer, 1024), 1);
	}
	return (0);
}

/**
 * _myhelp - This function handles the help command in the shell.
 * @info: Parameter containing potential arguments.
 * Return: 0 if successful.
 */
int _myhelp(info_t *info)
{
	char **arg_array = info->argv;

	_puts("help call works. Function not yet implemented\n");
	if (0)
		_puts(*arg_array);
	return (0);
}

