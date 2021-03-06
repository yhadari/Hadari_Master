/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unjma10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:38:40 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/20 23:03:16 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uconcat2(char c, char *ptr)
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	i = ft_ustrlen(ft_itoa(ft_uatoi(ptr))) + 1;
	p = malloc(i + 1);
	p[j++] = c;
	while (*ptr)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

void	ft_unjma11(const char *ptr, const char **c, long long *z)
{
	if (*ptr != '0')
	{
		if (*z >= 0)
			*c = ft_ujoin(ft_itoa(ft_uatoi(ptr)), ft_itoa(*z), '.',
					*(ptr + ft_strlen(ptr) - 1));
		else
			*c = ft_itoa(ft_uatoi(ptr));
	}
	if (*ptr == '0')
	{
		if (*z >= 0)
		{
			*c = ft_uconcat2('0', ft_itoa(ft_uatoi(ptr)));
			*c = ft_ujoin((char*)*c, ft_itoa(*z), '.',
					*(ptr + ft_strlen(ptr) - 1));
			if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
				*c = ft_uconx(*(ptr + ft_xstrlen(ptr)), *c);
		}
		else
			*c = ft_uconcat2('0', ft_itoa(ft_uatoi(ptr)));
	}
}

void	ft_unjma12(const char *ptr, const char *c, long long *valg,
		long long *k)
{
	if (*c == '-' && !ft_strchr((c + 1), '.'))
	{
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(*valg, ptr));
		else
			ft_uputnbr_fd(*valg, 1);
		ft_uchecknum1(c, valg, k);
	}
}

int		ft_unjma10(const char *ptr, long long *valg, va_list *args)
{
	const char	*c;
	long long	z;
	long long	k;

	k = 1;
	z = *valg;
	*valg = va_arg(*args, unsigned int);
	ft_unjma11(ptr, &c, &z);
	if (ft_isdigit(c) || *c == '.' || (*c == '-' && ft_strchr((c + 1), '.')))
	{
		c = ft_uconx(*(ptr + ft_strlen(ptr) - 1), c);
		ft_uchecknum1(c, valg, &k);
		if ((*valg == 0 && z >= 0 && (ptr[2] == '.' ||
						(ptr[2] == '*' && ptr[0] != '*'))))
			return (1);
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(*valg, ptr));
		else
			ft_uputnbr_fd(*valg, 1);
		while (k--)
			ft_putchar_fd(' ', 1);
	}
	ft_unjma12(ptr, c, valg, &k);
	return (1);
}
