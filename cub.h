/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/01 17:17:59 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./mlx_linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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

}	t_mlx;

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef enum e_direction {
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_dir;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	vec_init(t_vec *vec, double x, double y);
void	vec_add(t_vec *ans, t_vec *lhs, t_vec *rhs);
void	vec_sub(t_vec *ans, t_vec *lhs, t_vec *rhs);
int		draw_wall(t_mlx *mlx, t_vec *pos, t_vec *w_start, t_vec *w_end);

#endif
