/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:44:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/14 10:35:24 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_wall(t_cub *cub, t_field *field)
{
	double	theta;
	double	view_angle;
	double	theta_step;
	t_vec	*spot;
	int		x;

	view_angle = M_PI * 2 / 3;
	theta = field->user.dir * (M_PI / 2) - view_angle / 2;
	theta_step = view_angle / WIN_WIDTH;
	x = 0;
	while (x < WIN_WIDTH)
	{
		spot = cast_ray_alloc(&field->user.pos, theta, field->map);
		draw_vertical(cub, &field->user, spot, x);
		free(spot);
		theta += theta_step;
		x += 1;
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->img.img, 0, 0);
	return (0);
}

// #define SEP_NUM (500)

// static void		put_vertical_line(t_cub *mlx, t_vec *pos, t_vec *dest, \
// 												t_dir direction, int index);
// static double	calc_perp_dist(t_vec *pos, t_vec *dest, t_dir direction);

// int	draw_wall(t_cub *mlx, t_user *user, t_vec *w_start, t_vec *w_end)
// {
// 	t_vec	target;
// 	int		index;

// 	index = 0;
// 	printf("%p, %p, %p, %p\n", mlx, user, w_start, w_end);
// 	while (index < SEP_NUM)
// 	{
// 		target.x = w_start->x + (w_end->x - w_start->x) * index / SEP_NUM;
// 		target.y = w_start->y + (w_end->y - w_start->y) * index / SEP_NUM;
// 		put_vertical_line(mlx, &user->pos, &target, user->dir, index);
// 		index += 1;
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 1, 1);
// 	return (0);
// }

// static void	put_vertical_line(t_cub *mlx, t_vec *pos, t_vec *dest, t_dir direction, int index)
// {
// 	t_img	img;
// 	int		line_height;
// 	int		draw_start;
// 	int		draw_end;

// 	line_height = WIN_HEIGHT / calc_perp_dist(pos, dest, direction);
// 	draw_start = -1 * line_height / 2 + WIN_HEIGHT / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	draw_end = line_height / 2 + WIN_HEIGHT / 2;
// 	if (draw_end >= WIN_HEIGHT)
// 		draw_end = WIN_HEIGHT - 1;
// 	while (draw_start < draw_end)
// 	{
// 		// mlx_pixel_put(mlx->mlx, mlx->img->img, WIN_WIDTH / 2 + index, draw_start, 0xFFFFFF);
// 		char	*data_addr = mlx_get_data_addr(mlx->img->img, &img.b_p_pixel, &img.line_len, &img.endian);
// 		int pos = (draw_start * img.line_len + (WIN_WIDTH / 2 + index) * (img.b_p_pixel / 8));
// 		*(unsigned int *)(data_addr + pos) = 0xFFFFFF;
// 		draw_start++;
// 	}
// }


