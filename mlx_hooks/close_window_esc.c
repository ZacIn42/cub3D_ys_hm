/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_esc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:54:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/02 10:45:56 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_window_esc(int key_code, t_mlx *mlx)
{
	(void)mlx;
	if (key_code == ESC_KEY)
	{
		// mlx_destroy_image(mlx->mlx, mlx->new_img);
		// mlx_destroy_window(mlx->mlx, mlx->window);
		exit(0);
	}
	else
		return (1);
}
