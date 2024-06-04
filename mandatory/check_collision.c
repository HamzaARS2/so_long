/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:52:55 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:08:47 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_collided_instance(mlx_image_t *img_obj, int new_x, int new_y)
{
	size_t	i;
	int		obj_x;
	int		obj_y;
	int		width;
	int		height;

	width = img_obj->width;
	height = img_obj->height;
	i = 0;
	while (i < img_obj->count)
	{
		obj_x = img_obj->instances[i].x;
		obj_y = img_obj->instances[i].y;
		if (new_x < obj_x + width && new_x + PLAYER_SIZE > obj_x
			&& new_y < obj_y + height && new_y + PLAYER_SIZE > obj_y)
			return (i);
		i++;
	}
	return (-1);
}

int	check_collision(t_map *map, int new_x, int new_y, char obj)
{
	t_point	top_left;
	t_point	top_right;
	t_point	bot_left;
	t_point	bot_right;

	top_left.x = (new_x + 10) / TILE_SIZE;
	top_left.y = (new_y + 10) / TILE_SIZE;
	top_right.x = (new_x + PLAYER_SIZE - 10) / TILE_SIZE;
	top_right.y = (new_y + 10) / TILE_SIZE;
	bot_left.x = (new_x + 10) / TILE_SIZE;
	bot_left.y = (new_y + PLAYER_SIZE - 10) / TILE_SIZE;
	bot_right.x = (new_x + PLAYER_SIZE - 10) / TILE_SIZE;
	bot_right.y = (new_y + PLAYER_SIZE - 10) / TILE_SIZE;
	if (map->grid[top_left.y][top_left.x] == obj
		|| map->grid[top_right.y][top_right.x] == obj
		|| map->grid[bot_left.y][bot_left.x] == obj
		|| map->grid[bot_right.y][bot_right.x] == obj)
		return (0);
	return (1);
}
