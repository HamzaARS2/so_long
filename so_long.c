/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:59:43 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    onexit()
{
    system("leaks -q gameoftheyear");
}


int32_t	main(int ac, char *av[])
{
    mlx_t *mlx;
    t_event *event;
    t_map *map;

//    atexit(onexit);
    map = get_map(av[1]);
    if (!map)
        return (EXIT_FAILURE);
    mlx = mlx_init(map->width,map->height, GAME_NAME, true);
    if (!mlx)
        return (EXIT_FAILURE);
    event = render_game(mlx, map);
    mlx_loop_hook(mlx, on_direction_change, event);
    mlx_loop_hook(mlx, handle_input, event);
    mlx_loop_hook(mlx, update_game, event);
    mlx_loop(mlx);

    clean_resources(event);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
