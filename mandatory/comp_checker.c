/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:34:42 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:08:51 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	comp_count(char *row, char comp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (row[i])
		if (row[i++] == comp)
			count++;
	return (count);
}

int	is_exit_exists(char **map)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!map)
		return (0);
	while (map[i])
		found += comp_count(map[i++], 'E');
	if (found == 1)
		return (1);
	else if (found > 1)
		return ('M' + 'E');
	return ('E');
}

int	is_player_exists(char **map)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!map)
		return (0);
	while (map[i])
		found += comp_count(map[i++], 'P');
	if (found == 1)
		return (1);
	else if (found > 1)
		return ('M' + 'P');
	return ('P');
}

int	is_collectibles_exists(char **map)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!map)
		return (0);
	while (map[i])
		found += comp_count(map[i++], 'C');
	if (found > 0)
		return (1);
	return ('C');
}

int	check_invalid_chars(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] != '0' && map[i][k] != '1' && map[i][k] != 'P'
				&& map[i][k] != 'E' && map[i][k] != 'C' && map[i][k] != 'X'
				&& map[i][k] != '\n')
				return ('I' + 'M');
			k++;
		}
		i++;
	}
	return (1);
}
