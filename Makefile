# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arive-de <arive-de@student.42.fr>              +#+  +:+       +#+     #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 14:05:46 by arive-de            #+#    #+#            #
#    Updated: 2018/06/01 15:21:19 by arive-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
LIB				= libft/libft.a
LIBMLX			= minilibx_macos/libmlx.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
SRCS			= srcs/main.c \
				  srcs/tools.c \
				  srcs/mandelbrot.c \
				  srcs/julia.c
OBJS			= $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(LIBMLX) $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft $(MLX)
	@echo "\033[35;1m  __                _        _" 
	@echo "\033[35;1m / _|_ __ __ _  ___| |_ ___ | |"
	@echo "\033[35;1m| |_| '__/ _\` |/ __| __/ _ \| |"
	@echo "\033[35;1m|  _| | | (_| | (__| || (_) | |"
	@echo "\033[35;1m|_| |_|  \__,_|\___|\__\___/|_|\033[0m\n\n"
	@echo "FRACTOL COMPILED\t\033[0;32m✓\033[0m"

$(LIBMLX):
	@make -C minilibx_macos
	@echo "MINILIBX COMPILED\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@/bin/rm -rf $(OBJS)
	@echo "OBJECTS REMOVED\t\033[0;32m✓\033[0m"
	@make -C minilibx_macos clean
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIBMLX)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
