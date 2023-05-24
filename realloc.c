#include "shell.h"

/**
 **_memset - this method is responsible for filling the memory
 *@s: the address of the start of the block
 *@b: the char to use in the filling
 *@n: the bytes count
 *Return: the address of the block beginning
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - this method is responsinble for freeingatr od atrs
 * @pp: str of strs
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - this mthod is rsponsible for reallocatting bytes mlock
 * @ptr: the address of the old block
 * @old_size: the old bock  large
 * @new_size: the ne block large
 * Return: the address of the block start
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
