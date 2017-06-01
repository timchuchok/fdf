#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 18:24:57 by vtymchen          #+#    #+#              #
#    Updated: 2017/01/25 19:24:44 by vtymchen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

GCC = gcc -Wall -Wextra -Werror

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC =	main.c \
		draw.c \
		init.c \
		point.c \
		move.c \
		rotation.c

OBJ = $(SRC:.c=.o)

HEADER = fdf.h

.PHONY: all clean fclean libft libx

all: $(NAME)

$(NAME): $(OBJ)	libx libft
		gcc -o $(NAME) -Lminilibx_macos -lmlx -Llibft -lft $(OBJ) $(FRAMEWORKS)

%.o : %.c $(HEADER)	
	$(GCC) -c -o  $@ $<

libft:
		make -C libft/

libx:
		make -C minilibx_macos/

clean:
		rm -f $(OBJ)
		make clean -C libft/
		make clean -C minilibx_macos/

fclean: clean
		make fclean -C libft/
		rm -f $(NAME)

re: fclean all