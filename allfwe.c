#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - fork + wait + execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	printf("[Parent] My pid is %u\n", getpid());
	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("[child] My pid is %u\n", getpid());
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
