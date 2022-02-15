# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:48:16 by wmonacho          #+#    #+#              #
#    Updated: 2022/02/15 18:01:34 by wmonacho         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME =		FDF

CFLAGS =	-Wall -Wextra -Werror -g3 -fsanitize=address

CC =		gcc

MAKE =		make

LIBSDIR =	libft/

OBJ =	$(FILES:.c=.o)

FILES = ft_fdf.c		\

all: libs $(NAME)

libs:
	$(MAKE) -C $(LIBSDIR)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)