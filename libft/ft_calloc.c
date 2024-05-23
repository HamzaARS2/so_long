/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:57:17 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 16:05:54 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	char	*ptr;

	bytes = count * size;
	if (size && count != bytes / size)
		return (0);
	ptr = (char *)malloc(bytes);
	if (!ptr)
		return (0);
	ft_bzero(ptr, bytes);
	return ((void *)ptr);
}
