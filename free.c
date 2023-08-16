#include "shell.h"

void 
free_grid(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}

void 
free_all(char **args, uli nargs, char **path, uli npath, char *input)
{
	free_grid(args, nargs);
	free_grid(path, npath);
	free(input);
}
