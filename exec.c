#include "main.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previous memory block
 * @old_size: size in bytes of allocated memory for `ptr`
 * @new_size: size in bytes for new allocated space
 *
 * Return: Pointer to new memory block, or NULL if error
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr, *copy = ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		return (newptr);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		newptr[i] = copy[i];
	free(ptr);
	return (newptr);
}

/**
 * _atoi - converts a string to an integer, truncate invalid char
 * @s: string to convert
 *
 * Return: value of integer
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}
/**
 * execute - executes a command
 * @argv: pointer to argument vector
 */

void execute(char **argv)
{

	int new_process, status;

	if (!argv || !argv[0])
		return;
	
    new_process = fork();
	if (new_process == -1)
		perror(_getenv("_"));
	
    if (new_process == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
