#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcnt1.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>

/*  buffers sizes */
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* chain macros */
#define CMD_CHAIN 3
#define CMD_OR    1
#define CMD_NORM  0
#define CMD_AND   2

/* case and signconverting indication */
#define CONVERT_UNSIGNED    2
#define CONVERT_LOWERCASE   1

/* getline indication */
#define USE_STRTOK     0
#define USE_GETLINE    0

#define HIST_MAX       4096
#define HIST_FILE      ".simple_shell_history"

extern char **environ;

/**
 * struct liststr - this is a linkedlist in which nodes 
 * has one pionter
 * @num: number parameter
 * @str: array of chars
 * @next: pointer to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - a structure that contains info that will be passed
 * to function
 *@arg: a string generated from getline containing arguements
 *@argv:arg returni ng value as array
 *@path: the path of the command as tring
 *@argc: thenumber ofaruments
 *@line_count: the number of errors
 *@err_num: the number that indicate exit error
 *@linecount_flag: flag that indicate to count input line
 *@fname: the name of the program file
 *@env: environment copy that is local formed as linked list 
 *@environ: environment copy of the modified lnked list
 *@history: the node that is inhistory
 *@alias: node that is alias
 *@env_changed: flag that indicate change in environment
 *@status: the status retuned from the command that executd lastly
 *@cmd_buf: address of pointer to command buffer
 *@cmd_buf_type: command buffer type
 *@readfd: the variable that responsible forget the input line
 *@histcount: the coun of history lines
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - structure that contained string and functions
 *@type: the flag of the command
 *@func: refering to functions
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* declaration of toem_shloop.c methods*/
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* declaration of toem_parser.c methods*/
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* declaration of loophsh.c methods*/
int loophsh(char **);

/* declaration of toem errors methods */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* methods in toem string declaration */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem string1 declaration methods*/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* declaration of toem exits methods */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/*declaration of toem tokenizer functions*/
char **strtow(char *, char *);
char **strtow2(char *, char);

/* declaration of toem realloc functions */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* declaration of toem memory functions */
int bfree(void **);

/* declaration of toem atoi function */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* declaration of toem errors1 function */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* declaration of toem builtin function */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* declaration of toem builtin1 function */
int _myhistory(info_t *);
int _myalias(info_t *);

/* declaration of toem getline function */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* declaration of toem getinfo function */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* declaration toem environ function */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* declaration of toem getenv function*/
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* declartion of toem history function */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* declartion of toem lists function */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* declaration of toem lists1 function */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* declaration of toem vars function */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
