# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 01:03:22 by yhadari           #+#    #+#              #
#    Updated: 2019/10/25 19:09:59 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC) -I. 
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean :
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all
