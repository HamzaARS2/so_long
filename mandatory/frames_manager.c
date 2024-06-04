/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:26:28 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:08:56 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_frames_pos(mlx_image_t **frames, int x, int y)
{
	int	i;

	i = 0;
	while (frames[i])
	{
		frames[i]->instances[0].x = x;
		frames[i]->instances[0].y = y;
		i++;
	}
}

void	display_cframe(mlx_image_t **frames, int current_frame)
{
	int	i;

	i = 0;
	while (frames[i])
	{
		if (i == current_frame)
			frames[i]->enabled = 1;
		else
			frames[i]->enabled = 0;
		i++;
	}
}

void	display_cdirection_frame(t_player *player)
{
	int	i;

	i = 0;
	while (i < 4)
		display_cframe(player->sprites[i++], -1);
	if (player->direction == 0)
		display_cframe(player->sprites[0], 0);
	else if (player->direction == 1)
		display_cframe(player->sprites[1], 0);
	else if (player->direction == 2)
		display_cframe(player->sprites[2], 0);
	else if (player->direction == 3)
		display_cframe(player->sprites[3], 0);
}
