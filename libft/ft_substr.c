/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:16:25 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/28 17:59:51 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		return (ft_strdup((char*)s + start));
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
