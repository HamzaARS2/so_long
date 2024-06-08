/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:52:43 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 13:06:17 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_moves(mlx_t *mlx, t_player *player)
{
	char	*str_moves;

	player->moves.move_delay++;
	if (player->moves.move_delay <= 7)
		return ;
	player->moves.move_delay = 0;
	player->moves.count++;
	str_moves = ft_itoa(player->moves.count);
	if (player->moves.img)
		mlx_delete_image(mlx, player->moves.img);
	player->moves.img = mlx_put_string(mlx, str_moves, 8, 8);
	free(str_moves);
}
