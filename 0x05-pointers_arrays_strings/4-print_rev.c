#include "holberton.h"

/**
 * print_rev - prints a string
 * @s: value to be checked
 * Return: nothing
 */
void print_rev(char *s)
{
	int l = 0;

	while (s[l] != 0)
		l++;
	l = l - 1;
	while (l >= 0)
	{
		_putchar(s[l]);
	l--;
	}
	_putchar('\n');
}
