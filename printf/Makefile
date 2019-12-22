# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 18:09:05 by yhadari           #+#    #+#              #
#    Updated: 2019/12/22 04:35:09 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_putnbr_fd.c ft_isdigit.c ft_putchar_fd.c ft_itoa.c ft_strlen.c \
	  ft_strdup.c ft_strchr.c ft_printfdd.c ft_zero.c ft_checkptr.c ft_njma.c ft_njma1.c \
	  ft_printf.c ft_mzero.c ft_njma10.c ft_printfdd1.c ft_njma3.c ft_uitoa.c ft_unjma.c \
	  ft_unjma3.c ft_uputnbr_fd.c ft_uzero.c ft_uatoi.c ft_unjma1.c ft_uprintfdd.c \
	  ft_ustrdup.c ft_umzero.c ft_unjma10.c ft_uprintfdd1.c ft_ustrlen.c ft_xflag.c \
	  ft_putstr.c ft_xstrlen.c ft_cflag.c ft_cisdigit.c ft_cstrchr.c ft_pourcentage.c \
	  ft_pflag.c ft_sflag.c

O = ft_atoi.o ft_putnbr_fd.o ft_isdigit.o ft_putchar_fd.o ft_itoa.o ft_strlen.o \
	ft_strdup.o ft_strchr.o ft_printfdd.o ft_zero.o ft_checkptr.o ft_njma.o ft_njma1.o \
	ft_printf.o ft_mzero.o ft_njma10.o ft_printfdd1.o ft_njma3.o ft_uitoa.o ft_unjma.o \
	ft_unjma3.o ft_uputnbr_fd.o ft_uzero.o ft_uatoi.o ft_unjma1.o ft_uprintfdd.o \
	ft_ustrdup.o ft_umzero.o ft_unjma10.o ft_uprintfdd1.o ft_ustrlen.o ft_xflag.o \
	ft_putstr.o ft_xstrlen.o ft_cflag.o ft_cisdigit.o ft_cstrchr.o ft_pourcentage.o \
	ft_pflag.o ft_sflag.o

all : $(NAME)

$(NAME) :
	@gcc -g -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

clean : 
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all
