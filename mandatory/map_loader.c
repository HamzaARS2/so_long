/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:34:09 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:09:15 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_objects(mlx_t *mlx, t_object *object, int x, int y)
{
	int	i;

	i = 0;
	while (object->sprites[i])
	{
		mlx_image_to_window(mlx, object->sprites[i], x, y);
		object->sprites[i]->enabled = 0;
		i++;
	}
	object->sprites[object->current_frame]->enabled = 1;
}

void	draw_row(void *mlx, int y, t_components *components, t_map *map)
{
	int		x;
	t_point	coin_pos;

	x = 0;
	while (map->grid[y][x])
	{
		render_objects(mlx, components->bg, x * TILE_SIZE, y * TILE_SIZE);
		if (map->grid[y][x] == '1')
			render_objects(mlx, components->brick, x * TILE_SIZE, y
				* TILE_SIZE);
		else if (map->grid[y][x] == 'C')
		{
			coin_pos.x = x * TILE_SIZE + COIN_SIZE + COIN_SIZE / 2;
			coin_pos.y = y * TILE_SIZE + COIN_SIZE + COIN_SIZE / 2;
			render_objects(mlx, components->coin, coin_pos.x, coin_pos.y);
		}
		else if (map->grid[y][x] == 'E')
			render_objects(mlx, components->exit, x * TILE_SIZE, y * TILE_SIZE);
		x++;
	}
}

void	render_map(mlx_t *mlx, t_map *map, t_components *components)
{
	int	y;

	y = 0;
	while (map->grid[y])
	{
		draw_row(mlx, y, components, map);
		y++;
	}
}
