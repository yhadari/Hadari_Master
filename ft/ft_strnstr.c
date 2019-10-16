/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:19:53 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/16 03:59:38 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	char	*ptr1;

	i = 0;
	ptr = (char*)haystack;
	ptr1 = (char*)needle;
	if (*ptr1 == 0)
		return (ptr);
	while ((ptr[i] != '\0' || ptr1[j] != '\0') && i < len)
	{
		j = 0;
		while (ptr[i + j] == ptr1[j] && (i + j) < len)
		{
			j++;
			if (ptr1[j] == '\0')
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
