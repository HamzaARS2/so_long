/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:38:02 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*handle_data_error(unsigned char error)
{
	if (error == 'e' + 'x')
		ft_printf("Error\nInvalid map extension!\n");
	else if (error == 'n')
		ft_printf("Error\nInvalid map!\n");
	return (NULL);
}

int	is_valid_extension(char *path)
{
	size_t	size;

	if (!path)
		return (0);
	size = ft_strlen(path);
	if (size < 5)
		return (0);
	if (path[size - 1] == 'r' && path[size - 2] == 'e' && path[size - 3] == 'b'
		&& path[size - 4] == '.')
		return (1);
	return (0);
}

t_list	*read_data(char *file_path)
{
	int		fd;
	char	*row;
	t_list	*data;

	if (!is_valid_extension(file_path))
		return (handle_data_error('e' + 'x'));
	data = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		handle_error('F');
		return (NULL);
	}
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		ft_lstadd_back(&data, ft_lstnew(row));
	}
	if (data == 0)
		return (handle_data_error('n'));
	return (data);
}
