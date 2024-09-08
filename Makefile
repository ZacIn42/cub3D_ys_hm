# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:23:35 by hmiyazak          #+#    #+#              #
#    Updated: 2024/08/29 16:03:51 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = objects
LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a
MLXDIR = $(SRCDIR)/mlx_linux
MLXFLAGS = -L/usr/lib -lXext -lX11 -lm -lz
MLXOBJFLAGS = -I/usr/include -O3
MLXLIB = $(MLXDIR)/libmlx_Linux.a
IFLAGS = -I$(SRCDIR) -I$(LIBDIR) -I$(MLXDIR)

RM = rm -rf

SRCS = $(shell find $(SRCDIR) -type f -name '*.c')
OBJS = $(subst $(SRCDIR),$(OBJDIR),$(SRCS:.c=.o))

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXOBJFLAGS) -c $< -o $@

$(NAME): $(OBJS) | $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAGS) $(OBJS) $(MLXLIB) $(LIBFT) -o $@

clean:
	@$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJDIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
