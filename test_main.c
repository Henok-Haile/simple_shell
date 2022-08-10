#include "main.h"

/**
 * main - Shell
 * Return: 0 on success
 */
int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **argv;
	size_t size = 0;
	list_path_t *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);/* signal handling */
	while (len != EOF)
	{
		_isatty();
		len = _getline(&buff, &size, 0);
		_EOF(len, buff);
		argv = tokenizer(buff, " \n");
		if (!argv || !argv[0])
			execute(argv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(argv[0], head);
			f = buildins(argv);
			if (f)
			{
				free(buff);
				f(argv);
			}
			else if (!pathname)
				execute(argv);
			else if (pathname)
			{
				free(argv[0]);
				argv[0] = pathname;
				execute(argv);
			}
		}
	}
	free_list(head);
	free_argv(argv);
	free(buff);
	exit(EXIT_SUCCESS);
}
