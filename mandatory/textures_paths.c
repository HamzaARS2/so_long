/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:12:56 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:42:46 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_down_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 2);
	if (!paths)
		return (NULL);
	paths[0] = "mandatory/textures/down_walk_0.png";
	paths[1] = 0;
	return (paths);
}

char	**get_up_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 2);
	if (!paths)
		return (NULL);
	paths[0] = "mandatory/textures/up_walk_0.png";
	paths[1] = 0;
	return (paths);
}

char	**get_right_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 2);
	if (!paths)
		return (NULL);
	paths[0] = "mandatory/textures/right_walk_0.png";
	paths[1] = 0;
	return (paths);
}

char	**get_left_textures(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 2);
	if (!paths)
		return (NULL);
	paths[0] = "mandatory/textures/left_walk_0.png";
	paths[1] = 0;
	return (paths);
}
