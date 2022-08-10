#include "main.h"

/**
 * print_number - prints an integer;
 * @n: integer to be printed;
 */
void print_number(int n)
{
	unsigned int numb;

	/* We would archieve this using recursion*/
	/* Base case = number is < 10 */
	if (n < 0)
	{
		numb = -n;
		_putchar('-');
	} else
	{
		numb = n;
	}

	/* numbers > 10 print the last digit recursively */
	if (numb / 10)
		print_number(numb / 10);

	_putchar((numb % 10) + '0');
}

/**
 * _getpid - Function to print PID
 *
 * Return: void.
 */
void _getpid(void)
{
    pid_t my_pid;

    my_pid = getpid();
    print_number(my_pid);
}

/**
 * _getppid - Function to print parent process ID
 *
 * Return: void.
 */
void _getppid(void)
{
    pid_t ppid;

    ppid = getppid();
    print_number(ppid);
}
