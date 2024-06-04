/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_object_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:44 by helarras          #+#    #+#             */
/*   Updated: 2024/06/04 15:05:33 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_object(t_object *object, int frames_num)
{
	object->frame_delay++;
	if (object->frame_delay >= 8)
	{
		object->current_frame++;
		if (object->current_frame >= frames_num)
			object->current_frame = 0;
		display_cframe(object->sprites, object->current_frame);
		object->frame_delay = 0;
	}
}
