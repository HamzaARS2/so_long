#include "so_long.h"

static int is_valid(char **grid, int y, int x)
{
    if (y < 0 || x < 0)
        return 0;
    if (grid[y][x] == '1') // If it's a wall or already visited
        return 0;
    return 1;
}
void    print(char **grid)
{
    int i = 0;
    while (grid[i])
       printf("%s", grid[i++]);
    printf("\n");
}
void dfs(char **grid, int y, int x)
{
    if (!is_valid(grid, y, x))
        return;

    grid[y][x] = '1'; // Mark as visited
    dfs(grid, y + 1, x);
    dfs(grid, y - 1, x);
    dfs(grid, y, x + 1);
    dfs(grid, y, x - 1);
}
char **copy_grid(char **grid, int size)
{
    int i;
    char **grid_cpy;

    i = 0;
    grid_cpy = malloc((size + 1)* sizeof(char *));
    if (!grid_cpy)
        return (0);
    while (i < size) {
        grid_cpy[i] = ft_strdup(grid[i]);
        i++;
    }
    grid_cpy[i] = 0;

    return grid_cpy;
}

void free_grid(char **grid, int size)
{
    int i;

    i = 0;
    while (i < size)
        free(grid[i++]);
    free(grid);
}
int can_reach_all(t_map *map, int start_y, int start_x)
{
    int i;
    int k;
    char **grid_cpy;

    i = 0;
    grid_cpy = copy_grid(map->grid, map->height / TILE_SIZE);
    if (!grid_cpy)
        return (0);
    dfs(grid_cpy, start_y, start_x);
    while (grid_cpy[i])
    {
        k = 0;
        while (grid_cpy[i][k])
        {
            if (grid_cpy[i][k] == 'C' || grid_cpy[i][k] == 'E')
                return (0);
            k++;
        }
        i++;
    }
    free_grid(grid_cpy, map->height / TILE_SIZE);
    return 1;
}
