/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:02:05 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:09:48 by helarras         ###   ########.fr       */
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

mlx_image_t	**get_player_frames(mlx_t *mlx, char **paths)
{
	mlx_image_t	**frames;

	if (!paths)
		return (NULL);
	frames = malloc(sizeof(mlx_image_t *) * 2);
	if (!frames)
		return (NULL);
	frames[0] = load_img_texture(mlx, paths[0]);
	frames[1] = 0;
	free(paths);
	return (frames);
}

mlx_image_t	***create_sprites(mlx_t *mlx)
{
	mlx_image_t	***sprites;

	sprites = malloc(sizeof(mlx_image_t **) * 5);
	if (!sprites)
		return (NULL);
	sprites[0] = get_player_frames(mlx, get_down_textures());
	sprites[1] = get_player_frames(mlx, get_up_textures());
	sprites[2] = get_player_frames(mlx, get_right_textures());
	sprites[3] = get_player_frames(mlx, get_left_textures());
	sprites[4] = 0;
	return (sprites);
}

void	load_frames(mlx_t *mlx, mlx_image_t **frames, t_point point)
{
	int	i;

	i = 0;
	while (frames[i])
	{
		mlx_image_to_window(mlx, frames[i], point.x, point.y);
		frames[i]->enabled = 0;
		i++;
	}
}

void	load_sprites(mlx_t *mlx, t_player *player)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		load_frames(mlx, player->sprites[i], player->point);
		i++;
	}
	display_cframe(player->sprites[0], 0);
}
