/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:46:33 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/31 10:58:49 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	paint_ceiling(t_img *canvas, unsigned int c_color, int *index);
static void	paint_floor(t_img *canvas, unsigned int f_color, int *index);
static int	calc_border(t_img *canvas);
static int	calc_canvas_end(t_img *canvas);

int	refresh_image(t_img *canvas, unsigned int c_color, unsigned int f_color)
{
	int	canvas_index;

	canvas_index = 0;
	paint_ceiling(canvas, c_color, &canvas_index);
	paint_floor(canvas, f_color, &canvas_index);
	return (0);
}

static void	paint_ceiling(t_img *canvas, unsigned int c_color, int *index)
{
	int	border_index;

	border_index = calc_border(canvas);
	while (*index < border_index)
	{
		*(unsigned int *)(canvas->addr + *index) = c_color;
		*index += (canvas->bpp / 8);
	}
}

static void	paint_floor(t_img *canvas, unsigned int f_color, int *index)
{
	int	canvas_end;

	canvas_end = calc_canvas_end(canvas);
	while (*index < canvas_end)
	{
		*(unsigned int *)(canvas->addr + *index) = f_color;
		*index += (canvas->bpp / 8);
	}
}

static int	calc_border(t_img *canvas)
{
	int	x;
	int	y;

	x = canvas->width;
	y = canvas->height / 2;
	return (y * canvas->line_len + x * (canvas->bpp / 8));
}

static int	calc_canvas_end(t_img *canvas)
{
	int	x;
	int	y;

	x = canvas->width;
	y = canvas->height;
	return (y * canvas->line_len + x * (canvas->bpp / 8));
}
