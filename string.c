#include "shell.h"

/**
 * _strlen - this method is responsible for returning str length
 * @s: the string whose length  is reqiures to check
 * Return: str  len value
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - this method is responsible for perforing lexicogarphic comparison
 * @s1: the first to ne compared
 * @s2: the second to ne compared
 * Return: negative or positive or zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - this method is responsibe for checking if needle started with haystack
 * @haystack: string to reqiured to find in
 * @needle: the string reqiured to find
 * Return: character or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this methpd is responible for concatenating string
 * @dest: destination to xave value in
 * @src: source to xave value in dest
 * Return: character
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
