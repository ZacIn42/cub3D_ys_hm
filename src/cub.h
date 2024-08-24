/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:02:06 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 23:42:15 by hmiyazak         ###   ########.fr       */
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

//functions for parsing the file
void	read_map(char *map, t_field *field, t_parse *parse);
char	*get_next_line(int fd);

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

//functions in utils
int		perror_return_one(char *error_message);
void	free_str_array(char **str_array);

//functions in parse_file
void	parse_file(t_field *field, t_parse *parse, char *filename);
void	read_map(char *map, t_field *field, t_parse *parse);
void	check_valid_map(t_field *field, t_parse *parse);
void	parse_texture(char *map, t_parse *parse);
void	check_texture_north(char *line, t_parse *parse);
void	check_texture_sorth(char *line, t_parse *parse);
void	check_texture_west(char *line, t_parse *parse);
void	check_texture_east(char *line, t_parse *parse);
void	check_texture_ceiling(char *line, t_parse *parse);
void	check_texture_floor(char *line, t_parse *parse);

//functions in utils of parse_file
bool	check_space(t_field *field, t_parse *parse);
bool	check_first_pos(t_field *field, int yi, int xi);
bool	check_wall(t_field *field, t_parse *parse);


#endif
