/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:42:02 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:08:53 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_direction_change(void *param)
{
	t_event		*event;
	t_player	*player;

	event = (t_event *)param;
	player = event->player;
	if (mlx_is_key_down(event->mlx, MLX_KEY_LEFT))
		player->direction = 3;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_RIGHT))
		player->direction = 2;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_UP))
		player->direction = 1;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_DOWN))
		player->direction = 0;
}
