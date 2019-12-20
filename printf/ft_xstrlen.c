/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 00:40:10 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/20 00:47:39 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int   ft_xstrlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != 'x' && s[i] != 'X')
		i++;
	return (i);
}
