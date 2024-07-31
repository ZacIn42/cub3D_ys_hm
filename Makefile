NAME = cub3D
CC = cc
INCLUDES_DIR = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS =	main.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re