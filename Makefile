# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:23:35 by hmiyazak          #+#    #+#              #
#    Updated: 2024/08/03 19:17:11 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
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
		$(DRAW_DIR)/draw_wall.c \
		$(DRAW_DIR)/draw_vertical.c \
		$(DRAW_DIR)/cast_ray.c \
		utils.c \
		parse_file/parse_map.c \
		parse_file/parse_valid_map.c \
		parse_file/parse_arg.c \
		parse_file/get_next_line.c \
		parse_file/parse_check_height.c \

OBJS = $(SRCS:.c=.o)
TEST_SRCS = $(filter-out main.c, $(SRCS))
TEST_SRCS += test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
# LIBDIR = ./libft
# LIBFT = $(LIBDIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS)	$(MLXOBJFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) ./mlx_linux/libmlx_Linux.a -o $@

test: $(TEST_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(TEST_OBJS) ./mlx_linux/libmlx_Linux.a -o test

# $(LIBFT):
# 	$(MAKE) -C $(LIBDIR)

clean:
# $(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
# $(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)
	$(RM) test

re: fclean all

.PHONY: all clean fclean re
