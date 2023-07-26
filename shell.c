#include "shell.h"
/**
 * main - entry point
 * @ac: arg count
 * @av: arg vars
 * @env: env
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *cmd, **args;
	size_t buffer_size;
	pid_t pid;
	int status, n_chars;

	(void)ac;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);
		n_chars = getline(&buffer, &buffer_size, stdin);
		if (n_chars == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		args = _string_splitter(buffer, " \t\n");
		if (_strcmp(args[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			cmd = _get_command(args[0]);
			if (cmd)
				execve(cmd, args, env);
			else
				_printf("command not found\n");
			exit(0);
		}
		else
			wait(&status);
	}
	return (0);
}
