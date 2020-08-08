#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - fork + wait + execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, chars;
	char *argv[] = {NULL, NULL};
	char *buffer = NULL;
        size_t bufsize = 32;
	int satty = 0;

	satty = isatty(0);
	while(1)
	{
		if (satty == 1)
		{
			printf("$ ");
		}
		chars =	getline(&buffer, &bufsize, stdin);
		if (chars != -1)
		{
			argv[0] = strtok(buffer, "\n");
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				return (1);
			}
			if (child_pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("./shell");
				}
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			break;
		}
	}
	return (0);
}
