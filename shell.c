#include "shell.h"

/**
 * get_num_of_words - Gets number of words in string
 * 
 * @delim: delimiter
 * @string: string
 * Return: ul
 */

unsigned long int get_num_of_words(const char *string, char delim)
{


	int count = 1;
	char *ptr = NULL;
	char *ptrcpy = NULL;

	ptr = _strdup(string);
	ptrcpy = ptr;

	while ((ptr = strchr(ptr, delim)) != NULL)
	{
		count++;
		ptr++;
	}

	free(ptrcpy);

	return (count);
}

/**
 * str_to_array - splits a string from imput and 
 * return an array of each word of the string
 *
 *@buffer: buffer 
 *@n: number of words
 *@delim: delimiter
 *
 * return: pointer to array of strings
 */

char **str_to_array(char *buffer, unsigned long int n, char *delim)
{
	
	char *currentToken;
	char **array;
	int i = 0;

	array = malloc(sizeof(char *) * (n + 1));
	currentToken = strtok(buffer, delim);


	while (currentToken)
	{
		array[i] = _strdup(currentToken);
		currentToken = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;

	return (array);
}


/**
 *check_cmd - check existence of cmd command
 *
 *@args: arguments
 *@patharray: pointer to patharray pp to path pointer
 *return: args or NULL
 */


char *check_cmd(char **args, char **patharray, char *argv0)
{
	unsigned long int i;
	char test[1024];
	char *path;
	unsigned long int num_of_words;
	struct stat st;

	if (stat(args[0], &st) == 0)
		return (args[0]);

	path = getpath();
	num_of_words = get_num_of_words(path, ':');

	for (i = 0; i < num_of_words; i++)
	{
		_strcpy(test, patharray[i]);
		_strcat(test, "/");
		_strcat(test, args[0]);

		if (stat(test, &st) == 0)
		{
			free(args[0]);
			free(path);
			args[0] = strdup(test);
			return (args[0]);
		}
	}
	fprintf(stderr, "%s: 1: %s: not found\n", argv0, args[0]);
	free(path);
	free(args[0]);
	return (NULL);
}
