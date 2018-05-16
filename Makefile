# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arive-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 16:10:03 by arive-de          #+#    #+#              #
#    Updated: 2018/04/16 13:57:49 by arive-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol

SRC= ./srcs/main.c \
	 ./srcs/mandelbrot.c \
	 ./srcs/tools.c \
	 ./srcs/julia.c

OBJ= $(subst .c,.o, $(SRC))

CC= gcc
CFLAGS= -Wall -Wextra -Werror
MLX= -lmlx -framework OpenGL -framework Appkit

LIBFT= ./libft/libft.a
LIBINC= -I libft/

FILH= includes/fractol.h
INCDIR= -I includes/

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(FILH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(INCDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

$(LIBFT):
	make -C libft

clean:
	/bin/rm -rf $(OBJ) $(OBJ2)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf ./libft/libft.a

re: fclean all
