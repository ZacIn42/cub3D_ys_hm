/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:28:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/01 17:18:49 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub.h"

int	main(void)
{
	t_mlx	mlx;
	t_vec	pos;
	t_vec	w_start;
	t_vec	w_end;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Walls");
	vec_init(&pos, 0, 0);
	vec_init(&w_start, -2, 5);
	vec_init(&w_end, 2, 5);
	if (draw_wall(&mlx, &pos, &w_start, &w_end) == 0)
		write(1, "success\n", 8);
	else
		write(2, "error\n", 6);
	mlx_loop(mlx.mlx);
	return (0);
}
