/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:09:12 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/02 10:32:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	key_hook(int key_code, t_keyprops *keyprops);

int	set_mlx_hooks(t_mlx *mlx, t_user *user)
{
	t_keyprops	keyprops;

	keyprops.mlx = mlx;
	keyprops.user = user;
	mlx_hook(mlx->window, ON_KEYDOWN, 1L << 0, key_hook, &keyprops);
	return (0);
}

static int	key_hook(int key_code, t_keyprops *keyprops)
{
	printf("keycode: %d\n", key_code);
	if (is_look_key(key_code))
		return (look_around(key_code, keyprops->user));
	else if (key_code == MOVE_FORWARD_KEY || key_code == MOVE_BACK_KEY \
			|| key_code == MOVE_LEFT_KEY || key_code == MOVE_RIGHT_KEY)
		return (move(key_code, keyprops->user));
	else if (key_code == ESC_KEY)
		return (close_window_esc(key_code, keyprops->mlx));
	else
		return (1);
}
