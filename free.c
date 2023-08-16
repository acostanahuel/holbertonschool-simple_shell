#include "shell.h"

/**
*main: The function frees memory allocated for a grid,
* a list of arguments, a list of paths, and an input string.
* @grid: The `grid` parameter is a 2-dimensional array of strings.
* It represents a grid or table of strings.
* @height: The `height` parameter represents
* the number of rows in the `grid` array.
*/

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
