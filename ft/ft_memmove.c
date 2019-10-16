/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:59:35 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/11 17:54:52 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char temp[ft_strlen(src)];

	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	return (dst);
}
