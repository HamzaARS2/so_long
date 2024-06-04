/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:07:54 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 15:08:00 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*free_enemy(mlx_t *mlx, t_enemy *enemy)
{
	int	i;

	i = 0;
	if (!enemy || !enemy->object)
	{
		free(enemy);
		return (NULL);
	}
	while (enemy->object->sprites && enemy->object->sprites[i])
		mlx_delete_image(mlx, enemy->object->sprites[i++]);
	free(enemy->object->sprites);
	free(enemy->object);
	free(enemy);
	return (NULL);
}

void	set_sprites(mlx_t *mlx, mlx_image_t **sprites)
{
	sprites[0] = load_img_texture(mlx, "bonus/textures/enemy/tile000.png");
	sprites[1] = load_img_texture(mlx, "bonus/textures/enemy/tile001.png");
	sprites[2] = load_img_texture(mlx, "bonus/textures/enemy/tile002.png");
	sprites[3] = load_img_texture(mlx, "bonus/textures/enemy/tile003.png");
	sprites[4] = load_img_texture(mlx, "bonus/textures/enemy/tile004.png");
	sprites[5] = load_img_texture(mlx, "bonus/textures/enemy/tile005.png");
	sprites[6] = load_img_texture(mlx, "bonus/textures/enemy/tile006.png");
	sprites[7] = load_img_texture(mlx, "bonus/textures/enemy/tile007.png");
	sprites[8] = load_img_texture(mlx, "bonus/textures/enemy/tile008.png");
	sprites[9] = load_img_texture(mlx, "bonus/textures/enemy/tile009.png");
	sprites[10] = load_img_texture(mlx, "bonus/textures/enemy/tile010.png");
	sprites[11] = load_img_texture(mlx, "bonus/textures/enemy/tile011.png");
	sprites[12] = load_img_texture(mlx, "bonus/textures/enemy/tile012.png");
	sprites[13] = load_img_texture(mlx, "bonus/textures/enemy/tile013.png");
	sprites[14] = load_img_texture(mlx, "bonus/textures/enemy/tile014.png");
	sprites[15] = load_img_texture(mlx, "bonus/textures/enemy/tile015.png");
	sprites[16] = load_img_texture(mlx, "bonus/textures/enemy/tile016.png");
	sprites[17] = load_img_texture(mlx, "bonus/textures/enemy/tile017.png");
	sprites[18] = load_img_texture(mlx, "bonus/textures/enemy/tile018.png");
	sprites[19] = load_img_texture(mlx, "bonus/textures/enemy/tile019.png");
	sprites[20] = 0;
}

void	update_enemy_pos(t_enemy *enemy)
{
	int			i;
	mlx_image_t	**frames;

	i = 0;
	frames = enemy->object->sprites;
	while (frames[i])
	{
		frames[i]->instances[0].x = enemy->point.x;
		frames[i++]->instances[0].y = enemy->point.y;
	}
}

t_enemy	*load_enemy(mlx_t *mlx, t_point start_pnt)
{
	t_enemy	*enemy;

	if (start_pnt.x == 0 && start_pnt.y == 0)
		return (NULL);
	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->object = malloc(sizeof(t_object));
	if (!enemy->object)
		return (free_enemy(mlx, enemy));
	enemy->object->sprites = malloc(20 * sizeof(mlx_image_t));
	if (!enemy->object->sprites)
		return (free_enemy(mlx, enemy));
	set_sprites(mlx, enemy->object->sprites);
	enemy->object->current_frame = 0;
	enemy->object->frame_delay = 0;
	enemy->object->hidden = 0;
	enemy->point = start_pnt;
	enemy->direction = 2;
	enemy->speed = (t_point){3, 0};
	return (enemy);
}

int	enemy_count(char **map)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (map[i])
		found += comp_count(map[i++], 'X');
	if (found == 1)
		return (1);
	return (0);
}
