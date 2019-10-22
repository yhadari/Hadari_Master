/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:14:48 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/22 18:18:25 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	if (*s == '\0')
		return (NULL);
	i = ft_strlen(s);
	while (s[i] != c && i != -1)
		i--;
	if (i == -1)
		return (NULL);
	return ((char*)s + i);
}
