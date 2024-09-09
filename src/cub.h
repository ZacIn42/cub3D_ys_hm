/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:02:06 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/09 15:09:22 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include "libft.h"
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
# include <stdint.h>

# define WIN_HEIGHT (768)
# define WIN_WIDTH (768)
# define MAX_SIZE (1024)
# define FUDGE_FACTOR (0.0001)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (20)
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
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

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

typedef struct s_parse {
	int		pos_x;
	int		pos_y;
	int		xi;
	int		yi;
	int		top;
	int		height;
	int		width;
	int		texture_flag;
	int		texture_height;
	bool	north_flag;
	bool	sorth_flag;
	bool	west_flag;
	bool	east_flag;
	bool	ceiling_flag;
	bool	floor_flag;
	bool	gnl_flag;
}	t_parse;

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

//functions for draw_scene
int		draw_scene(t_cub *cub, t_field *field);
t_vec	*cast_ray(const t_vec *pos, double theta, char **map);
int		draw_vertical(t_cub *cub, t_user *user, t_vec *spot, int x);
int		refresh_image(t_img *canvas, unsigned int c, unsigned int f);

//functions for hooks
int		set_mlx_hooks(t_cub *cub);
int		close_window_cross(t_cub *cub);
int		close_window_esc(int key_code, t_cub *cub);
int		look_around(int key_code, t_user *user);
int		move(int key_code, t_user *user);
//fook error handling
bool	check_walk(int key_code, t_user *user, t_field *field);

//functions to handle struct vec
void	vec_init(t_vec *vec, double x, double y);
void	vec_add(t_vec *ans, t_vec *lhs, t_vec *rhs);
void	vec_sub(t_vec *ans, t_vec *lhs, t_vec *rhs);

//functions to handle texture images
int		init_textures(void *mlx, t_field *fld);
void	destroy_textures(void *mlx, t_field *field);

//functions in utils
int		perror_return_one(char *error_message);
void	free_str_array(char **str_array);

//functions in parse_file
//functions in parse_texture
int		parse_texture(t_field *field, char *map, t_parse *parse);
int		check_texture_north(t_field *field, char *line, t_parse *parse);
int		check_texture_sorth(t_field *field, char *line, t_parse *parse);
int		check_texture_west(t_field *field, char *line, t_parse *parse);
int		check_texture_east(t_field *field, char *line, t_parse *parse);
int		check_texture_ceiling(t_field *field, char *line, t_parse *parse);
int		check_texture_floor(t_field *field, char *line, t_parse *parse);
int		check_valid_texture_map(char **new_line, t_parse *parse, int fd);

//functions in parse_map
int		parse_file(t_cub *cub, char *filename);
int		read_map(char *map, t_field *field, t_parse *parse);
int		check_valid_map(t_field *field, t_parse *parse);

//functions in utils of parse_file
bool	check_space(t_field *field, t_parse *parse);
bool	check_first_pos(t_field *field, int yi, int xi);
bool	check_wall(t_field *field, t_parse *parse);
char	*get_next_line(int fd, bool *gnl_flag);
void	gnl_error(bool *gnl_flag, char *error_message);
int		check_gnl_error(char *line, bool gnl_flag, char *message);
int		check_valid_ft_atoi(char *color_value);
char	*init_error(int number);
int		check_map_size(int height, int width);
void	set_position(t_parse *parse, int *pos_count, int height, int width);

#endif
