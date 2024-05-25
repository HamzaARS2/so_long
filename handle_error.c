/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:51:58 by helarras          #+#    #+#             */
/*   Updated: 2024/05/24 17:34:23 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    handle_error(unsigned char error)
{
    if (error == 'E')
        ft_printf("Error\n%s\n", "Exit not found!");
    else if (error == 'M' + 'E')
        ft_printf("Error\n%s\n", "Multiple exits found!");
    else if (error == 'P')
        ft_printf("Error\n%s\n", "Player not found!");
    else if (error == 'M' + 'P')
        ft_printf("Error\n%s\n", "Multiple players found!");
    else if (error == 'C')
        ft_printf("Error\n%s\n", "Collectibles not found!");
    else if (error == 'R')
        ft_printf("Error\n%s\n", "The map is not rectangular");
    else if (error == 'W')
        ft_printf("Error\n%s\n", "The map is not walled!");
    else if (error == 'N' + 'R')
        ft_printf("Error\n%s\n", "Components not reachable!");
    else
        return (1);
    return (0);
}
