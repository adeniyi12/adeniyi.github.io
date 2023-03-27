#include "main.h"

/**
 * print_char - prints a character to stdout
 * @args: variadic parameter
 *
 * Return: number of characters printed
 */

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	int count = 0;

	if (c)
	{
		count = _putchar(c);
		return (count);
	}

	return (0);
}

/**
 * print_str - prints a variadic string each per time to stdout
 * @args: variadic parameter
 *
 * Return: number of characters printed on Success
 * upon failure -1
 */

int print_str(va_list args)
{
	int i;
	int count = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);

	while (str[i])
	{
		count = write(1, &str[i], 1);
		i = i + 1;
	}

	return (count);
}


/**
 * print_cent - prints character % to stdout
 * @args: variadic parameter
 *
 * Return: number of characters printed
 */

int print_cent(va_list args)
{
	(void)args;

	write(1, "%", 1);

	return (1);
}


/**
 * print_bin - prints binary of num to stdout
 * @args: variadic parameter
 *
 * Return: binary value of argument passed on Success
 * upon failure -1
 */

int print_bin(va_list args)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = print_rev(str);

	if (rev_str == NULL)
		return (-1);

	for (i = 0; rev_str[i] != '\0'; i++)
	{
		_putchar(rev_str[i]);
	}
	//write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}
