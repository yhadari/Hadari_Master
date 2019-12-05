/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:26:34 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/05 21:57:10 by yhadari          ###   ########.fr       */
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
char    *ft_concat(char c, char *ptr, const char *a);
char    *ft_join(char *c, const char *ptr);

#endif
