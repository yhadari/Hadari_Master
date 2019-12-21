/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:18:38 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/20 23:55:01 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_cstrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != 'c' && s[i] != '%')
	{
		if (s[i] == c)
			return ((char*)s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
