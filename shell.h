#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>

#define RED "\033[0;31m"
#define RESET "\e[0m"

extern char **environ;

int _putchar(char c);
int _puts(char *s);
void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t size);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char **split_line(char *line);
int dash_execute(char **args, char *cmd);

#endif
