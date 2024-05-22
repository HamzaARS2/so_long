/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:38:02 by helarras          #+#    #+#             */
/*   Updated: 2024/05/22 18:51:59 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list  *read_data(char *file_path)
{
    int     fd;
    char    *row;
    t_list  *data;

    if (!file_path)
        return (0);
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return (&(t_list){0});
    while (1)
    {
        row = get_next_line(fd);
        if (!row)
            break;
        ft_lstadd_back(&data, ft_lstnew(row));
    }
    return (data);
}
