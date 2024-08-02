/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/02 12:00:32 by hmiyazak         ###   ########.fr       */
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
# include <fcntl.h>
# include <errno.h>
# include <sys/time.h>

# define WIN_HEIGHT (2048)
# define WIN_WIDTH (2048)
# define BLOCK_HEIGHT (1024)
# define BLOCK_WIDTH (1024)

typedef struct s_mlx_info {
	void	*mlx;
	void	*window;
	void	*new_img;
}	t_mlx;

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef enum e_direction {
	NORTH,
	EAST,
	SOUTH,
	WEST,
}	t_dir;

typedef struct s_user_info {
	t_vec	pos;
	t_dir	dir;
}	t_user;

typedef struct s_wall_info {
	t_vec	start;
	t_vec	end;
}	t_wall;

typedef struct s_keyhook_props {
	t_mlx	*mlx;
	t_user	*user;
	t_wall	*wall;
}	t_keyprops;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

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
int		draw_wall(t_mlx *mlx, t_user *user, t_vec *w_start, t_vec *w_end);
int		set_mlx_hooks(t_keyprops *keyprops);
int		move(int key_code, t_user *user);
bool	is_look_key(int key_code);
int		look_around(int key_code, t_user *user);
int		close_window_esc(int key_code, t_mlx *mlx);

#endif
