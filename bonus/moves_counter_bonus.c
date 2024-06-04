/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:52:43 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 15:11:07 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_moves(mlx_t *mlx, t_player *player)
{
	char	*str_moves;

	player->moves.count++;
	str_moves = ft_itoa(player->moves.count);
	if (player->moves.img)
		mlx_delete_image(mlx, player->moves.img);
	player->moves.img = mlx_put_string(mlx, str_moves, 32, 32);
	free(str_moves);
}
