#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>



pid_t wait(int *status);

extern char **environ;

int strLen_func(const char *my_input);
char *strcopy_func(char *destination, const char *source);
int stringcompare_func(const char *str_one, const char *str_two, size_t num_bytes);
char *strduplicate_func(const char *original);
long int stringtoint_func(char *input_string);
void prompt(void);
void environment(char **env_variable);
char *convertIntegar(int num);
char *path(void);
char *input(void);
char *checkpathcorrection(const char *command);
int exitfuncs(char **exitcommand);
void all_command(char **fullque);
int execommand(char **argv, char **com, int countnum, char **enviro);
int countcom(const char *com);
void handler(char *yet, int countnum, char **com, int yetstatu);
char **createcommand(const char *com);
char *strconcat_func(char *destination, const char *source);



#endif
