#include "holberton.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string to copy
 * @s2: second string to copy
 * @n: number of bytes of s2 to copy
 *
 * Return: char pointer to newly allocated place in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *a;
	unsigned int s1Len, s2Len;
	unsigned int i, I;
	char nul = '\0';
	int tots;

	if (s1 == NULL)
		s1 = &nul;
	if (s2 == NULL)
		s2 = &nul;

	s1Len = _strlen(s1);
	s2Len = _strlen(s2);

	if (n >= s2Len)
		tots = s2Len + s1Len;
	else
		tots = s1Len + n;

	a = malloc(tots + 1);
	if (a == NULL)
		return (NULL);

	i = 0, I = 0;
	while (s1[i] != '\0')
		a[I++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && n-- != 0)
		a[I++] = s2[i++];
	a[I] = '\0';

	return (a);
}
