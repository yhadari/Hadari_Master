/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:26:34 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:46:31 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int			g_count;
int			g_point;
int			ft_printf(const char *ptr, ...);
void		ft_checknum1(const char *ptr, long *valg, int *k);
void		ft_putnbr_fd(long n, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(const char *c);
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
int			ft_pointzero(const char *ptr, long *valg, const char *str, int *nb);
int			ft_point(const char *ptr, long *valg, int *n, int **k);
char		*ft_strchr(const char *s, int c);
int			ft_checkptr(const char *ptr, int *i, va_list *args);
int			ft_printfdd(const char *ptr, va_list *args);
int			ft_zero(long *valg, int *n, int *i, int *nb);
int			ft_njma(const char *ptr, long *valg, va_list *args);
char		*ft_concat(char c, char *ptr, const char *a, int k);
int			ft_njma1(char *a, const char *ptr, long *valg, int z);
int			ft_njma2(const char *ptr, long *valg, int z);
int			ft_njma3(char *a, const char *ptr, int z, long *valg);
char		*ft_concat1(char c, char *ptr, const char *a);
int			ft_mzero(const char *ptr, long *valg, va_list *args, int *k);
char		*ft_con(char a, char *ptr);
char		*ft_join(char *a, char *b, char c);
char		*ft_concat2(char c, char *ptr);
int			ft_njma10(const char *ptr, long *valg, va_list *args);
void		ft_point1(long *valg, int *nb, int *i, int *n);
int			ft_printfdd1(const char *ptr, long *valg, int *k);
int			ft_n1(char *a, int *z, long *valg, int *i);
int			ft_n2(char *a, int *z, long *valg, int *j);
int			ft_n3(char *a, long *valg, int *j);
void		ft_mzero1(char **p, const char *ptr, int *i, int *j);
int			ft_mzero2(char **p, long *num, int *k);
void		ft_njma11(const char *ptr, const char **c, int *z);
int			ft_1njma(const char *ptr, const char *(*arr)[2], int (*arr1)[3],
			long *valg);
int			ft_2njma(const char *ptr, const char *(*arr)[2], int (*arr1)[3],
			long *valg);
void		ft_uchecknum1(const char *ptr, long long *valg, long long *k);
int			ft_upointzero(const char *str, long long *nb);
void		ft_upoint1(long long *valg, long long nb, long long *n);
int			ft_upoint(const char *ptr, long long *valg, long long *n,
			long long **k);
int			ft_uprintfdd(const char *ptr, va_list *args);
int			ft_uprintfdd1(const char *ptr, long long *valg, long long *k);
long long	ft_uatoi(const char *str);
int			ft_u1njma(const char *ptr, const char *(*arr)[2],
			long long (*arr1)[3], long long *valg);
int			ft_u2njma(const char *ptr, const char *(*arr)[2],
			long long (*arr1)[3], long long *valg);
int			ft_unjma(const char *ptr, long long *valg, va_list *args);
int			ft_unjma3(char *a, const char *ptr, long long z, long long *valg);
int			ft_un1(const char *arr[2], long long *z, long long *valg,
			long long *i);
int			ft_un2(const char *arr[2], long long *z, long long *valg,
			long long *j);
int			ft_pourcentage(const char *ptr, va_list *args);
int			ft_un3(const char *arr[2], long long *valg, long long *j);
void		ft_uputnbr_fd(unsigned int n, int fd);
int			ft_uzero(long long *valg, long long *n, long long arr[2],
			const char *ptr);
int			ft_unjma1(char *a, const char *ptr, long long *valg, long long z);
int			ft_unjma2(const char *ptr, long long *valg, long long z);
char		*ft_ustrdup(const char *s1);
int			ft_umzero(const char *ptr, long long *valg, va_list *args,
			long long *k);
void		ft_umzero1(char **p, const char *ptr, long long *i, long long *j);
int			ft_umzero2(char **p, long long *num, long long *k, const char *ptr);
int			ft_unjma10(const char *ptr, long long *valg, va_list *args);
void		ft_unjma11(const char *ptr, const char **c, long long *z);
int			ft_1unjma1(const char *ptr, long long *valg, long long z);
void		ft_1uprintfdd1(const char *ptr, long long *valg, long long *k);
char		*ft_uconcat2(char c, char *ptr);
char		*ft_uconcat(char c, char *ptr, const char *a, long long k);
char		*ft_uconcat1(char c, char *ptr, const char *a);
char		*ft_ucon(char a, char *ptr);
char		*ft_ujoin(char *a, char *b, char c, char d);
long long	ft_ustrlen(const char *s);
char		*ft_strev(char *ptr);
char		*ft_xflag(size_t n, int k);
char		*ft_uitoa(unsigned int n, const char *a);
void		ft_putstr(char *c);
char		*ft_uconx(char a, const char *ptr);
int			ft_xstrlen(const char *s);
int			ft_cisdigit(const char *c);
int			ft_cflag(const char *ptr, va_list *args);
char		*ft_cstrchr(const char *s, int c);
int			ft_cflag1(const char *ptr, va_list *args, char valg, int valg1);
int			ft_check(const char *ptr);
int			ft_writepo(int num, char i);
void		ft_pourcentage1(const char *ptr, char *i, int *num);
void		ft_unjma12(const char *ptr, const char *c, long long *valg,
			long long *k);
void		ft_umzero3(char **p, long long *num, long long *k, const char *ptr);
int			ft_un0(const char *arr[2], long long *j, long long *z);
void		ft_uprintfdd2(const char *ptr, long long valg);
int			ft_2unjma2(const char *ptr, long long *valg, long long z);
void		ft_u2njmanext(const char *ptr, long long (*arr1)[3],
			long long *valg);
int			ft_pflag(const char *ptr, va_list *args);
int			ft_pflag1(const char *ptr, char *p, size_t valg);
int			ft_pflag2(const char *ptr, char *p, size_t valg, int arr[2]);
int			ft_pflag3(const char *ptr, char *p, size_t valg, int arr[2]);
int			ft_sflag(const char *ptr, va_list *args);
int			lenum(int n);
void		ft_sflag2(va_list *args, int arr[2], char *valg, int i);
void		ft_sflagnx(va_list *args, const char *ptr, int (*arr)[2], int *i);
#endif
