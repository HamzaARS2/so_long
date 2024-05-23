/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:33:06 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 16:06:37 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_bytes;
	char	*dest;

	s1_bytes = ft_strlen(s1) + 1;
	dest = (char *)malloc(s1_bytes * sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, s1_bytes);
	return (dest);
}
