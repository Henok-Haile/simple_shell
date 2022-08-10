#include "main.h"
/**
 * _strncpy - copies the string
 * @dest: array that returns
 * @src: the pointer that receive the string
 * @n: times to interate
 *
 * Return: the parameter dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
/**
 * _memset - fills memory with a constant byte.
 * @s: source string
 * @c_in: the constant byte for filling
 * @n: lenght of buffer
 * Return: new string.
 */
char *_memset(char *s, int c_in, unsigned int n)
{
	unsigned int i;
	unsigned char c;
/* cast int to char */
	c = (unsigned char) c_in;

	for (i = 0; i < n; i++)
		s[i] = c;

	return (s);
}

/**
 * _strspn - gets length of a prefix substring
 * @s: string to check
 * @accept: string to check against
 *
 * Return: number of bytes in the initial segment of s in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j] == '\0')
			break;
	}
	return (i);
}
/**
 * _strcspn - gets length of a prefix substring
 * @s: string to check
 * @accept: string to check against
 *
 * Return: number of bytes in the first occurence segment of s in accept
 */
unsigned int _strcspn(char *s, char *accept)
{
	unsigned int i, j, pos = 0;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				/* set value and break */
				pos = i;
				break;
			}
		}
		if (pos || !s[i])
			break;
	}
	return (pos);
}
