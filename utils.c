/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:39:21 by helarras          #+#    #+#             */
/*   Updated: 2024/05/26 20:53:30 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_player(mlx_t *mlx, t_player *player)
{
    int i;

    if (!player || !player->sprites)
        return ;
    i = 0;
    while (player->sprites[i]) {

        mlx_delete_image(mlx, player->sprites[i++]);
    }
    free(player->sprites);
    free(player);
}

void    free_map(t_map *map)
{
    int i;

    if (!map || map->grid)
        return ;
    i = 0;
    while (map->grid[i])
        free(map->grid[i++]);
    free(map->grid);
    free(map);
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
        free(current);
		current = next;
	}
	*data = NULL;
    return (0);
}