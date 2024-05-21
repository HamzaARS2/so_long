/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:29:51 by helarras          #+#    #+#             */
/*   Updated: 2024/05/19 18:18:36 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    set_color(void *pixels, size_t area, int rgba) 
{
    size_t i;
    
    i = 0;
    while (i < area)
        ((int *)pixels)[i++] = rgba;
    return (rgba);
}