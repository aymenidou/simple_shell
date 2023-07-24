#include "shell.h"

/**
 *_printf - printa string
 *@str: input string
 */
void _printf(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	/*static char buf[BUFFER];*/

	write(1, &c, i);
	/*if (c == FLUSH || i >= BUFFER)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != FLUSH)
		buf[i++] = c;*/
	return (1);
}

char **_string_splitter(char *buffer, char *del)
{
	char **tokens;
	char *token;
	int i = 0;
	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buffer, del);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * _strcmp - compare string
 * @s1: input string
 * @s2: input string
 * Return: string comparison
 */

int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		else if (*s1 == '\0' || *s2 == '\0')
		{
			break;
		}
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strncmp - compare n characters in string
 * @s1: input string
 * @s2: input string
 * @n: input number
 * Return: string comparison
 */

int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	for (; *s1 != '\0' && *s2 != '\0' && i < n; s1++, i++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		else if (*s1 == '\0' || *s2 == '\0')
		{
			break;
		}
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}