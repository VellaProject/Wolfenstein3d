# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avella <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 15:23:55 by avella            #+#    #+#              #
#    Updated: 2016/03/15 15:25:57 by avella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

INCLUDES = "libft/includes"

SECONDIN = "includes"

FLAGS = -Wall -Wextra -Werror

MLXFLA = -lmlx -framework OpenGL -framework AppKit

SRC =  src/draw_line.c src/get_next_line.c src/main_give.c src/raycast.c \
	   src/time_event.c src/time_event2.c src/raycast_give.c src/usefull_func.c \
	   src/wolf.c src/my_img.c

SRCS =  draw_line.c get_next_line.c main_give.c raycast.c \
           time_event.c time_event2.c raycast_give.c usefull_func.c \
           wolf.c my_img.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES) -I $(SECONDIN)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLXFLA) $(LIB) -I $(INCLUDES) -I $(SECONDIN)
	mv $(OBJS) src/

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all
