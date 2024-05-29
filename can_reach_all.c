/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_reach_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:19:49 by helarras          #+#    #+#             */
/*   Updated: 2024/05/29 17:19:50 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid(char **grid, int y, int x)
{
	if (y < 0 || x < 0)
		return (0);
	if (grid[y][x] == '1')
		return (0);
	return (1);
}

void	dfs(char **grid, int y, int x)
{
	if (!is_valid(grid, y, x))
		return ;
	grid[y][x] = '1';
	dfs(grid, y + 1, x);
	dfs(grid, y - 1, x);
	dfs(grid, y, x + 1);
	dfs(grid, y, x - 1);
}

void	free_grid(char **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(grid[i++]);
	free(grid);
}

char	**copy_grid(char **grid, int size)
{
	int		i;
	char	**grid_cpy;

	i = 0;
	grid_cpy = malloc((size + 1) * sizeof(char *));
	if (!grid_cpy)
		return (0);
	while (i < size)
	{
		grid_cpy[i] = ft_strdup(grid[i]);
		if (!grid_cpy[i])
		{
			free_grid(grid_cpy, i);
			return (0);
		}
		i++;
	}
	grid_cpy[i] = 0;
	return (grid_cpy);
}

int	can_reach_all(t_map *map, int start_y, int start_x)
{
	int		i;
	int		k;
	char	**grid_cpy;

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
			{
				free_grid(grid_cpy, map->height / TILE_SIZE);
				return (handle_error('N' + 'R'));
			}
			k++;
		}
		i++;
	}
	free_grid(grid_cpy, map->height / TILE_SIZE);
	return (1);
}
