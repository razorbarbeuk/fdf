# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:48:45 by gbourson          #+#    #+#              #
#    Updated: 2016/08/18 19:37:52 by RAZOR            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fdf
LIB			=	./libft/libft.a
SRC_NAME 	=	main.c \
				list_utils.c \
				err.c

SRC			=	$(addprefix srcs/, $(SRC_NAME))
INCLUDES	=	-I./libft/includes/ -I./includes
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-g -Werror -Wall -Wextra

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME) -L/usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit
	# @gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "Tu as compilé"

clean :
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "Tu as clean!"

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "C'est encore plus propre..."

re : 	fclean all

.PHONY: all, clean, fclean, re
