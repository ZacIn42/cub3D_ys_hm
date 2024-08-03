/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:24:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/03 14:41:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	const char	*map[5] = {
		"111111",
		"100101",
		"101001",
		"1100N1",
		"111111",
	};
	t_vec		pos;
	t_vec		*point;

	(void)argc;
	(void)argv;
	vec_init(&pos, 3.5, 2.5);
	point = cast_ray_alloc(&pos, M_PI / 2, &map[0]);
	printf("%f, %f\n", point->x, point->y);
	free(point);
	return (0);
}
