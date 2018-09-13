# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 07:14:46 by mmbatha           #+#    #+#              #
#    Updated: 2018/07/13 17:56:19 by mmbatha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
CC = gcc -Wall -Werror -Wextra
SRCSFILES	= ft_putendl.c ft_putstr.c ft_memalloc.c ft_strsplit.c \
			  ft_memset.c ft_putchar.c ft_strlen.c ft_putendl_fd.c \
			  ft_strchr.c ft_strdup.c ft_strjoin.c ft_putstr_fd.c \
			  ft_putchar_fd.c get_next_line.c ft_strcat.c ft_strcpy.c \
			  ft_strnew.c ft_strsub.c

SRCS = $(SRCSFILES)
OBJS = $(SRCS:.c=.o)
HEADER = includes/libft.h
HEADERFLAGS = $(addprefix -I , $(HEADER))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(HEADERFLAGS) -c -o $@ $<

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
