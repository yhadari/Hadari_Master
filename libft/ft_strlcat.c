/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:25:59 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/19 16:02:38 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = size;
	while (n-- != 0 && dst[i] != '\0')
		i++;
	n = size - i;
	if (n == 0)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] != '\0')
	{
		if (n != 1)
		{
			dst[i] = src[j];
			n--;
		}
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i);
}
