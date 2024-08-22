# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 19:23:35 by hmiyazak          #+#    #+#              #
#    Updated: 2024/08/23 08:51:48 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
MLXOBJFLAGS = -I/usr/include -Imlx_linux -O3
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCDIR = src
OBJDIR = objects
BINDIR = bin
LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a
TARGET = $(BINDIR)/$(NAME)

SRCFILES = $(wildcard $(SRCDIR)/*.c)

OBJFILES = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o)

$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJFILES) $(BINDIR)
	$(CC) $(CFLAGS) $(OBJFILES) ./mlx_linux/libmlx_Linux.a -o $@

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(BINDIR)

re: fclean all

.PHONY: all clean fclean re
