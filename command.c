#include "shell.h"

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
        strcpy(cmd_full, token);
        strcat(cmd_full, "/");
        strcat(cmd_full, command);
        if (stat(cmd_full, &st) == 0)
        {
            return (cmd_full);
        }
        free(cmd_full);
        token = strtok(NULL, ":");
    }
    return (NULL);
}