# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 20:29:51 by yhadari           #+#    #+#              #
#    Updated: 2020/03/13 17:37:55 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube

SRC = ft_draw.c ft_get.c ft_key.c ft_player.c ft_check.c ft_checkline.c \
      ft_revision.c ft_checkmap.c

SRC1 = ft_dr.c ft_get.c ft_check.c ft_checkline.c ft_revision.c ft_checkmap.c \
       ft_key.c ft_derec.c ft_dda.c ft_checkcolor.c ft_keypress.c

SRC2 = ft_dda.c

SRC3 = main.c ft_dda2.c

INC = /usr/include

INCLIB = $(INC)/../lib

all :
	@cc -I /usr/local/include main2.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
	@./a.out

test : 
	@clear
	@gcc -I /usr/local/include $(SRC) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -o $(NAME)
	@./cube

test1 :
	@clear
	@gcc -g -I /usr/local/include $(SRC1) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -o $(NAME)
	@./cube

test2 : 
	@clear
	@gcc -g -I /usr/local/include $(SRC2) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -o $(NAME)
	@./cube

test3 :
	@clear
	@gcc -g -I /usr/local/include $(SRC3) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -o $(NAME)
	@./cube
	

clean :
	@rm -rf $(NAME)

re : clean all

