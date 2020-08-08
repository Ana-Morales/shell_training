#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
char *str_concat(char *s1, char *s2);
int main(int argc, char *argv[])
{
	unsigned int i, j = 0;
	struct stat st;
	char *path, *token, *str1, *path_3;
	char *slash = "/";
	char *path_path[100];

	path = getenv("PATH");
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
char *str_concat(char *s1, char *s2)
{
	char *conc;
	unsigned int len1 = 0, len2 = 0, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	conc = malloc(sizeof(char) * (len1 + (len2 + 1)));
	if (conc == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		conc[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		conc[len1] = s2[i];
		i++;
		len1++;
	}
	return (conc);
}
