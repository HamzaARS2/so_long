/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:54:28 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 12:52:09 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hide_object_instance(t_object *object, int instance)
{
	int	i;

	if (instance == -1
		|| !object->sprites[object->current_frame]->instances[instance].enabled)
		return ;
	object->hidden++;
	i = 0;
	while (object->sprites[i])
		object->sprites[i++]->instances[instance].enabled = 0;
}

void	handle_coin_collision(t_event *event)
{
	t_player		*player;
	t_components	*components;
	int				new_x;
	int				new_y;
	int				instance;

	player = event->player;
	components = event->components;
	new_x = player->point.x;
	new_y = player->point.y;
	if (!check_collision(event->map, new_x, new_y, 'C'))
	{
		instance = get_collided_instance(components->coin->sprites
			[components->coin->current_frame],
				new_x,
				new_y);
		hide_object_instance(components->coin, instance);
	}
}

void	on_player_exit(t_event *event)
{
	t_player	*player;
	t_object	*exit;
	int			new_x;
	int			new_y;

	player = event->player;
	exit = event->components->exit;
	new_x = player->point.x;
	new_y = player->point.y;
	if (!check_collision(event->map, new_x + PLAYER_SIZE / 2, new_y
			+ PLAYER_SIZE / 2, 'E') && exit->sprites[1]->enabled)
	{
		mlx_close_window(event->mlx);
	}
}

void	update_player_position(t_player *player, int new_x, int new_y)
{
	player->point.x = new_x;
	player->point.y = new_y;
	change_frames_pos(player->sprites[0], player->point.x, player->point.y);
	change_frames_pos(player->sprites[1], player->point.x, player->point.y);
	change_frames_pos(player->sprites[2], player->point.x, player->point.y);
	change_frames_pos(player->sprites[3], player->point.x, player->point.y);
	count_moves(player);
}

void	update_game(void *param)
{
	int			new_x;
	int			new_y;
	t_event		*event;
	t_player	*player;

	event = (t_event *)param;
	player = event->player;
	new_x = player->point.x + player->speed_x;
	new_y = player->point.y + player->speed_y;
	if (new_x != player->point.x || new_y != player->point.y)
	{
		if (check_collision(event->map, new_x, new_y, '1'))
			update_player_position(player, new_x, new_y);
	}
	display_cdirection_frame(player);
	handle_coin_collision(event);
	check_all_coins_collected(event->components->coin, event->components->exit);
	on_player_exit(event);
}
