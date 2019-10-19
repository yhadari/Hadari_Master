/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:48:11 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/19 18:12:38 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstr(const char*src, char a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (src[i] = a)
			i++;
		j++;
		if (src[i + 1] != c) 
			j--;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	*arr = malloc(n * sizeof(char*));
