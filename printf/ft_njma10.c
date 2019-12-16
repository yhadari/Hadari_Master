/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_njma10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:53:28 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 15:08:59 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_concat2(char c, char *ptr)
{
	char *p;
	int i;
	int j;

	j = 0;
	i = ft_strlen(ft_itoa(ft_atoi(ptr))) + 1;
	p = malloc(i + 1);
	p[j++] = c;
	while (*ptr)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

int		ft_njma10(const char *ptr, long *valg, va_list *args)
{
	const char *c;
	int z;
	int k;

	k = 1;
	z = *valg;
	*valg = va_arg(*args, int);
	if (*ptr != '0')
	{
		if (z >= 0)
			c = ft_join(ft_itoa(ft_atoi(ptr)), ft_itoa(z), '.');
		else
			c = ft_itoa(ft_atoi(ptr));
	}
	if (*ptr == '0')
	{
		if (z >= 0)
		{
			c = ft_concat2('0', ft_itoa(ft_atoi(ptr)));
			c = ft_join((char*)c, ft_itoa(z), '.');
		}
		else
			c = ft_concat2('0', ft_itoa(ft_atoi(ptr)));
	}
	if (ft_isdigit(c) || *c == '.' || (*c == '-' && checkpoint(c + 1)))
	{
		ft_checknum1(c, valg, &k);
		if ((*valg == 0 && z >= 0 && (ptr[2] == '.' || (ptr[2] == '*' && ptr[0] != '*'))))
			return (1);
		ft_putnbr_fd(*valg, 1);
		while (k--)
			ft_putchar_fd(' ', 1);
	}
	if (*c == '-' && !checkpoint(c + 1))
	{
		ft_putnbr_fd(*valg, 1);
		ft_checknum1(c, valg, &k);
	}
	return (1);
}
