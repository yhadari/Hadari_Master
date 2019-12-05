/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:25:56 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/05 22:01:25 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *ptr, ...)
{
	va_list		args;
	int			i;

	i = 0;
	count = 0;
	va_start(args, ptr);
	while (ptr[i] != '\0')
	{
		while (ptr[i] != '%')
		{
			if (ptr[i] == '\0')
				return (count);
			ft_putchar_fd(ptr[i], 1);
			i++;
		}
		zero = 0;
		ft_checkptr(ptr + i + 1, &i, &args);
		i++;
	}
	va_end(args);
	return (count);
}
/*
   int main()
   {
   int i;
   int j;

   i = ft_printf("%dssine", 6);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = printf("%dssine", 6);
   printf("%s", "XX\n");
   printf("j is %d\n", j);
   printf("---------------------------------------------------\n");
   i = ft_printf("11 %15dXX%10d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = printf("11 %15dXX%10d", 128, 9);
   printf("%s", "XX\n");
   printf("j is %d\n", j);
   printf("---------------------------------------------------\n");
   i = ft_printf("22 %5dXX%5d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("22 %5dXX%5d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   rintf("------------------------------------------------------\n");
   i = ft_printf("33 %015dXX%15d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("33 %015dXX%15d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   printf("------------------------------------------------------\n");
   i = ft_printf("44 %05dXX%015d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("44 %05dXX%015d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   printf("------------------------------------------------------\n");
   i = ft_printf("55 %.15dXX%.3d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("55 %.15dXX%.3d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   printf("------------------------------------------------------\n");
   i = ft_printf("66 %.5dXX%.00d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("66 %.5dXX%.00d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   printf("------------------------------------------------------\n");
   i = ft_printf("77 %-15dXX%-6d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("77 %-15dXX%-6d", 128, 9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   printf("------------------------------------------------------\n");
   i = ft_printf("88 %15dXX%4d", -128, -9);
   printf("%s", "XX\n");
   printf("i is %d\n", i);
   j = ft_printf("88 %15dXX%4d", -128, -9);
   printf("%s", "XX\n");
   printf("i is %d\n", j);
   printf("------------------------------------------------------\n");
   i = ft_printf("99 %5dXX%15d", -128, -9);
   printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("99 %5dXX%15d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("11 %015dXX%0003d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("11 %015dXX%0003d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("22 %05dXX%00d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("22 %05dXX%00d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("33 %.15dXX%.16d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("33 %.15dXX%.16d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("44 %.5dXX%.06d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("44 %.5dXX%.06d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("66 %-1dXX%-11d%000000.5d", -128, -9, 333);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("66 %-1dXX%-11d%000000.5d", -128, -9, 333);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("77 %.015dXX%.16d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("77 %.015dXX%.16d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("88 %.0000007dXX%.11d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("88 %.0000007dXX%.11d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
printf("------------------------------------------------------\n");
i = ft_printf("99 %0.10dXX%000000.4d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", i);
j = ft_printf("99 %0.10dXX%000000.4d", -128, -9);
printf("%s", "XX\n");
printf("i is %d\n", j);
return (0);
}
*/
