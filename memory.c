#include "shell.h"

/**
 * bfree - this method is responsibe for freeing
 * @ptr: the adddress that reqiure freeing
 * Return: one or zero
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
