# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:48:45 by gbourson          #+#    #+#              #
#    Updated: 2016/08/17 17:03:59 by gbourson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fdf
LIB			=	./libft/libft.a
LIBMLX		=	./minilibx_macos/libmlx.a
SRC_NAME 	=	main.c

SRC			=	$(addprefix srcs/, $(SRC_NAME))
INCLUDES	=	-I./libft/includes/ -I./includes
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-g -Werror -Wall -Wextra -framework OpenGL -framework Appkit

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(LIBMLX) $(INCLUDES) -o $(NAME)
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
