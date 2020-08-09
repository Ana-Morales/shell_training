#include "holberton.h"
/**
 * main - fork + wait + execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, chars, i;
	char *argv[100];
	char *buffer = NULL;
	char *token, *comm;
        size_t bufsize = 32;
	int satty = 0;

	satty = isatty(0);
	while(1)
	{
		if (satty == 1)
		{
			printf("$ ");
		}
		chars =getline(&buffer, &bufsize, stdin);
		if (chars == 1)
		{
			continue;
		}
		if (chars != -1)
		{
			i = 0;
			token = strtok(buffer, " \n");
			while (token != NULL)
			{
				argv[i] = token;
				i++;
				token = strtok(NULL, " \n");
			}

			comm = _which(argv[0]);

			argv[i] = NULL;
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				return (1);
			}
			if (child_pid == 0)
			{
				if (execve(comm, argv, NULL) == -1)
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
char *_which(char *str)
{
	unsigned int j = 0;
	struct stat st;
	char *path, *path1;
	char *token, *str1, *path_3;
	char *slash = "/";
	char *path_path[100];

	path = _getenv("PATH");
	path1 = strdup(path);
	token = strtok(path1, ":");
	while (token != NULL)
	{
		path_path[j] = token;
		j++;
		token = strtok(NULL, ":");
	}
	free(path1);
	path_path[j] = NULL;

	str1 = str_concat(slash, str);

	for (j = 0; path_path[j] != NULL; j++)
	{
		path_3 = str_concat(path_path[j], str1);
		if (stat(path_3, &st) == 0)
		{
			return(path_3);
		}
	}
	return (str);
}
