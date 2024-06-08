/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 13:19:19 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_args(int ac)
{
	if (ac == 2)
		return (1);
	ft_printf("Error\nInvalid number of args!\n");
	return (0);
}

int	main(int ac, char *av[])
{
	mlx_t	*mlx;
	t_event	*event;
	t_map	*map;

	if (!check_args(ac))
		return (EXIT_FAILURE);
	map = get_map(av[1]);
	if (!map)
		return (EXIT_FAILURE);
	mlx = mlx_init(map->width, map->height, GAME_NAME, false);
	if (!mlx)
		return (EXIT_FAILURE);
	event = render_game(mlx, map);
	if (!event)
		mlx_close_window(mlx);
	mlx_loop_hook(mlx, handle_input, event);
	mlx_loop_hook(mlx, update_game, event);
	mlx_loop(mlx);
	clean_resources(event, 0);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
