#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **env;
/**
 * struct liststr - singly linked list
 * @number: the number field
 * @str: a string
 * @nxt: points to the next node
 */
typedef struct liststr
{
	int number;
	char *str;
	struct liststr *nxt;
} list_t;

/**
 *struct pass_info - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@linecount: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@first_name: the program filename
 *@env1: linked list local copy of environ
 *@env2: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int linecount;
	int err_num;
	int linecount_flag;
	char *first_name;
	list_t *env1;
	list_t *history;
	list_t *alias;
	char **env2;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/* parse.c */
int is_cmd(info_t *, char *);
char *dupChar(char *, int, int);
char *find_path(info_t *, char *, char *);

/* out.c */
char *_stringcopy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_chr(char *, char);

/*token.c */
char **str_tow(char *, char *);
char **str_tow1(char *, char);

/*rloc.c */
char *mem_set(char *, char, unsigned int);
void set_free(char **);
void *_realloc(void *, unsigned int, unsigned int);

/*mem.c */
int free_it(void **);

/* get_envi.c */
char **get_env(info_t *);
int unset_env(info_t *, char *);
int set_env(info_t *, char *, char *);

/*getInfo.c */
void cls_info(info_t *);
void s_info(info_t *, char **);
void set_free(info_t *, int);

#endif
