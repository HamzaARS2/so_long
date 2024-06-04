/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coins_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:32:27 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_all_coins_collected(t_object *coin, t_object *exit)
{
	if (coin->hidden >= coin->sprites[coin->current_frame]->count
		&& !exit->sprites[1]->enabled)
	{
		exit->sprites[0]->enabled = 0;
		exit->sprites[1]->enabled = 1;
	}
}
