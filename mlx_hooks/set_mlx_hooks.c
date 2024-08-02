/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:09:12 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/02 12:11:09 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	key_hook(int key_code, t_keyprops *keyprops);

int	set_mlx_hooks(t_keyprops *keyprops)
{
	t_mlx	*mlx;

	mlx = keyprops->mlx;
	mlx_hook(mlx->window, ON_KEYDOWN, 1L << 0, key_hook, keyprops);
	return (0);
}

static int	key_hook(int key_code, t_keyprops *keyprops)
{
	t_mlx	*mlx;
	t_user	*user;
	t_wall	*wall;

	mlx = keyprops->mlx;
	user = keyprops->user;
	wall = keyprops->wall;
	printf("keycode: %d\n", key_code);
	if (is_look_key(key_code))
		look_around(key_code, user);
	else if (key_code == MOVE_FORWARD_KEY || key_code == MOVE_BACK_KEY \
			|| key_code == MOVE_LEFT_KEY || key_code == MOVE_RIGHT_KEY)
		move(key_code, user);
	else if (key_code == ESC_KEY)
		return (close_window_esc(key_code, mlx));
	else
		return (1);
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->new_img);
	mlx->new_img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	draw_wall(mlx, user, &(wall->start), &(wall->end));
	return (0);
}
