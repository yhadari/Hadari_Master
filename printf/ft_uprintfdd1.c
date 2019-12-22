/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintfdd1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:51:54 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:52:06 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_upointzero(const char *str, long long *nb)
{
	while ((*nb)-- > ft_ustrlen(str))
		ft_putchar_fd('0', 1);
	return (1);
}

char	*ft_uconcat1(char c, char *ptr, const char *a)
{
	char		*p;
	long long	i;
	int			j;

	j = 0;
	i = ft_ustrlen(ptr);
	p = malloc(i + 3);
	p[j++] = c;
	p[j++] = *a;
	while (i--)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

char	*ft_ujoin(char *a, char *b, char c, char d)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = (ft_ustrlen(a) + ft_ustrlen(b) + 2);
	if (*b == '-')
		i = (ft_ustrlen(a) + 1);
	p = malloc(i + 1);
	while (*a && i--)
		p[j++] = *a++;
	if (*b != '-')
	{
		p[j++] = c;
		while (*b && i--)
			p[j++] = *b++;
	}
	p[j++] = d;
	p[j] = '\0';
	return (p);
}

void	ft_1uprintfdd1(const char *ptr, long long *valg, long long *k)
{
	if (*ptr == '-' && !ft_strchr((ptr + 1), '.'))
	{
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(*valg, ptr));
		else
			ft_uputnbr_fd(*valg, 1);
		ft_uchecknum1(ptr, valg, k);
	}
}

int		ft_uprintfdd1(const char *ptr, long long *valg, long long *k)
{
	if (ft_isdigit(ptr) || (*ptr == '.' && ptr[1] != '*') || (*ptr == '-' &&
				ft_strchr((ptr + 1), '.')))
	{
		ft_uchecknum1(ptr, valg, k);
		if (*valg == 0 && ptr[0] != '-' && (ptr[0] == '.' || g_point != 0))
			return (1);
		if (*valg != 0 || (*valg == 0 && ft_strchr(ptr, '.') &&
					ft_uatoi(ptr) > ft_uatoi(ft_strchr(ptr, '.'))) ||
				(*valg == 0 && !ft_strchr(ptr, '.')))
		{
			if (!ft_strchr(ptr, 'u'))
				ft_putstr(ft_uitoa(*valg, ptr));
			else
				ft_uputnbr_fd(*valg, 1);
		}
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	ft_1uprintfdd1(ptr, valg, k);
	return (1);
}
