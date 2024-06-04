/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:05:50 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 15:05:51 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_player(t_player *player)
{
	display_cdirection_frame(player);
	player->frame_delay++;
	if (player->frame_delay >= 10)
	{
		player->current_frame++;
		if (player->current_frame > 3)
			player->current_frame = 0;
		player->frame_delay = 0;
	}
	display_cframe(player->sprites[player->direction], player->current_frame);
}
