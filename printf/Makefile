# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 18:09:05 by yhadari           #+#    #+#              #
#    Updated: 2019/12/16 15:35:07 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_putnbr_fd.c ft_isdigit.c ft_putchar_fd.c ft_itoa.c ft_strlen.c \
	  ft_strdup.c ft_strchr.c ft_printfdd.c ft_zero.c ft_checkptr.c ft_njma.c ft_njma1.c \
	  ft_printf.c ft_mzero.c ft_njma10.c

O = ft_atoi.o ft_putnbr_fd.o ft_isdigit.o ft_putchar_fd.o ft_itoa.o ft_strlen.o \
	ft_strdup.o ft_strchr.o ft_printfdd.o ft_zero.o ft_checkptr.o ft_njma.o ft_njma1.o \
	ft_printf.o ft_mzero.o ft_njma10.o

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

test : re
	@clear
	@gcc -g -Wall -Wextra -Werror ft_printf.c ya.c libftprintf.a
	@./a.out
	@make fclean

test1 : re
	@clear
	@gcc -g -Wall -Wextra -Werror ft_printf.c main.c libftprintf.a
	@./a.out
	@make fclean

test2 : re
	@clear
	@gcc -g -Wall -Wextra -Werror ft_printf.c dib.c libftprintf.a
	@./a.out
	@make fclean

test3 : re
	@clear
	@gcc -g -Wall -Wextra -Werror ft_printf.c jmain.c libftprintf.a
	@./a.out
	@make fclean

