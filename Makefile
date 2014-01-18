# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 02:31:26 by cfeijoo           #+#    #+#              #
#    Updated: 2014/01/18 14:51:26 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/
LIBFOLDERS = -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS =  -lft -lmlx -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES =	main.c			\
			get_next_line.c	\
			pixel_blend.c	\
			layer.c			\
			raycast.c		\
			load_map.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) :
	$(CC) -c $(CFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(OFILES) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)

updatelibs :
	cd libft/ && git pull
	make -C libft/ re

complibs :
	make -C libft/ re

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
