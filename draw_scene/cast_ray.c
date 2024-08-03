/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:46:06 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/03 14:42:47 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_next_border(t_vec *pos, double theta, int *x, int *y);
static bool	is_block(const char **map, int x, int y);

t_vec	*cast_ray_alloc(const t_vec *pos, double theta, const char **map)
{
	t_vec	*current_ray;
	int		next_x;
	int		next_y;

	current_ray = (t_vec *)malloc(sizeof(t_vec));
	if (current_ray == NULL)
		exit(1);
	vec_init(current_ray, pos->x, pos->y);
	next_x = (int)(pos->x);
	next_y = (int)(pos->y);
	while (true)
	{
		set_next_border(current_ray, theta, &next_x, &next_y);
		if (is_block(map, next_x, next_y))
			break ;
	}
	return (current_ray);
}

static void	set_next_border(t_vec *current_ray, double theta, int *x, int *y)
{
	if (((*x) + 1 - current_ray->x) * tan(theta) < ((*y) + 1 - current_ray->y))
	{
		*x += 1;
		printf("tan %f\n", tan(M_PI));
		current_ray->y += (*x - current_ray->x) * tan(theta);
		current_ray->x = *x;
	}
	else
	{
		*y += 1;
		current_ray->x += (*y - current_ray->y) / tan(theta);
		current_ray->y = *y;
	}
}

static bool	is_block(const char **map, int x, int y)
{
	return (map[y][x] == '1');
}
