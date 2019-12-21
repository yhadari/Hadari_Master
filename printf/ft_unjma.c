/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unjma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:44:06 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/21 01:02:18 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uconcat(char c, char *ptr, const char *a, long long k)
{
	char	*p;
	int		i;
	int		j;

	if (k == 0)
		return (ft_uconcat1(c, ptr, a));
	i = 0;
	if (a != NULL)
		i = 1;
	if (*ptr == '-' && c == 0)
		return (0);
	j = 0;
	i += ft_ustrlen(ptr) + 1;
	p = malloc(i + 2);
	p[j++] = c;
	while (*ptr)
		p[j++] = *ptr++;
	if (a == NULL)
		return (p);
	p[j++] = *a;
	p[j++] = a[ft_strlen(a) - 1];
	p[j] = '\0';
	return (p);
}

int		ft_u1njma(const char *ptr, const char *(*arr)[2], long long (*arr1)[3],
		long long *valg)
{
	char *p;

	p = "xX";
	if (ft_isdigit(ptr) && ptr[2] == '*' && ft_strchr(ptr, '.'))
		(*arr)[0] = ".";
	if ((*ptr == '*' && *(ptr + 2) == '*'))
		(*arr1)[1] = *valg;
	if (*ptr == '*' && (ft_strchr(p, *(ptr + 1)) || *(ptr + 1) == 'u'))
		(*arr)[1] = ft_itoa((*arr1)[0]);
	if ((*ptr == '-' || *ptr == '0' || *ptr == '.' ||
				(*ptr == '*' && *(ptr + 2) != '*') ||
				(ft_isdigit(ptr) && ptr[2] == '*' && ft_strchr(ptr, '.'))) &&
			(!ft_strchr(p, ptr[1]) && ptr[1] != 'u'))
	{
		if (!(ft_isdigit(ptr) && ptr[2] == '*') &&
				ft_unjma1((char*)(*arr)[0], ptr, valg, (*arr1)[0]))
			return (1);
		if (ft_isdigit(ptr) && ptr[2] == '*')
			(*arr1)[2] = 0;
		(*arr)[1] = ft_uconcat(*ptr, ft_itoa((*arr1)[0]), (*arr)[0],
				(*arr1)[2]);
		(*arr1)[2] = 1;
	}
	return (0);
}

void	ft_u2njmanext(const char *ptr, long long (*arr1)[3], long long *valg)
{
	if (*valg != 0 || (((*ptr == '*' && *(ptr + 2) != '*') ||
		(*ptr == '*' && *(ptr + 1) == '.' && *(ptr + 2) == '*' && *valg == 0 &&
		(*arr1)[1] < 0 && (*arr1)[0] >= 0) ||
		(*ptr == '0' && *(ptr + 1) == '*' && *(ptr + 2) != '.') ||
		(*ptr == '.' && *(ptr + 1) == '*' && (*arr1)[0] < 0)) && *valg == 0))
	{
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(*valg, ptr));
		else
			ft_uputnbr_fd(*valg, 1);
	}
}

int		ft_u2njma(const char *ptr, const char *(*arr)[2], long long (*arr1)[3],
		long long *valg)
{
	if (ft_isdigit((*arr)[1]) || *((*arr)[1]) == '.' || (*((*arr)[1]) == '-' &&
				ft_strchr(((*arr)[1] + 1), '.')))
	{
		if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
			(*arr)[1] = ft_uconx(*(ptr + ft_xstrlen(ptr)), (*arr)[1]);
		ft_uchecknum1((*arr)[1], valg, &(*arr1)[2]);
		if (*ptr == '*' && *(ptr + 1) == '.' && *(ptr + 2) == '*' &&
				*valg == 0 && (*arr1)[1] >= 0 && (*arr1)[0] >= 0)
			return (1);
		ft_u2njmanext(ptr, arr1, valg);
		if (*ptr == '0' && *valg == 0 && (*arr1)[0] < 0)
			ft_uputnbr_fd(*valg, 1);
		while ((*arr1)[2]--)
			ft_putchar_fd(' ', 1);
	}
	if (*((*arr)[1]) == '-' && !ft_strchr(((*arr)[1] + 1), '.'))
	{
		(!ft_strchr(ptr, 'u')) ? ft_putstr(ft_uitoa(*valg, ptr))
			: (ft_uputnbr_fd(*valg, 1));
		if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
			(*arr)[1] = ft_uconx(*(ptr + ft_xstrlen(ptr)), (*arr)[1]);
		ft_uchecknum1((*arr)[1], valg, &(*arr1)[2]);
	}
	return (1);
}

int		ft_unjma(const char *ptr, long long *valg, va_list *args)
{
	const char	*arr[2];
	long long	arr1[3];
	char		i;

	i = *(ptr + ft_strlen(ptr) - 1);
	arr1[1] = 0;
	arr[0] = NULL;
	if (*ptr == '*')
		arr[0] = (ptr + 1);
	if (*(ptr + 1) == '*' && *(ptr + 2) != 'u')
		arr[0] = (ptr + 2);
	arr1[0] = *valg;
	arr1[2] = 1;
	*valg = va_arg(*args, int);
	if (ft_u1njma(ptr, &arr, &arr1, valg))
		return (1);
	if ((*ptr == '*' && *(ptr + 2) == '*'))
	{
		arr[1] = ft_ujoin(ft_itoa(arr1[0]), ft_itoa((int)arr1[1]),
				*(ptr + 1), i);
		if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
			arr[1] = ft_uconx(*(ptr + ft_xstrlen(ptr)), arr[1]);
		*valg = va_arg(*args, unsigned int);
	}
	return (ft_u2njma(ptr, &arr, &arr1, valg));
}
