#include "holberton.h"

/**
 * main - which example
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	unsigned int i, j = 0;
	struct stat st;
	char *path;
	char *token, *str1, *path_3;
	char *slash = "/";
	char *path_path[100];

	path = _getenv("PATH");
	if (argc < 2)
	{
		printf("Usage: %s path_to_file ...\n", argv[0]);
		return (1);
	}
	else
	{
		token = strtok(path, ":");

		while( token != NULL ) {
			path_path[j] = token;
/*			printf("path_path[%d]: %s\n", j, path_path[j]);*/
			j++;
			token = strtok(NULL, ":");
			}
		path_path[j] = NULL;
		i = 1;
		while (argv[i])
		{
			str1 = str_concat(slash, argv[i]);
			for (j = 0; path_path[j] != NULL; j++)
			{
				path_3 = str_concat(path_path[j], str1);
/*				printf("path_path[%d]: %s\n", j, path_path[j]);
				printf("path_3: %s\n", path_3);*/

				if (stat(path_3, &st) == 0)
				{
					printf("%s\n", path_3);

				}
			}
			i++;
		}
	}
	return (0);
}
