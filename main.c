/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:28:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/02 12:07:42 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub.h"

int	main(void)
{
	t_mlx		mlx;
	t_user		user;
	t_wall		wall;
	t_keyprops	keyprops;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Walls");
	mlx.new_img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	vec_init(&user.pos, 0, 0);
	user.dir = EAST;
	vec_init(&wall.start, -2, 5);
	vec_init(&wall.end, 2, 5);
	keyprops.mlx = &mlx;
	keyprops.user = &user;
	keyprops.wall = &wall;
	set_mlx_hooks(&keyprops);
	draw_wall(&mlx, &user, &(wall.start), &(wall.end));
	mlx_loop(mlx.mlx);
	return (0);
}
