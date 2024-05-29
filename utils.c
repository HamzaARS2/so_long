/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:39:21 by helarras          #+#    #+#             */
/*   Updated: 2024/05/29 18:13:01 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_player(mlx_t *mlx, t_player *player)
{
	int	i;

	if (!player || !player->sprites)
		return ;
	i = 0;
	while (player->sprites[i])
	{
		mlx_delete_image(mlx, player->sprites[i++]);
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

void	free_textures(mlx_t *mlx, mlx_texture_t **textures, int num_textures)
{
	int	i;

	i = 0;
	while (i < num_textures)
		mlx_delete_texture(textures[i++]);
	free(textures);
}
