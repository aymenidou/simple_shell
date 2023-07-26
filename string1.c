#include "shell.h"
/**
 * _strlen - string lengthvoid puts2(char *str);
 * @s: pointer char
 * Return: return length of string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * *_strcpy - entry point
 * @dest: char pointer
 * @src: char pointer
 * Return: char
 */

char *_strcpy(char *dest,const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcat - concat string
 *@dest: string destination
 *@src: string source
 *Return: string concatenation
 */

char *_strcat(char *dest,const char *src)
{
	int i = _strlen(dest), k;

	for (k = 0; src[k] != '\0'; k++)
	{
		dest[i + k] = src[k];
	}
	dest[i + k] = '\0';
	return (dest);
}
