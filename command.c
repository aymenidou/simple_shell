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

void ls - r(char *path)
{
	char *cmd;
	list_cmd = 0;
	struct path
	{
		int chdir(const char *path);
		struct path *next;
		struct token *path = NULL;
		if (path == NULL)
		printf("list is empty\n")
			return;
		printf("path of signaly linked lis\n")
			
			int data;
			while(current != NULL)
			printf("%d", current->data);
			current = current->next;
			printf("\n");
			return 0;
	}
}
