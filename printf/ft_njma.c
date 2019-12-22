/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_njma.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:11:42 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:30:08 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_concat1(char c, char *ptr, const char *a)
{
	char	*p;
	int		i;
	int		j;

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

char	*ft_concat(char c, char *ptr, const char *a, int k)
{
	char	*p;
	int		i;
	int		j;

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
	p[j++] = *a;
	p[j] = '\0';
	return (p);
}

int		ft_1njma(const char *ptr, const char *(*arr)[2], int (*arr1)[3],
		long *valg)
{
	if (ft_isdigit(ptr) && ptr[2] == '*' && ft_strchr(ptr, '.'))
		(*arr)[0] = ".";
	if ((*ptr == '*' && *(ptr + 2) == '*'))
		(*arr1)[1] = *valg;
	if (*ptr == '*' && (*(ptr + 1) == 'd' || *(ptr + 1) == 'i'))
		(*arr)[1] = ft_itoa((*arr1)[0]);
	if ((*ptr == '-' || *ptr == '0' || *ptr == '.' ||
				(*ptr == '*' && *(ptr + 2) != '*') ||
				(ft_isdigit(ptr) && ptr[2] == '*' && ft_strchr(ptr, '.'))) &&
			ptr[1] != 'd' && ptr[1] != 'i')
	{
		if (!(ft_isdigit(ptr) && ptr[2] == '*') &&
				ft_njma1((char*)(*arr)[0], ptr, valg, (*arr1)[0]))
			return (1);
		if (ft_isdigit(ptr) && ptr[2] == '*')
			(*arr1)[2] = 0;
		(*arr)[1] = ft_concat(*ptr, ft_itoa((*arr1)[0]), (*arr)[0], (*arr1)[2]);
		(*arr1)[2] = 1;
	}
	return (0);
}

int		ft_2njma(const char *ptr, const char *(*arr)[2], int (*arr1)[3],
		long *valg)
{
	if (ft_isdigit((*arr)[1]) || *((*arr)[1]) == '.' || (*((*arr)[1]) == '-' &&
				ft_strchr(((*arr)[1] + 1), '.')))
	{
		ft_checknum1((*arr)[1], valg, &(*arr1)[2]);
		if (*valg != 0 || (((*ptr == '*' && *(ptr + 2) != '*') ||
		(*ptr == '*' && *(ptr + 1) == '.' && *(ptr + 2) == '*' && *valg == 0 &&
		(*arr1)[1] < 0 && (*arr1)[0] >= 0) ||
		(*ptr == '0' && *(ptr + 1) == '*' && *(ptr + 2) != '.') ||
		(*ptr == '.' && *(ptr + 1) == '*' && (*arr1)[0] < 0)) && *valg == 0))
			ft_putnbr_fd(*valg, 1);
		if ((*ptr == '0' && *valg == 0 && (*arr1)[0] < 0) || (*ptr == '*' &&
	*(ptr + 1) == '.' && *(ptr + 2) == '*' && *valg == 0 && (*arr1)[1] > 0 &&
	(*arr1)[0] > 0 && (*arr1)[0] > (*arr1)[1]))
			ft_putnbr_fd(*valg, 1);
		while ((*arr1)[2]--)
			ft_putchar_fd(' ', 1);
	}
	if (*((*arr)[1]) == '-' && !ft_strchr(((*arr)[1] + 1), '.'))
	{
		ft_putnbr_fd(*valg, 1);
		ft_checknum1((*arr)[1], valg, &(*arr1)[2]);
	}
	return (1);
}

int		ft_njma(const char *ptr, long *valg, va_list *args)
{
	const char	*arr[2];
	int			arr1[3];

	arr1[1] = 0;
	arr[0] = NULL;
	if (*ptr == '*')
		arr[0] = (ptr + 1);
	if (*(ptr + 1) == '*' && *(ptr + 2) != 'd')
		arr[0] = (ptr + 2);
	arr1[0] = *valg;
	arr1[2] = 1;
	*valg = va_arg(*args, int);
	if (ft_1njma(ptr, &arr, &arr1, valg))
		return (1);
	if ((*ptr == '*' && *(ptr + 1) == '.' && *(ptr + 2) == '*'))
	{
		arr[1] = ft_join(ft_itoa(arr1[0]), ft_itoa((int)arr1[1]), *(ptr + 1));
		*valg = va_arg(*args, int);
	}
	return (ft_2njma(ptr, &arr, &arr1, valg));
}
