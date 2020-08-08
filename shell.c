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
	int status;
	char *argv[] = {NULL, NULL};
	char *buffer = NULL;
        size_t bufsize = 32;



	while(1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		argv[0] = strtok(buffer, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("%s",argv[0]);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
