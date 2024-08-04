# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yususato <yususato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:23:35 by hmiyazak          #+#    #+#              #
#    Updated: 2024/08/03 21:35:08 by yususato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
INCLUDES_DIR = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)
MLXOBJFLAGS = -I/usr/include -Imlx_linux -O3
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS =	ray_cast.c
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
