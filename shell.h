#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


extern char **environ;

void _print_prompt(void);
int _execute_command(char *argv[], char *command[], int counter, char *env[]);
int strLen_func(const char *my_input);
char *strduplicate_func(const char *original);
char *strcopy_func(char *destination, const char *source);
void _error_handler(char *name, int counter, char **command, int status);
int _count_commands(const char *command);
char **_create_full_command(const char *command);
char *_int_to_string(int number);
char *_get_path(void);
int stringcompare_func(const char *str_one, const char *str_two, size_t num_bytes);
char *_check_path(const char *command);
char *strduplicate_func(const char *original);
char *_get_input(void);
void _print_env(char **env);
int _check_exit(char **full_command);
long int stringtoint_func(char *input_string);
void _free_full_command(char **full_command);

#endif
