#include "shell.h"

/**
 * my_exit - Exits the shell with a given exit status.
 * @info: Structure containing potential arguments. Used to maintain
 *        a constant function prototype.
 *
 * Return: If info->argv[0] is not "exit", returns 0.
 *         Otherwise, exits with the given exit status.
 */
int my_exit(info_t *info)
{
	if (info->argv[1]) /* If there is an exit argument */
	{
		int exit_status = _erratoi(info->argv[1]);

		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		info->err_num = exit_status;
		return (-2);
	}

	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - Changes the current directory of the process.
 * @info: Structure containing potential arguments. Used to maintain
 *        a constant function prototype.
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir, buffer[1024];
	int chdir_ret;
	char *current_dir = getcwd(buffer, sizeof(buffer));

	if (!current_dir)
		_printf("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _get_env(info, "HOME=");
		if (!dir)
			dir = _get_env(info, "PWD=");
		chdir_ret = chdir(dir ? dir : "/");
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _get_env(info, "OLDPWD=");
		if (!dir)
		{
			_printf(current_dir);
			_putchar('\n');
			return (1);
		}
		_printf(dir);
		_putchar('\n');
		chdir_ret = chdir(dir);
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", current_dir);
		_setenv(info, "PWD", getcwd(buffer, sizeof(buffer)));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_printf("help call works. Function not yet implemented \n");
	if (0)
		_printf(*arg_array); /* temp att_unused workaround */
	return (0);
}
