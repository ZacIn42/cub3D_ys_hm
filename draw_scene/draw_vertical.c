/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:31:19 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/03 17:37:57 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define PRECISION (0.01f)

static t_img	*set_texture(t_cub *mlx, t_user *user, t_vec *spot);
static double	calc_perp_dist(t_user *user, t_vec *dest);

int	draw_vertical(t_cub *mlx, t_user *user, t_vec *spot, int x)
{
	t_img	*canvas;
	t_img	*texture;
	int		h;
	int		h_iter;

	canvas = mlx->img;
	texture = set_texture(mlx, user, spot);
	h = (double)WIN_HEIGHT / calc_perp_dist(user, spot);
	h_iter = WIN_HEIGHT / 2 - h / 2;
	if (h_iter < 0)
		h_iter = 0;
	while (h_iter < WIN_HEIGHT / 2 + h / 2 && h_iter < WIN_HEIGHT)
	{
		
		h_iter += 1;
	}
	return (0);
}

static t_img	*set_texture(t_cub *mlx, t_user *user, t_vec *spot)
{
	t_vec	*pos;

	pos = user->pos;
	if (spot->x - (double)(int)spot->x < PRECISION)
	{
		if (pos->x <= spot->x)
			return (&mlx->texture.west);
		else
			return (&mlx->texture.east);
	}
	else
	{
		if (pos->y <= spot.y)
			return (&mlx->texture.north);
		else
			return (&mlx->texture.south);
	}
}

static double	calc_perp_dist(t_user *user, t_vec *dest)
{
	if (user->dir == NORTH || dir == SOUTH)
		return (dest->y - pos->y);
	else
		return (dest->x - pos->x);
}
