/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:44:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/01 17:18:21 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define SEP_NUM (1000)

static void		put_vertical_line(t_mlx *mlx, t_vec *pos, t_vec *dest, \
												t_dir direction, int index);
static double	calc_perp_dist(t_vec *pos, t_vec *dest, t_dir direction);

int	draw_wall(t_mlx *mlx, t_vec *pos, t_vec *w_start, t_vec *w_end)
{
	t_vec	target;
	int		index;

	index = 0;
	while (index < SEP_NUM)
	{
		target.x = w_start->x + (w_end->x - w_start->x) * index / SEP_NUM;
		target.y = w_start->y + (w_end->y - w_start->y) * index / SEP_NUM;
		put_vertical_line(mlx, pos, &target, NORTH, index);
		index += 1;
	}
	return (0);
}

static void	put_vertical_line(t_mlx *mlx, t_vec *pos, t_vec *dest, t_dir direction, int index)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = BLOCK_HEIGHT / calc_perp_dist(pos, dest, direction);
	draw_start = -1 * line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	while (draw_start < draw_end)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, WIN_WIDTH / 2 + index, draw_start, 0xFFFFFF);
		draw_start++;
	}
}

static double	calc_perp_dist(t_vec *pos, t_vec *dest, t_dir direction)
{
	if (direction == NORTH || direction == SOUTH)
		return (dest->x - pos->x);
	else
		return (dest->y - pos->y);
}
