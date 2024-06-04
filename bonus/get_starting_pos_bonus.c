/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_pos_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:47:11 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	get_starting_pos(char **map, char c)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == c)
				return ((t_point){k * TILE_SIZE, i * TILE_SIZE});
			k++;
		}
		i++;
	}
	return ((t_point){0});
}
