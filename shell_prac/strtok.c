#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* split - returns array of separated words from string
* str: string provided by uer
* Return: Always 0 
*/

char **split(char *str)
{
	char **arr = malloc(MAX_SIZE * sizeof(char*));
	char *token = strtok(str, " ");
	int i = 0;

	while (token != NULL)
	{
		arr[i] = malloc((strlen(token) + 1) * sizeof(char));
		strcpy(arr[i], token);
		i++;
		token = strtok(NULL, " ");
	}

	arr[i] = NULL;

	return (arr);
}

/**
* main - prints all elements of array (returned from split function)
* Return: Always 0
*/

int main()
{
	int i  = 0;
	int j = 0;

	char str[MAX_SIZE];

	printf("enter a word: ");
	fgets(str, sizeof(str), stdin);

	char **words = split(str);

	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		i++;
	}

	for (; j < i; j++)
		free(words[j]);
	free(words);

	return (0);

}
