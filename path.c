#include "shell.h"
/**
* The above code defines functions to retrieve the PATH environment variable and convert it into an
* array of strings.
*
* @getpatharray: Returns a pointer to a character array (`char **`).
* @Return: pointer.
*/
char **getpatharray(void)
{
	char *path;
	char **patharray;
	unsigned long int num_of_tokens;

	path = getpath();
	num_of_tokens = get_num_of_words(path, ':');
	patharray = str_to_array(path, num_of_tokens, ":\n");
	free(path);

	return (patharray);
}


char
*getpath(void)
{
	int i;
	char *path;
	char envcpy[2048];

	for (i = 0; environ[i]; i++)
	{
		strcpy(envcpy, environ[i]);

		if (strcmp((strtok(envcpy, "=")), "PATH") == 0)
		{
			path = _strdup(strtok(NULL, "\n"));

	return (path);
		}
	}
	return (NULL);
}
