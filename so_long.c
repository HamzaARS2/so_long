/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   Updated: 2024/05/21 16:10:23 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int32_t	main(int ac, char *av[])
{
    mlx_t *mlx;
    char *map;
    
    mlx = mlx_init(WIDTH, HEIGHT, GAME_NAME, true);
    if (!mlx)
        return (EXIT_FAILURE);
    map = read_map(av[1]);
    
    
    mlx_loop(mlx);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}