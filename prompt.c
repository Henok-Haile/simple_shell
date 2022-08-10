#include "main.h"

/**
 * sig_handler - to catch Ctrl C
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		_puts("\n#cisfun$ ");
}

/**
 * _EOF - function to handle End Of File
 * @len:
 * @buff:
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * _isatty - function to check if datatype FILE is STDIN.
 * (i.e if input is from the terminal)
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * free_argv - frees the pointer to argument vector
 *@argv: pointer to elements in the argument vector
 */

void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}

/**
 * _exit_sh - exits the shell with or without a return of status n
 * @argv: array of words of the entered line
 */
void _exit_sh(char **argv)
{
	int i, n;

	if (argv[1])
	{
		n = _atoi(argv[1]);
		if (n <= -1)
			n = 2;
		free_argv(argv);
		exit(n);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	exit(0);
}
