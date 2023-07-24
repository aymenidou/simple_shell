#include "shell.h"

/**
 * _get_env - getenv
 * @name: input
 * Return: environment variable value
 */
char *_get_env(const char *name)
{
    char *token;
    extern char **environ;
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

int _setenv(const char *name, const char *value, int overwrite)
{

    extern char **environ;
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
                strcpy(new_var, name);
                strcat(new_var, "=");
                strcat(new_var, value);
                environ[i] = new_var;
                return (0);
            }
            return (0);
        }
        i++;
    }
    new_var = malloc(_strlen(name) + _strlen(value) + 2);
    strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);
    environ[i] = new_var;
    environ[i + 1] = NULL;
    return (0);
}