#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int _putchar(char c);
void _puts(char *str);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
#endif /*_HOLBERTON_H_*/
