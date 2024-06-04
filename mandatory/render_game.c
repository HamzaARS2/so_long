/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:04:46 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:09:41 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_event	*render_game(mlx_t *mlx, t_map *map)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!event)
		return (NULL);
	*event = (t_event){0};
	event->mlx = mlx;
	event->map = map;
	event->player = load_player(mlx, map->start_pos);
	if (!event->player)
		clean_resources(event, EXIT_FAILURE);
	event->components = load_components(mlx);
	if (!event->components)
		clean_resources(event, EXIT_FAILURE);
	render_map(mlx, event->map, event->components);
	render_player(mlx, event->player);
	return (event);
}
