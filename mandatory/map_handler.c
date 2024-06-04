/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:10:36 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:09:12 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **grid)
{
	size_t	i;
	size_t	row_size;
	size_t	current_size;

	if (!grid || !grid[0])
		return (0);
	i = 0;
	row_size = ft_strlen(grid[0]);
	while (grid[++i])
	{
		current_size = ft_strlen(grid[i]);
		if (!grid[i + 1])
			if (row_size - 1 == current_size && grid[i][row_size - 2] != '\n')
				return (1);
		if (!grid[i + 1] && current_size > row_size - 1)
			return ('R');
		if (row_size != current_size)
			return ('R');
	}
	if (i <= 1)
		return ('R');
	return (1);
}

int	check_components(char **grid)
{
	if (!grid)
		return (0);
	if (!handle_error(is_player_exists(grid)))
		return (0);
	if (!handle_error(is_exit_exists(grid)))
		return (0);
	if (!handle_error(is_collectibles_exists(grid)))
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	if (map->width > 2560 || map->height > 1280)
		return (handle_error('I'));
	if (!handle_error(check_invalid_chars(map->grid)))
		return (0);
	if (!handle_error(is_rectangular(map->grid)))
		return (0);
	if (!handle_error(is_walled(map->grid)))
		return (0);
	return (check_components(map->grid));
}

int	create_map(t_map *map, t_list *data)
{
	size_t	i;
	size_t	data_size;
	t_list	*current;

	i = 0;
	data_size = ft_lstsize(data);
	map->grid = malloc((data_size + 1) * sizeof(char *));
	if (!map->grid)
		return (0);
	current = data;
	while (current)
	{
		map->grid[i] = ft_strdup((current->content));
		if (!map->grid[i])
			return (free_map(map));
		current = current->next;
		i++;
	}
	map->grid[i] = 0;
	map->width = (ft_strlen(map->grid[0]) - 1) * TILE_SIZE;
	map->height = data_size * TILE_SIZE;
	map->start_pos = get_starting_pos(map->grid, 'P');
	return (1);
}

t_map	*get_map(char *file_path)
{
	t_list	*data;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	data = read_data(file_path);
	if (!data)
	{
		free(map);
		return (NULL);
	}
	if (!create_map(map, data))
		return (free_map_data(map, data));
	if (!check_map(map))
		return (free_map_data(map, data));
	if (!can_reach_all(map, map->start_pos.y / TILE_SIZE, map->start_pos.x
			/ TILE_SIZE))
		return (free_map_data(map, data));
	free_data(&data);
	return (map);
}
