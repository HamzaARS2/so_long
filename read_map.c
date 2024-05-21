/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:38:02 by helarras          #+#    #+#             */
/*   Updated: 2024/05/21 16:01:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *read_map(char *file_path)
{
    int     fd;
    char    *map;
    char    *row;
    
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return (0);
    map = 0;
    while (1)
    {
        row = get_next_line(fd);
        if (!row)
            break ;
        map = strcombine(map, row);
        if (!map)
            break ;
    }
    return (map);
}