#include "main.h"

/**
 * base_len - Calculates the length for base number
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 * Return: An integer representing the length of a number
 */

unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * print_rev - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */

char *print_rev(char *s)
{
	int i, len = 0;
	char *s_rev;

	while (s[len] != '\0')
	{
		len++;
	}

	s_rev = malloc(sizeof(char) * len + 1);
	if (s_rev == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		s_rev[i] = s[len - i - 1];
	}
	s_rev[len] = '\0';
	return (s_rev);
}
