/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:31:19 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/07 11:38:38 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_img	*set_texture(t_field *field, t_vec *spot);
static int		calc_canvas_index(t_img *canvas, int x, int h, int iter);
static int		calc_texture_index(t_img *texture, t_vec *spot, int h, int i);
static double	calc_perp_dist(t_user *user, t_vec *dest);

int	draw_vertical(t_cub *cub, t_user *user, t_vec *spot, int x)
{
	t_img	*canvas;
	t_img	*texture;
	int		h;
	int		iter;

	canvas = &cub->img;
	texture = set_texture(cub->field, spot);
	h = (double)WIN_HEIGHT / 5 / calc_perp_dist(user, spot);
	iter = 0;
	while (iter < h && iter - h / 2 < WIN_HEIGHT / 2)
	{
		canvas->addr[calc_canvas_index(canvas, x, h, iter)] = \
			texture->addr[calc_texture_index(texture, spot, h, iter)];
		canvas->addr[calc_canvas_index(canvas, x, h, iter) + 1] = \
			texture->addr[calc_texture_index(texture, spot, h, iter) + 1];
		canvas->addr[calc_canvas_index(canvas, x, h, iter) + 2] = \
			texture->addr[calc_texture_index(texture, spot, h, iter) + 2];
		canvas->addr[calc_canvas_index(canvas, x, h, iter) + 3] = \
			texture->addr[calc_texture_index(texture, spot, h, iter) + 3];
		iter += 1;
	}
	return (0);
}

static int	calc_canvas_index(t_img *canvas, int x, int h, int iter)
{
	int	y;

	y = canvas->height / 2 - h / 2 + iter;
	if (y < 0)
		y = 0;
	else if (y >= WIN_HEIGHT)
		y = WIN_HEIGHT - 1;
	return (y * canvas->line_len + x * (canvas->bpp / 8));
}

static int	calc_texture_index(t_img *texture, t_vec *spot, int h, int iter)
{
	int	x;
	int	y;

	if (spot->x == (int)spot->x)
		x = texture->width * fabs(spot->y - (int)spot->y);
	else
		x = texture->width * fabs(spot->x - (int)spot->x);
	y = texture->height * iter / h;
	return (y * texture->line_len + x * (texture->bpp / 8));
}

static t_img	*set_texture(t_field *field, t_vec *spot)
{
	t_vec	*pos;

	pos = &field->user.pos;
	if (spot->x == (int)spot->x)
	{
		if (pos->x <= spot->x)
			return (&field->textures[WEST]);
		else
			return (&field->textures[EAST]);
	}
	else
	{
		if (pos->y <= spot->y)
			return (&field->textures[NORTH]);
		else
			return (&field->textures[SOUTH]);
	}
}

static double	calc_perp_dist(t_user *user, t_vec *dest)
{
	if (user->dir == NORTH || user->dir == SOUTH)
		return (fabs(dest->y - user->pos.y));
	else
		return (fabs(dest->x - user->pos.x));
}
