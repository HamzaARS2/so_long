/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:54:13 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_input(void *param)
{
	t_event		*event;
	t_player	*player;

	event = (t_event *)param;
	player = event->player;
	if (mlx_is_key_down(event->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(event->mlx);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_UP))
		set_player_speed(player, 0, -3);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_DOWN))
		set_player_speed(player, 0, 3);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_LEFT))
		set_player_speed(player, -3, 0);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_RIGHT))
		set_player_speed(player, 3, 0);
	else
		set_player_speed(player, 0, 0);
}
