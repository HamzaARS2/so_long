/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:02:05 by helarras          #+#    #+#             */
/*   Updated: 2024/05/29 18:06:19 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(mlx_t *mlx, mlx_image_t **sprites, int num_textures)
{
	int	i;

	i = 0;
	while (i < num_textures)
	{
		if (sprites[i])
			mlx_delete_image(mlx, sprites[i]);
		i++;
	}
	free(sprites);
}

mlx_image_t	**create_sprites(mlx_t *mlx, mlx_texture_t **textures,
		int num_textures)
{
	mlx_image_t	**sprites;
	int			i;
	int			j;

	sprites = malloc(sizeof(mlx_image_t *) * num_textures);
	if (!sprites)
		return (NULL);
	i = 0;
	while (i < num_textures)
	{
		sprites[i] = mlx_texture_to_image(mlx, textures[i]);
		if (!sprites[i])
		{
			free_sprites(mlx, sprites, i);
			free_textures(mlx, textures, num_textures);
			return (NULL);
		}
		i++;
	}
	free_textures(mlx, textures, num_textures);
	return (sprites);
}

void	load_sprites(mlx_t *mlx, t_player *player)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_image_to_window(mlx, player->sprites[i], player->point.x,
			player->point.y);
		player->sprites[i]->enabled = 0;
		i++;
	}
	player->current_frame->enabled = 1;
}
