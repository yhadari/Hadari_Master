/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:46:14 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/10 22:50:52 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if ((*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i)) == 0)
			i++;
		else
			return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
