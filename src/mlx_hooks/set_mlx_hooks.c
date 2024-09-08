/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:09:12 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/07 11:22:22 by hmiyazak         ###   ########.fr       */
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
	t_field	*field;
	t_user	*user;

	if (cub == NULL)
		return (1);
	field = cub->field;
	user = &field->user;
	if (is_look_key(key_code))
		look_around(key_code, user);
	else if (is_move_key(key_code) && check_walk(key_code, user, field))
		move(key_code, user);
	else if (key_code == ESC_KEY)
		return (close_window_esc(key_code, cub));
	else
		return (1);
	if (draw_scene(cub, cub->field) != 0)
	{
		free_str_array(cub->field->map);
		destroy_textures(cub->mlx, cub->field);
		mlx_destroy_image(cub->mlx, cub->img.img);
		mlx_destroy_window(cub->mlx, cub->window);
		exit(1);
	}
	return (0);
}
