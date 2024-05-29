/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:04:46 by helarras          #+#    #+#             */
/*   Updated: 2024/05/29 18:15:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_event	*render_game(mlx_t *mlx, t_map *map)
{
	t_player	*player;
	t_event		*event;

	event = malloc(sizeof(t_event));
	if (!event)
		return (NULL);
	event->mlx = mlx;
	event->map = map;
	event->components = 0;
	event->player = load_player(mlx, get_starting_pos(map->grid));
	if (!event->player)
	{
		clean_resources(event);
		exit(1);
	}
	event->components = load_components(mlx);
	if (!event->components)
	{
		clean_resources(event);
		exit(1);
	}
	render_map(mlx, event->map, event->components);
	render_player(mlx, event->player);
	return (event);
}
