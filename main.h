#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
/* header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

/* error messages */
#define MEM_ERROR write(2, "Memory Error\n", 13)
#define BUFF_SIZE 8

/* utils */
int _putchar(char c);
void _puts(char *str);
unsigned int _strlen(char *s);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2, char *s3);
char *_strncpy(char *dest, char *src, int n);
char *_memset(char *s, int c_in, unsigned int n);
unsigned int _strspn(char *s, char *accept);
unsigned int _strcspn(char *s, char *accept);

/* print process id */
void print_number(int n);
void _getpid();
void _getppid();

/* prompt: handles signal from terminal */
void sig_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);
void free_argv(char **argv);
void _exit_sh(char **argv);

/* execute */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *s);
void execute(char **argv);

/* built ins */
/**
 * struct buildins - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct buildins
{
	char *name;
	void (*func)(char **);
} buildin_t;
/* Note that fileno(stdin) is 0 */
int _getline(char **buffer, size_t *bufsize, int fd);
char *_strleft (char *str, char *delim);
char **tokenizer(char *str, char *delim);
void(*buildins(char **arv))(char **arv);

/* tools testing */
unsigned int _strspn(char *s, char *accept);
unsigned int _strcspn(char *s, char *accept);
char *_strtok_r_gcc (char *s, char *delim, char **save_ptr);
char *_strtok_gcc (char *s, char *delim);

/* environment */
void env(char **arv __attribute__ ((unused)));
char *_getenv(const char *name);
void _setenv(char **arv);
void _unsetenv(char **arv);

/* path link list */
/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path_t;
list_path_t *add_node_end(list_path_t **head, char *str);
list_path_t *linkpath(char *path);
char *_which(char *filename, list_path_t *head);
void free_list(list_path_t *head);


#endif /* MAIN_H */
