/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:02:06 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 19:17:12 by hmiyazak         ###   ########.fr       */
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

# define WIN_HEIGHT (768)
# define WIN_WIDTH (768)

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

//functions in utils
void	put_error_exit(char *error_message);

#endif
