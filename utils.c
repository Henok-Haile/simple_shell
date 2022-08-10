#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: is a character
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _strlen - returns the length of a string recursively
 * @s: is a character
 * Return: 0;
 */

unsigned int _strlen(char *s)
{
	if (!s || (*s == '\0'))
		return (0);
	return ((1) + _strlen(s + 1));
}

/**
 * _strdup - Copies string to a newly allocated space in memory.
 * @str: string we need to duplicate
 *
 * Return: a pointer to the duplicated string or NULL
 */
char *_strdup(char *str)
{
	char *newstr = NULL;
	unsigned int i;
	int size;

	if (str == NULL)
		return (NULL);

	size = _strlen(str);

	newstr = malloc(size + 1 * sizeof(char));
	if (!newstr)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		newstr[i] = str[i];

	newstr[i] = '\0';
	return (newstr);
}

/**
 * str_concat -concatenates three strings
 * @s1: string 1
 * @s2: string 2
 * @s3: string 3
 *
 * Return: pointer should point to a newly allocated space in memory or NULL
 */
char *str_concat(char *s1, char *s2, char *s3)
{
	char *newstr = NULL;
	unsigned int i;
	int size1, size2, size3, count;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (s3 == NULL)
		s3 = "";

	size1 = _strlen(s1);
	size2 = _strlen(s2);
	size3 = _strlen(s3);
	newstr = (char *)malloc((size1 + size2 + size3 + 1) * sizeof(char));

	if (newstr == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		newstr[i] = s1[i];
	count = i;

	for (i = 0; s2[i] != '\0'; i++)
		newstr[count + i] = s2[i];
	count = count + i;

	for (i = 0; s3[i] != '\0'; i++)
		newstr[count + i] = s3[i];
	count = count + i;

	newstr[count] = '\0';

	return (newstr);
}
