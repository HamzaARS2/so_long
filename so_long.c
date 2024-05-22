/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   Updated: 2024/05/22 19:56:10 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_rectangular(t_list *map_list)
{
    t_list *current;
    size_t row_size;
    size_t current_size;
    
    if (!map_list)
        return (0);
    current = map_list->next;
    row_size = ft_strlen((char *)map_list->content);
    while (current)
    {
        current_size = ft_strlen(current->content);
        if (!current->next)
        {
            if (row_size - 1 == current_size)
                return (1);
            if (current_size > row_size - 1)
                return (0);
        }
        if (row_size != current_size)
            return (0);
        current = current->next;
    }
    return (1);
}

int32_t	main(int ac, char *av[])
{
    mlx_t *mlx;
    // char **map;
    
    // mlx = mlx_init(WIDTH, HEIGHT, GAME_NAME, true);
    // if (!mlx)
    //     return (EXIT_FAILURE);
    t_list *data = read_data(av[1]);
    printf("%i\n", is_walled(data));
    
    // mlx_loop(mlx);
    // mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}