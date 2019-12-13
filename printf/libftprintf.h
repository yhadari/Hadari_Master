/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:26:34 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/12 16:37:56 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		count;
int		zero;
int		point;
int		ft_printf(const char *ptr, ...);
int		ft_checknum1(const char *ptr, long *valg, int *k);
void	ft_putnbr_fd(long n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(const char *c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_pointzero(const char *ptr, long *valg, const char *str, int *nb);
int		ft_point(const char *ptr, long *valg, const char *str, int *n, int **k);
char	*ft_strchr(const char *s, int c);
int		checkpoint(const char *p);
int     ft_checkptr(const char *ptr, int *i, va_list *args);
int     ft_printfdd(const char *ptr, va_list *args);
int		ft_zero(long *valg, const char *str, int *n, int *i, int *nb);
int     ft_njma(const char *ptr, long *valg, va_list *args);
char    *ft_concat(char c, char *ptr, const char *a, int k);
int     ft_njma1(char *a, const char *ptr, long *valg, int z);
int     ft_njma2(const char *ptr, long *valg, int z);
int     ft_njma3(char *a, const char *ptr, int z, long *valg);
char    *ft_concat1(char c, char *ptr, const char *a);
#endif
