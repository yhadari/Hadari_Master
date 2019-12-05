/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_njma.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:11:42 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/05 22:01:22 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_concat(char c, char *ptr, const char *a)
{
	char *p;
	int i;
	int j;

	i = 0;
	if (a != NULL)
		i = 1;
	if (*ptr == '-' && c == 0)
		return (0);
	j = 0;
	i += ft_strlen(ptr) + 1;
	p = malloc(i + 1);
	p[j++] = c;
	while (*ptr)
		p[j++] = *ptr++;
	if (a == NULL)
		return (p);
	p[j] = *a;
	p[j + 1] = '\0';
	return (p);
}

int		ft_njma(const char *ptr, long *valg, va_list *args)
{
	const char *c;
	int z;
	int k;
	const char *a;

	a = NULL;
	if (*ptr == '*')
		a = (ptr + 1);
	if (*(ptr + 1) == '*')
		a = (ptr + 2);
	z = *valg;
	k = 1;
	*valg = va_arg(*args, int);
	if (*ptr == '-' || *ptr == '0' || *ptr == '.')
		c = ft_concat(*ptr, ft_itoa(z), a);
	if (ft_isdigit(c) || *c == '.' || (*c == '-' && checkpoint(c + 1)))
	{
		ft_checknum1(c, valg, &k);
		if (zero != 0)
			return (1);
		ft_putnbr_fd(*valg, 1);
		if (k != 0)
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
