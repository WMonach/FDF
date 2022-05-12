# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:48:16 by wmonacho          #+#    #+#              #
#    Updated: 2022/05/12 13:30:58 by wmonacho         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME =		fdf

CFLAGS =	-Wall -Wextra -Werror -I .

SFLAGS =	-fsanitize=address -g3

CC =		gcc

LIBSDIR =	../libft/

OBJS_DIR = .objs

OBJ =	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

FILES = main.c									\
		bresenham.c								\
		debug.c									\
		parsing.c								\
		zoom.c									\
		rgb.c									\
		calibration.c							\
		keyhook.c								\
		translation.c							\
		../get_next_line/get_next_line.c		\
		../get_next_line/get_next_line_utils.c	\
		matrix.rotation.c						\

all: libs $(NAME)

libs:
	$(MAKE) -C $(LIBSDIR)

$(NAME): $(OBJ) $(LIBSDIR)libft.a
	$(CC) $(SFLAG) $(OBJ) $(LIBSDIR)libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
$(OBJS_DIR)/%.o:		%.c fdf.h ${LIBSDIR}libft.h ${LIBSDIR}libft.a Makefile
				mkdir -p $(dir $@)
				${CC} ${CFLAGS} -I$(LIBSDIR) -c $< -o $@

clean :
				${MAKE} clean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o 

fclean :
				${MAKE} fclean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o
				rm -f ${NAME}

re :			fclean all

.PHONY:			all clean fclean bonus libs re