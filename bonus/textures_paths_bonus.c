/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_paths_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:12:56 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 15:12:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**get_down_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 5);
	if (!paths)
		return (NULL);
	paths[0] = "bonus/textures/down/down_walk_0.png";
	paths[1] = "bonus/textures/down/down_walk_1.png";
	paths[2] = "bonus/textures/down/down_walk_2.png";
	paths[3] = "bonus/textures/down/down_walk_3.png";
	paths[4] = 0;
	return (paths);
}

char	**get_up_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 5);
	if (!paths)
		return (NULL);
	paths[0] = "bonus/textures/up/up_walk_0.png";
	paths[1] = "bonus/textures/up/up_walk_1.png";
	paths[2] = "bonus/textures/up/up_walk_2.png";
	paths[3] = "bonus/textures/up/up_walk_3.png";
	paths[4] = 0;
	return (paths);
}

char	**get_right_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 5);
	if (!paths)
		return (NULL);
	paths[0] = "bonus/textures/right/right_walk_0.png";
	paths[1] = "bonus/textures/right/right_walk_1.png";
	paths[2] = "bonus/textures/right/right_walk_2.png";
	paths[3] = "bonus/textures/right/right_walk_3.png";
	paths[4] = 0;
	return (paths);
}

char	**get_left_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 5);
	if (!paths)
		return (NULL);
	paths[0] = "bonus/textures/left/left_walk_0.png";
	paths[1] = "bonus/textures/left/left_walk_1.png";
	paths[2] = "bonus/textures/left/left_walk_2.png";
	paths[3] = "bonus/textures/left/left_walk_3.png";
	paths[4] = 0;
	return (paths);
}

char	**get_idle_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 5);
	if (!paths)
		return (NULL);
	paths[0] = "bonus/textures/idle/idle_0.png";
	paths[1] = "bonus/textures/idle/idle_1.png";
	paths[2] = "bonus/textures/idle/idle_2.png";
	paths[3] = "bonus/textures/idle/idle_3.png";
	paths[4] = 0;
	return (paths);
}
