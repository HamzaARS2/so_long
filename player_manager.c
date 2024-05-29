/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:16 by helarras          #+#    #+#             */
/*   Updated: 2024/05/29 18:04:08 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	**load_textures(void)
{
	mlx_texture_t	**textures;

	textures = malloc(sizeof(mlx_texture_t *) * 4);
	if (!textures)
		return (NULL);
	textures[0] = mlx_load_png("textures/down_walk_0.png");
	textures[1] = mlx_load_png("textures/right_walk_0.png");
	textures[2] = mlx_load_png("textures/left_walk_0.png");
	textures[3] = mlx_load_png("textures/up_walk_0.png");
	return (textures);
}

t_player	*load_player(mlx_t *mlx, t_point start_pos)
{
	int				i;
	t_player		*player;
	mlx_texture_t	**textures;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	textures = load_textures();
	if (!textures)
		return (0);
	player->sprites = create_sprites(mlx, textures, 4);
	if (!player->sprites)
		return (0);
	player->point = start_pos;
	player->speed_x = 0;
	player->speed_y = 0;
	player->direction = 0;
	player->moves = 0;
	player->current_frame = player->sprites[0];
	return (player);
}

void	render_player(mlx_t *mlx, t_player *player)
{
	load_sprites(mlx, player);
}

void	set_player_speed(t_player *player, int speed_x, int speed_y)
{
	player->speed_x = speed_x;
	player->speed_y = speed_y;
}
