#include "shell.h"

/**
 * _myexit - This function is responsible for handling the exit command
 * @info: Function parameter that indicates the struct containing potential arg
 * Return: 0 if successful.
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit argument */
	{
		exitcheck = atoi(info->argv[1]);
		if (exitcheck == 0 && strcmp(info->argv[1], "0") != 0)
		{
			info->status = 2;
			fprintf(stderr, "Illegal number: %s\n", info->argv[1]);
			return (1);
		}
		info->err_num = exitcheck;
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
		fprintf(stderr, "TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getenv("HOME");
		if (!dir)
			chdir_ret = chdir((dir = getenv("PWD")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (strcmp(info->argv[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (!dir)
		{
			printf("%s\n", s);
			return (1);
		}
		printf("%s\n", dir);
		chdir_ret = chdir(dir ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);

	if (chdir_ret == -1)
		fprintf(stderr, "can't cd to %s\n", info->argv[1]);
	else
	{
		setenv("OLDPWD", getenv("PWD"), 1);
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

	printf("help call works. Function not yet implemented\n");
	if (0)
		printf("%s\n", *arg_array); /* temp att_unused workaround */
	return (0);
}

