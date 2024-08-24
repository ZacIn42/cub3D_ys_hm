# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:23:35 by hmiyazak          #+#    #+#              #
#    Updated: 2024/08/24 21:42:51 by hmiyazak         ###   ########.fr        #
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

SRCFILES = $(shell find $(SRCDIR) -name '*.c')

OBJFILES = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCFILES)))

all: $(NAME)

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

%.o: %.c $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXOBJFLAGS) -c $(SRCDIR)/$< -o $(OBJDIR)/%.c

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAGS) $(OBJFILES) $(MLXLIB) -o $@

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
