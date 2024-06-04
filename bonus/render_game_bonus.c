/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:04:46 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:12:46 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_event	*render_game(mlx_t *mlx, t_map *map)
{
	t_event	*event;
	t_point	enemy_point;

	event = malloc(sizeof(t_event));
	if (!event)
		return (NULL);
	*event = (t_event){0};
	enemy_point = get_starting_pos(map->grid, 'X');
	event->mlx = mlx;
	event->map = map;
	event->enemy = load_enemy(event->mlx, enemy_point);
	if (!event->enemy)
		clean_resources(event, 'E' + 'N');
	event->player = load_player(mlx, map->start_pos);
	if (!event->player)
		clean_resources(event, EXIT_FAILURE);
	event->components = load_components(mlx);
	if (!event->components)
		clean_resources(event, EXIT_FAILURE);
	render_map(mlx, event->map, event->components);
	render_player(mlx, event->player);
	render_objects(mlx, event->enemy->object, enemy_point.x, enemy_point.y);
	return (event);
}
