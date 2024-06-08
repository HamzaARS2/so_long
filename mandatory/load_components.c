/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:12:26 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 11:39:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_object	*load_exit(mlx_t *mlx)
{
	t_object	*exit;

	exit = malloc(sizeof(t_object));
	if (!exit)
		return (NULL);
	exit->sprites = malloc(3 * sizeof(mlx_image_t));
	if (!exit->sprites)
	{
		free(exit);
		return (NULL);
	}
	exit->sprites[0] = load_img_texture(mlx,
			"mandatory/textures/exit_closed.png");
	exit->sprites[1] = load_img_texture(mlx,
			"mandatory/textures/exit_opened.png");
	exit->sprites[2] = 0;
	exit->current_frame = 0;
	exit->frame_delay = 0;
	exit->hidden = 0;
	return (exit);
}

t_object	*load_coin(mlx_t *mlx)
{
	t_object	*coin;

	coin = malloc(sizeof(t_object));
	if (!coin)
		return (NULL);
	coin->sprites = malloc(2 * sizeof(mlx_image_t));
	if (!coin->sprites)
	{
		free(coin);
		return (NULL);
	}
	coin->sprites[0] = load_img_texture(mlx, "mandatory/textures/coin_0.png");
	coin->sprites[1] = 0;
	coin->current_frame = 0;
	coin->frame_delay = 0;
	coin->hidden = 0;
	return (coin);
}

t_object	*load_brick(mlx_t *mlx)
{
	t_object	*brick;

	brick = malloc(sizeof(t_object));
	if (!brick)
		return (NULL);
	brick->sprites = malloc(2 * sizeof(mlx_image_t));
	if (!brick->sprites)
		return (NULL);
	brick->sprites[0] = load_img_texture(mlx, "mandatory/textures/brick.png");
	brick->sprites[1] = 0;
	brick->current_frame = 0;
	brick->frame_delay = 0;
	brick->hidden = 0;
	return (brick);
}

t_object	*load_bg(mlx_t *mlx)
{
	t_object	*bg;

	bg = malloc(sizeof(t_object));
	if (!bg)
		return (NULL);
	bg->sprites = malloc(2 * sizeof(mlx_image_t));
	if (!bg->sprites)
		return (NULL);
	bg->sprites[0] = load_img_texture(mlx, "mandatory/textures/bg_brick.png");
	bg->sprites[1] = 0;
	bg->current_frame = 0;
	bg->frame_delay = 0;
	bg->hidden = 0;
	return (bg);
}

t_components	*load_components(mlx_t *mlx)
{
	t_components	*components;

	components = malloc(sizeof(t_components));
	if (!components)
		return (NULL);
	components->brick = load_brick(mlx);
	if (!components->brick)
		return (NULL);
	components->coin = load_coin(mlx);
	if (!components->coin)
		return (NULL);
	components->exit = load_exit(mlx);
	if (!components->exit)
		return (NULL);
	components->bg = load_bg(mlx);
	if (!components->bg)
		return (NULL);
	return (components);
}
