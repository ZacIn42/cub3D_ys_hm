/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:09:12 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 19:16:08 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	key_hook(int key_code, t_cub *cub);
static bool	is_look_key(int key_code);
static bool	is_move_key(int key_code);

int	set_mlx_hooks(t_cub *cub)
{
	mlx_hook(cub->window, ON_KEYDOWN, 1L << 0, key_hook, cub);
	mlx_hook(cub->window, ON_DESTROY, 1L << 2, close_window_cross, cub);
	return (0);
}

static bool	is_look_key(int key_code)
{
	return (key_code == LOOK_LEFT_KEY || key_code == LOOK_RIGHT_KEY);
}

static bool	is_move_key(int key_code)
{
	return (key_code == MOVE_FORWARD_KEY || key_code == MOVE_BACK_KEY \
			|| key_code == MOVE_LEFT_KEY || key_code == MOVE_RIGHT_KEY);
}

static int	key_hook(int key_code, t_cub *cub)
{
	if (is_look_key(key_code))
		look_around(key_code, &cub->field->user);
	else if (is_move_key(key_code))
		move(key_code, &cub->field->user);
	else if (key_code == ESC_KEY)
		return (close_window_esc(key_code, cub));
	else
		return (1);
	mlx_clear_window(cub->mlx, cub->window);
	draw_wall(cub, cub->field);
	return (0);
}
