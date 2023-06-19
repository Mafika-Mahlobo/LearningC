#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

extern char **environ;

char *_getenv(const char *name)
{
	unsigned int i = 0;
	char *value;
	char *envar;
	size_t keylen;
	char *envkey;
	char *delim;

	while (environ[i] != NULL)
	{
		envar = environ[i];
		delim = strchr(envar, '=');

		if (delim != NULL)
		{
			keylen = delim - envar;
			envkey = malloc(keylen + 1);

			strncpy(envkey, envar, keylen);
			envkey[keylen] = '\0';

			value = delim + 1;


			if (strcmp(envkey, name) == 0)
			{
				free(envkey);
				return (value);
			}

			free(envkey);
		}
		i++;
	}
	return (NULL);
}
