/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:10:46 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 15:10:47 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemy_direction(t_enemy *enemy)
{
	if (enemy->direction == 0)
		enemy->speed = (t_point){0, 3};
	else if (enemy->direction == 1)
		enemy->speed = (t_point){0, -3};
	else if (enemy->direction == 2)
		enemy->speed = (t_point){3, 0};
	else if (enemy->direction == 3)
		enemy->speed = (t_point){-3, 0};
}

int	check_enemy_collision(t_map *map, int new_x, int new_y, char obj)
{
	t_point	top_left;
	t_point	top_right;
	t_point	bot_left;
	t_point	bot_right;

	top_left.x = (new_x + 10) / TILE_SIZE;
	top_left.y = (new_y + 10) / TILE_SIZE;
	top_right.x = (new_x + ENEMY_SIZE - 20) / TILE_SIZE;
	top_right.y = (new_y + 10) / TILE_SIZE;
	bot_left.x = (new_x + 20) / TILE_SIZE;
	bot_left.y = (new_y + ENEMY_SIZE - 20) / TILE_SIZE;
	bot_right.x = (new_x + ENEMY_SIZE - 20) / TILE_SIZE;
	bot_right.y = (new_y + ENEMY_SIZE - 20) / TILE_SIZE;
	if (map->grid[top_left.y][top_left.x] == obj
		|| map->grid[top_right.y][top_right.x] == obj
		|| map->grid[bot_left.y][bot_left.x] == obj
		|| map->grid[bot_right.y][bot_right.x] == obj)
		return (0);
	return (1);
}

void	move_enemy(t_map *map, t_enemy *enemy, char obj)
{
	int	new_x;
	int	new_y;

	new_y = enemy->point.y + enemy->speed.y;
	new_x = enemy->point.x + enemy->speed.x;
	if (!check_enemy_collision(map, new_x, new_y, obj))
	{
		enemy->direction = (rand() % 4);
		set_enemy_direction(enemy);
		return ;
	}
	enemy->point.x = new_x;
	enemy->point.y = new_y;
}
