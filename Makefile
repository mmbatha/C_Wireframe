# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 11:59:06 by mmbatha           #+#    #+#              #
#    Updated: 2018/07/30 16:46:57 by mmbatha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = fdf.h

SRC = main.c error.c matrices.c init_matrices.c draw.c parse_map.c keyhook.c helpers.c mousehook.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

HEADERFLAGS = $(addprefix -I , $(HEADER))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -g

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
