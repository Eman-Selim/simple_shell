#include "shell.h"

/**
 *interactive -  this function responsible for
 *returning true if the shell is in interactive mode
 *@info: the address of struct
 *Return: 1 if shell is ininteractive mode
*/

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *is_delim - this function is responsible for checking
 *if the char is a delimeter or not
 *@c: the character to be checked
 *@delim: the delimeter
 *Return: 0 if c is not a delimeter 1 otherwise
*/

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - ths function is responsible for checking
 *id the c is a character or not
 *@c: the input charcter
 *Return: if c is a char it returns 1
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi -  this function is responsible for converting
 *a string to integer
 *@s: the input string
 *Return: converted number or 0 if there is no number
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '0')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
