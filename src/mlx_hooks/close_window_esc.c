/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_esc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:54:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/30 10:22:50 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_window_esc(int key_code, t_cub *cub)
{
	if (key_code == ESC_KEY)
	{
		free_str_array(cub->field->map);
		destroy_textures(cub->mlx, cub->field);
		mlx_destroy_image(cub->mlx, cub->img.img);
		mlx_destroy_window(cub->mlx, cub->window);
		exit(0);
	}
	else
		return (1);
}
