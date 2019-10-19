# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 01:03:22 by yhadari           #+#    #+#              #
#    Updated: 2019/10/19 16:12:29 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = *.c

all :
	@gcc -Wall -Wextra -Werror -c $(NAME) -I. 
	@ar rc libft.a *.o
	@ranlib libft.a

bonus : all

clean :
	@rm -f *.o

fclean : clean
	@rm -f *.a

re : fclean all
