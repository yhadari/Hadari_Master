/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_njma.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:11:42 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/13 22:46:11 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_concat1(char c, char *ptr, const char *a)
{
	char *p;
	int i;
	int j;

	j = 0;
	i = ft_strlen(ptr);
	p = malloc(i + 3);
	p[j++] = c;
	p[j++] = *a;
	while (i--)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

char    *ft_concat(char c, char *ptr, const char *a, int k)
{
	char *p;
	int i;
	int j;

	if (k == 0)
		return (ft_concat1(c, ptr, a));
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

char    *ft_join(char *a, char *b, char c)
{
	char *p;
	int i;
	int j;

	i = 0;
	j = 0;
	i = (ft_strlen(a) + ft_strlen(b) + 1);
	if (*b == '-')
		i = (ft_strlen(a) + 1);
	p = malloc(i + 1);
	while(*a && i--)
		p[j++] = *a++;
	if (*b != '-')
	{
		p[j++] = c;
		while (*b && i--)
			p[j++] = *b++;
	}
	p[j] = '\0';
	return (p);
}

int		ft_njma(const char *ptr, long *valg, va_list *args)
{
	const char *c;
	int z;
	int z1;
	int k;
	const char *a;

	z1 = 0;
	a = NULL;
	if (*ptr == '*')
		a = (ptr + 1);
	if (*(ptr + 1) == '*' && *(ptr + 2) != 'd')
		a = (ptr + 2);
	z = *valg;
	k = 1;
	*valg = va_arg(*args, int);
	if (ft_isdigit(ptr) && ptr[2] == '*' && ft_strchr(ptr, '.'))
		a = ".";
	if ((*ptr == '*' && *(ptr + 2) == '*'))
		z1 = *valg;
	if (*ptr == '*' && *(ptr + 1) == 'd')
		c = ft_itoa(z);
	if ((*ptr == '-' || *ptr == '0' || *ptr == '.' || (*ptr == '*' && *(ptr + 2) != '*') ||
			(ft_isdigit(ptr) && ptr[2] == '*' && ft_strchr(ptr, '.'))) && ptr[1] != 'd')
	{
		if (!(ft_isdigit(ptr) && ptr[2] == '*') && ft_njma1((char*)a, ptr, valg, z))
			return (1);
		if (ft_isdigit(ptr) && ptr[2] == '*')
			k = 0;
		c = ft_concat(*ptr, ft_itoa(z), a, k);
		k = 1;
	}
	if ((*ptr == '*' && *(ptr + 2) == '*'))
	{
		c = ft_join(ft_itoa(z), ft_itoa((int)z1), *(ptr + 1));
		*valg = va_arg(*args, int);
	}
	if (ft_isdigit(c) || *c == '.' || (*c == '-' && checkpoint(c + 1)))
	{
		ft_checknum1(c, valg, &k);
		if ((*valg == 0 && z >= 0 &&
					(ptr[2] == '.' || (ptr[2] == '*' && ptr[0] != '*') || (ptr[0] == '.' && ptr[1] == '*'))) ||
				(*valg == 0 && z1 >= 0 && (*ptr == '*' && *(ptr + 2) == '*')))
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
