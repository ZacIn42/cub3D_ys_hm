/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:09:12 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/14 15:51:52 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	key_hook(int key_code, t_cub *cub);

int	set_mlx_hooks(t_cub *cub)
{
	mlx_hook(cub->window, ON_KEYDOWN, 1L << 0, key_hook, cub);
	return (0);
}

static int	key_hook(int key_code, t_cub *cub)
{
	printf("keycode: %d\n", key_code);
	if (is_look_key(key_code))
		look_around(key_code, &cub->field->user);
	else if (key_code == MOVE_FORWARD_KEY || key_code == MOVE_BACK_KEY \
			|| key_code == MOVE_LEFT_KEY || key_code == MOVE_RIGHT_KEY)
		move(key_code, &cub->field->user);
	else if (key_code == ESC_KEY)
		return (close_window_esc(key_code, cub));
	else
		return (1);
	printf("%d\n", cub->field->user.dir);
	printf("%f, %f\n", cub->field->user.pos.x, cub->field->user.pos.y);
	mlx_clear_window(cub->mlx, cub->window);
	draw_wall(cub, cub->field);
	return (0);
}
