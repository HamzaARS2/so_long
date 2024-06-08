/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:52:43 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 13:12:37 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_player *player)
{
	player->moves.move_delay++;
	if (player->moves.move_delay <= 7)
		return ;
	player->moves.move_delay = 0;
	player->moves.count++;
	ft_printf("moves: %i\n", player->moves.count);
}
