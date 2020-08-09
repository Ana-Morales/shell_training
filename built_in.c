#include "holberton.h"

void exit_func()
{
	exit(EXIT_SUCCESS);
}

void display_env()
{
        char **ep;
        for (ep = environ; *ep != NULL; ep++)
                _puts(*ep);
        return;
}
