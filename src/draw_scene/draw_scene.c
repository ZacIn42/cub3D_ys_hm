/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:44:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/03 21:36:04 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_scene(t_cub *cub, t_field *field)
{
	double	theta;
	double	view_angle;
	double	theta_step;
	t_vec	*spot;
	int		x;

	if (refresh_image(&cub->img, field->c_color, field->f_color) != 0)
		return (1);
	view_angle = M_PI * 2 / 3;
	theta = field->user.dir * (M_PI / 2) - view_angle / 2;
	theta_step = view_angle / WIN_WIDTH;
	x = 0;
	while (x < WIN_WIDTH)
	{
		spot = cast_ray(&field->user.pos, theta, field->map);
		if (spot == NULL)
			return (1);
		if (draw_vertical(cub, &field->user, spot, x) != 0)
			return (free(spot), 1);
		free(spot);
		theta += theta_step;
		x += 1;
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->img.img, 0, 0);
	return (0);
}
