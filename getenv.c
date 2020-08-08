#include "holberton.h"

char *_getenv(const char *name)
{

	char **env;
	char *tok;
	char *env_name_val[500];
	char *err = "Name not found";
	int i, j;

	env = environ;
	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
/*		printf("%s\n", env[i]);*/
		tok = strtok(env[i], "=");
		while( tok != NULL ) {
                        env_name_val[j] = tok;
/*			printf("env_name_val[%d]: %s\n", j, env_name_val[j]);*/
                        j++;
                        tok = strtok(NULL, "=");
		}
                env_name_val[j] = NULL;
		i++;
	}
	j = 0;
	while (env_name_val[j] != NULL)
	{
/*		printf("env_name_val[%d]: %s name: %s\n", j, env_name_val[j], name);
		printf("%d %d\n", _strlen(env_name_val[j]), _strlen(name));*/
		if (_strcmp(env_name_val[j], name) == 0)
		{
			return (env_name_val[j+1]);
		}
		j++;
	}

	return (err);
}
/*int main()
{
        char *path;

	path = getenv("LS_COLORS");
	printf("%s\n", _getenv("LS_COLORS"));
	printf("%s\n", path);
	return (0);
	}*/
