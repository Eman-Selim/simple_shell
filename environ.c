#include "shell.h"

/**
 * _myenv - this function is responsible for printing
 * the env
 * @info: potential argument contained in structure
 * Return: 0
 */

int _myenv(info_t *info)
{
        print_list_str(info->env);
				return (0);
}

/**
 * _getenv - function responsible for returning the variable
 * of env value
 * @info: potential argument contained in a structure
 * Return: returns the value of env var
 */
char *_getenv(info_t *info, const char *name)
{
        list_t *node = info->env;
				char *p;
				while (node)
				{
                p = starts_with(node->str, name);
								if(p && *p)
								        return (p);
					      node = node->next;
				}
	      return (Null);
}

/**
 * _mysetenv - this function is responsible for modifying and
 * initializing new env
 * @info: potential argument contained in a structure
 * Return: 0
 */

int _mysetenv(info_t *info)
{
        if (info->argc != 3)
				{
				        _eputs("Incorrect number of argument \n");
				        return (1);
				}
        if (_setenv(info, info->argv[1], info->argv[2]))
				        return (0);
        return (1);
}

/**
 * @info: potential argument contained in a structure
  
