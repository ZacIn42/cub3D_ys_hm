# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:23:35 by hmiyazak          #+#    #+#              #
#    Updated: 2024/08/02 10:05:11 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
INCLUDES_DIR = ./includes
CFLAGS = -Wall -Wextra -Werror -I.
MLXOBJFLAGS = -I/usr/include -Imlx_linux -O3
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
DRAW_DIR = ./draw_scene
STRUCT_DIR = ./struct_handlers
HOOKS_DIR = ./mlx_hooks
SRCS =	main.c \
		$(STRUCT_DIR)/vec_handlers.c \
		$(HOOKS_DIR)/look_around.c \
		$(HOOKS_DIR)/move.c \
		$(HOOKS_DIR)/close_window_esc.c \
		$(HOOKS_DIR)/set_mlx_hooks.c \
		$(DRAW_DIR)/draw_wall.c
OBJS = $(SRCS:.c=.o)
# LIBDIR = ./libft
# LIBFT = $(LIBDIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS)	$(MLXOBJFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) ./mlx_linux/libmlx_Linux.a -o $@

# $(LIBFT):
# 	$(MAKE) -C $(LIBDIR)

clean:
# $(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
# $(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
