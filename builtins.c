#include "main.h"
/**
 * _getline - read a string or a line from an input stream
 * @buffer: pointer to a space where the stdin read will be saved
 * as a string
 * @bufsize: current size of buffer (must be given as 0 initially)
 * @fd: stream to read
 *
 * Return: Number of Characters Read
 */
int _getline(char **buffer, size_t *bufsize, int fd)
{
	static char *buff;
	static size_t size;
	unsigned int len = 0, i = 0, sizeold;
	int r;

	if (*bufsize == 0)
		size = BUFF_SIZE;
	if (*buffer == 0)
	{
		buff = malloc(sizeof(char) * size);
		if (!buff)
			return (MEM_ERROR, 0);
		*buffer = buff;
	}
    /* initialize buff with '\0' */
	for (i = 0; i < size; i++)
		buff[i] = '\0';
    i = 0;
	do {

		r = read(fd, buff + len, BUFF_SIZE);
		if (r >= 0)
			i = len, len += r;
		if (r == -1 || r == 0)
			return (-1);
		if  (len >= size)
		{
			sizeold = size, size += BUFF_SIZE;
			buff = _realloc(buff, sizeold, size);
			if (!buff)
				return (MEM_ERROR, 0);
		}
		for (; i < len; i++)
		{
			if (buff[i] == '\n')
			{
				*buffer = buff, *bufsize = size;
				return (len);
			}
		}

	} while (1);
	return (len);
}
/**
 * _strleft - tokenizes a string based on a delimiter
 * @str: string to operate
 * @delim: delimiter
 *
 * Return: pointer to the string remaining after tokenized
 * or NULL if no string remains
 */
char *_strleft (char *str, char *delim)
{
    /* Scan leading delimiters.  */
    str += _strspn (str, delim);
    unsigned int len = _strcspn(str, delim);
    str += len;
    /* Scan leading delimiters.  */
    if (*str == '\0')
        return (NULL);
    if (len == 0)
        return (NULL);
    /* Find the end of the first token and update str_left. */
    return (str);
}
/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **tokenizer(char *str, char *delim)
{
    char **array;
    char table[256];
    char *token;
    int len, i = 0, buffer = 3;

    array = malloc((sizeof(char *) * buffer));

    while (str)
    {
        // extract token to array
        /* Scan leading delimiters and remove */
        str += _strspn (str, delim);
        if (*str == '\0')
            break;
        /* check delimiter on updated string */
        len = _strcspn(str, delim);
        
        token = _memset(table, 0, 256);
        if ((len == 0))
        {
            token = str;
            array[i] = _strdup(token);
            break;
        }
        /* update token */
        token = _strncpy(token, str, len);
        array[i] = _strdup(token);
		array = _realloc(array, (sizeof(char *) * (buffer - 1)), (sizeof(char *) * buffer));
        str = _strleft(str, delim);
        i++;
        buffer++;
    }
    return (array);
}
/**
* checkbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*buildins(char **arv))(char **arv)
{
	int i, j;
	buildin_t T[] = {
		{"exit", _exit_sh},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
