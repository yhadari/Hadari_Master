/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:16:18 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/16 04:10:19 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ifbegi(const char *src, const char *sub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && sub[j] != '\0')
	{
		if (src[i] == sub[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static int		ifend(const char *src, const char *sub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	i = i - 1;
	while (sub[j] != '\0')
	{
		if (src[i] == sub[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		size;

	size = (ifend(s1, set) - ifbegi(s1, set));
	if (size < 0)
		return ("");
	ptr = ft_substr(s1, ifbegi(s1, set), size + 1);
	ptr[size + 1] = '\0';
	return (ptr);
}
