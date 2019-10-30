/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:59:35 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/26 00:51:06 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d1;
	unsigned char	*s1;
	size_t			i;

	i = 0;
	d1 = (unsigned char*)dst;
	s1 = (unsigned char*)src;
	if (!src && !dst)
		return (NULL);
	if (d1 > s1)
	{
		while (len--)
			d1[len] = s1[len];
	}
	if (d1 < s1)
	{
		while (len--)
		{
			d1[i] = s1[i];
			i++;
		}
	}
	return (d1);
}
