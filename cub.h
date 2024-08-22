/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/22 20:59:59 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./mlx_linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <string.h>
# include "./libft/libft.h"

# define WIN_HEIGHT (2048)
# define WIN_WIDTH (2048)
# define MAX_SIZE (1024)
# define SIZE_MAX (1024)
// # define BLOCK_HEIGHT (1024)
// # define BLOCK_WIDTH (1024)

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef enum e_direction {
	EAST = 0,
	SOUTH = 1,
	WEST = 2,
	NORTH = 3,
}	t_dir;

typedef struct s_user {
	t_vec	pos;
	t_dir	dir;
}	t_user;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		b_p_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_parse {
	int	pos_x;
	int	pos_y;
	int	xi;
	int	yi;
	int	top;
	int	height;
	int	width;
	int	texture_flag;
	int	texture_height;
} t_parse;

typedef struct s_field {
	char			**map;
	t_user			user;
	char			texture_paths[4][PATH_MAX];
	t_img			textures[4];
	unsigned int	c_color;
	unsigned int	f_color;
}	t_field;


typedef struct s_cub {
	void	*mlx;
	void	*window;
	t_img	img;
	t_field	*field;
}	t_cub;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	LOOK_LEFT_KEY = 65361,
	LOOK_RIGHT_KEY = 65363,
	MOVE_FORWARD_KEY = 119,
	MOVE_RIGHT_KEY = 100,
	MOVE_BACK_KEY = 115,
	MOVE_LEFT_KEY = 97,
	ESC_KEY = 65307,
};

void	vec_init(t_vec *vec, double x, double y);
void	vec_add(t_vec *ans, t_vec *lhs, t_vec *rhs);
void	vec_sub(t_vec *ans, t_vec *lhs, t_vec *rhs);
int		draw_wall(t_cub *cub, t_field *field);
int		draw_vertical(t_cub *cub, t_user *user, t_vec *spot, int x);
t_vec	*cast_ray_alloc(const t_vec *pos, double theta, char **map);
int		set_mlx_hooks(t_cub *cub);
int		move(int key_code, t_user *user, t_field *field);
bool	is_look_key(int key_code);
int		look_around(int key_code, t_user *user);
int		close_window_esc(int key_code, t_cub *mlx);
void	check_filename(int ac, char *av);
void	read_map(char *map, t_field *field, t_parse *parse);
void	check_map(t_field *field, t_parse *parse);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	check_valid_map(t_field *field, t_parse *parse);
int		count_file_height(int fd);
bool	check_walk(int key_code, t_user *user, t_field *field);
void	parse_texture(char *map, t_parse *parse);
void    check_texture_north(char *line);
void    check_texture_sorth(char *line);
void    check_texture_west(char *line);
void    check_texture_east(char *line);
void	check_texture_floor(char *line);
void	check_texture_ceiling(char *line);
void	check_valid_texture(char *line);


#endif
