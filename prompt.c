#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t bufsize = 32;

	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);
	return (0);
}
