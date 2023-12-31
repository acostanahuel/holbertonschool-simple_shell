#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


typedef unsigned long int uli;

extern char **environ;


unsigned long int get_num_of_words(const char *string, char delim);
char **str_to_array(char *buffer, unsigned long int n, char *delim);
char *check_cmd(char **args, char **patharray, char *argv0);
char **getpatharray(void);
char *getpath(void);
char *get_input_str(int mode);
void free_all(char **args, uli nargs, char **path, uli npath, char *input);
void free_grid(char **grid, int height);

/*auxiliar*/

int fork_and_exec(char **args);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);



#endif
