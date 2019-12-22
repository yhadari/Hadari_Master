/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:54:46 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:52:36 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_sflag2(va_list *args, int arr[2], char *valg, int i)
{
	valg = va_arg(*args, char*);
	if (valg == NULL)
		valg = "(null)";
	if (arr[1] > ft_strlen(valg) || arr[1] < 0)
		arr[1] = ft_strlen(valg);
	if (i == -1)
	{
		g_count += write(1, valg, arr[1]);
		while ((arr[0]-- - arr[1]) > 0)
			g_count += write(1, " ", 1);
	}
	if (i == 1)
	{
		while ((arr[0]-- - arr[1]) > 0)
			g_count += write(1, " ", 1);
		g_count += write(1, valg, arr[1]);
	}
}

void	ft_sflagnx(va_list *args, const char *ptr, int (*arr)[2], int *i)
{
	if (ft_isdigit(ptr))
	{
		(*arr)[0] = ft_atoi(ptr);
		ptr += lenum((*arr)[0]) - 1;
	}
	else if (*ptr == '*')
	{
		(*arr)[0] = va_arg(*args, int);
		if ((*arr)[0] < 0 && ((*arr)[0] = -(*arr)[0]))
			*i = -1;
	}
	else if (*ptr == '-')
		*i = -1;
}

int		ft_sflag(const char *ptr, va_list *args)
{
	char	*valg;
	int		arr[2];
	int		i;

	i = 1;
	arr[0] = 0;
	arr[1] = -1;
	valg = NULL;
	while (*ptr != 's')
	{
		ft_sflagnx(args, ptr, &arr, &i);
		if (*ptr == '.')
		{
			arr[1] = 0;
			if (ft_isdigit(++ptr) && (arr[1] = ft_atoi(ptr)))
				ptr += lenum(arr[1]) - 1;
			else if (*ptr == '*')
				arr[1] = va_arg(*args, int);
			break ;
		}
		ptr++;
	}
	ft_sflag2(args, arr, valg, i);
	return (1);
}
