/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:19:49 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/22 18:18:48 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	i = 0;
	while (d1[i] - d2[i] == 0 && i < (n - 1) && d1[i] != 0 && d2[i] != 0)
		i++;
	return (d1[i] - d2[i]);
}
