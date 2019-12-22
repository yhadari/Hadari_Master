/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:28:55 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 02:19:57 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != 'u' && s[i] != 'd' && s[i] != 'i')
	{
		if (s[i] == c)
			return ((char*)s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
