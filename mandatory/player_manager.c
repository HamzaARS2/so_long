/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:16 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 13:11:09 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*load_player(mlx_t *mlx, t_point start_pos)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->sprites = create_sprites(mlx);
	if (!player->sprites)
		return (0);
	player->point = start_pos;
	player->speed_x = 0;
	player->speed_y = 0;
	player->direction = 0;
	player->moves = (t_moves){0};
	player->current_frame = 0;
	return (player);
}

void	render_player(mlx_t *mlx, t_player *player)
{
	load_sprites(mlx, player);
}

void	set_player_speed(t_player *player, int speed_x, int speed_y)
{
	player->speed_x = speed_x;
	player->speed_y = speed_y;
}
