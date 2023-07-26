#include "shell.h"

/**
 * _get_command - get command from path
 * @command: command to be found
 * Return: the full path of the command
 */
char *_get_command(char *command)
{
	char *path = _get_env("PATH");
	char *token;
	char *cmd_full;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		cmd_full = malloc(_strlen(token) + _strlen(command) + 2);
		_strcpy(cmd_full, token);
		_strcat(cmd_full, "/");
		_strcat(cmd_full, command);
		if (stat(cmd_full, &st) == 0)
		{
			return (cmd_full);
		}
		free(cmd_full);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
