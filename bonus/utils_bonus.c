/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:39:21 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_player(mlx_t *mlx, t_player *player)
{
	int	i;

	if (!player || !player->sprites)
		return ;
	i = 0;
	while (i < 5)
	{
		mlx_delete_image(mlx, player->sprites[i][0]);
		mlx_delete_image(mlx, player->sprites[i][1]);
		mlx_delete_image(mlx, player->sprites[i][2]);
		mlx_delete_image(mlx, player->sprites[i][3]);
		free(player->sprites[i++]);
	}
	free(player->sprites);
	free(player);
}

int	free_map(t_map *map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map->grid && map->grid[i])
		free(map->grid[i++]);
	free(map->grid);
	free(map);
	return (0);
}

int	free_data(t_list **data)
{
	t_list	*current;
	t_list	*next;

	if (!data)
		return (0);
	current = *data;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*data = NULL;
	return (0);
}

void	*free_map_data(t_map *map, t_list *data)
{
	free_data(&data);
	free_map(map);
	return (NULL);
}
