/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:01:34 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/25 23:26:13 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		if ((unsigned char)c == *((unsigned char*)src + i))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
