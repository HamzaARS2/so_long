/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:42:02 by helarras          #+#    #+#             */
/*   Updated: 2024/05/29 17:24:39 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_direction(t_player *player, mlx_image_t *current_frame)
{
	int	i;

	i = 0;
	player->current_frame = current_frame;
	player->current_frame->instances[0].x = player->point.x;
	player->current_frame->instances[0].y = player->point.y;
	while (i < 4)
		player->sprites[i++]->enabled = 0;
	player->current_frame->enabled = 1;
}

void	on_direction_change(void *param)
{
	t_event		*event;
	t_player	*player;

	event = (t_event *)param;
	player = event->player;
	if (mlx_is_key_down(event->mlx, MLX_KEY_D))
		player->direction = 1;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_A))
		player->direction = 2;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_W))
		player->direction = 3;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_S))
		player->direction = 0;
	else
		player->direction = 0;
}

void	check_direction(t_player *player)
{
	if (player->direction == 0)
		set_direction(player, player->sprites[0]);
	else if (player->direction == 1)
		set_direction(player, player->sprites[1]);
	else if (player->direction == 2)
		set_direction(player, player->sprites[2]);
	else if (player->direction == 3)
		set_direction(player, player->sprites[3]);
	else if (player->direction == 4)
		set_direction(player, player->sprites[0]);
}
