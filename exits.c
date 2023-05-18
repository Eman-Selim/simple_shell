#include "shell.h"

/**
 **_strncpy - function that responsible for copying the string parameter
 *@dest: the string that will have the copy
 *@src: the string to be copied
 *@n: the count of chars in the string
 *Return: string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - this function is responsible for concatinating strings
 *@dest: the string that will be in the intro of result
 *@src: the string that will be in the end of result
 *@n: the bytes counted as max
 *Return: the result
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - function that is responsible for changing char in the string
 *@s: string that will changed
 *@c: char will be placed in string
 *Return: it returns a pointer to string
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
