/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:16:25 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/15 22:56:24 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*ptr;

	i = 0;
	j = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i == start)
		{
			while (len--)
			{
				ptr[j] = s[i];
				i++;
				j++;
			}
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
