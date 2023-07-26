#ifndef SHELL_H
#define SHELL_H

#define BUFFER 1024
#define FLUSH -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
void _printf(char *);
int _putchar(char);
char **_string_splitter(char *buffer, char *del);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_get_command(char *command);

char *_get_env(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int main(int ac, char **av, char **env);
int _strlen(const char *s);
#endif
