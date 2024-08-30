/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:46:06 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/30 09:36:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_next_border(t_vec *current_ray, double theta);
static void	set_next_x_y(t_vec *current_ray, t_vec *next_x_y, double theta);
static bool	is_next_x(t_vec *current_ray, t_vec *next_x_y, double theta);
static bool	is_block(char **map, const t_vec *pos, t_vec *current_ray);

t_vec	*cast_ray(const t_vec *pos, double theta, char **map)
{
	t_vec	*current_ray;
	t_vec	next_block;

	current_ray = (t_vec *)malloc(sizeof(t_vec));
	if (current_ray == NULL)
		exit(perror_return_one("failed to allocate memory\n"));
	vec_init(current_ray, pos->x, pos->y);
	vec_init(&next_block, (int)pos->x, (int)pos->y);
	while (true)
	{
		set_next_border(current_ray, theta);
		if (is_block(map, pos, current_ray))
			break ;
	}
	return (current_ray);
}

static void	set_next_border(t_vec *current_ray, double theta)
{
	t_vec	next_x_y;
	t_vec	dif_x_y;

	set_next_x_y(current_ray, &next_x_y, theta);
	vec_init(&dif_x_y, next_x_y.x - current_ray->x, \
						next_x_y.y - current_ray->y);
	if (cos(theta) == 0)
		current_ray->y = next_x_y.y;
	else if (is_next_x(current_ray, &next_x_y, theta))
	{
		current_ray->x = next_x_y.x;
		current_ray->y += dif_x_y.x * tan(theta);
	}
	else
	{
		current_ray->y = next_x_y.y;
		current_ray->x += dif_x_y.y / tan(theta);
	}
}

static void	set_next_x_y(t_vec *current_ray, t_vec *next_x_y, double theta)
{
	if (cos(theta) > 0)
		next_x_y->x = (int)current_ray->x + 1;
	else if (current_ray->x != (int)current_ray->x)
		next_x_y->x = (int)current_ray->x;
	else
		next_x_y->x = (int)current_ray->x - 1;
	if (sin(theta) > 0)
		next_x_y->y = (int)current_ray->y + 1;
	else if (current_ray->y != (int)current_ray->y)
		next_x_y->y = (int)current_ray->y;
	else
		next_x_y->y = (int)current_ray->y - 1;
}

// tell next border is parallel to x or y
static bool	is_next_x(t_vec *current_ray, t_vec *next_x_y, double theta)
{
	t_vec	gap_x_y;

	gap_x_y.x = fabs(next_x_y->x - current_ray->x);
	gap_x_y.y = fabs(next_x_y->y - current_ray->y);
	if (cos(theta) == 0)
		return (false);
	if (sin(theta) == 0)
		return (true);
	if (gap_x_y.x * fabs(tan(theta)) < gap_x_y.y)
		return (true);
	else
		return (false);
}

static bool	is_block(char **map, const t_vec *pos, t_vec *current_ray)
{
	int	x;
	int	y;

	if (current_ray->x == (int)current_ray->x && current_ray->x < pos->x)
			x = (int)current_ray->x;
	else
		x = (int)current_ray->x + 1;
	if (current_ray->y == (int)current_ray->y && current_ray->y < pos->y)
			y = (int)current_ray->y;
	else
		y = (int)current_ray->y + 1;
	return (map[y][x] == '1');
}
