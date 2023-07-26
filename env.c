#include "shell.h"

/**
 * _get_env - getenv
 * @name: input
 * Return: environment variable value
 */
char *_get_env(const char *name)
{
	char *token;
	int i = 0;

	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (_strcmp(name, token) == 0)
		{
			return (strtok(NULL, ""));
		}
		i++;
	}
	return (NULL);
}

/**
 * _setenv - set env variable
 * @name: var name
 * @value: var value
 * @overwrite: overwrite value
 * Return: 0 or -1
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, len = 0;
	char *new_var;

	if (!name || !value)
	{
		return (-1);
	}
	while (environ[i])
	{
		len = _strlen(name);
		if (_strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				new_var = malloc(_strlen(name) + _strlen(value) + 2);
				_strcpy(new_var, name);
				_strcat(new_var, "=");
				_strcat(new_var, value);
				environ[i] = new_var;
				return (0);
			}
			return (0);
		}
		i++;
	}
	new_var = malloc(_strlen(name) + _strlen(value) + 2);
	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);
	environ[i] = new_var;
	environ[i + 1] = NULL;
	return (0);
}
