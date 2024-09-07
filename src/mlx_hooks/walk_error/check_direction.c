/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:22:22 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/07 11:20:11 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_north(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)(user->pos.x + 0.0001);
	cast_y = (int)(user->pos.y + 0.0001);
	point = user->pos.y - cast_y;
	if (field->map[cast_y - 1][cast_x] == '1' && point <= 0.15)
		return (false);
	if (fabs(cast_x - user->pos.x) < 0.0001 && cast_x != 0)
	{
		if (field->map[cast_y - 1][cast_x - 1] == '1' && point <= 0.15)
			return (false);
	}
	return (true);
}

bool	check_west(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)(user->pos.x + 0.0001);
	cast_y = (int)(user->pos.y + 0.0001);
	point = user->pos.x - cast_x;
	if (field->map[cast_y][cast_x - 1] == '1' && point <= 0.15)
		return (false);
	if (fabs(cast_y - user->pos.y) < 0.0001 && cast_y != 0)
	{
		if (field->map[cast_y - 1][cast_x - 1] == '1' && point <= 0.15)
			return (false);
	}
	return (true);
}

bool	check_south(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)(user->pos.x + 0.0001);
	cast_y = (int)(user->pos.y + 0.0001);
	point = user->pos.y - cast_y;
	if (field->map[cast_y + 1][cast_x] == '1' && point >= 0.85)
		return (false);
	if (fabs(cast_x - user->pos.x) < 0.0001 && cast_x != 0)
	{
		if (field->map[cast_y + 1][cast_x - 1] == '1' && point >= 0.85)
			return (false);
	}
	return (true);
}

bool	check_east(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)(user->pos.x + 0.0001);
	cast_y = (int)(user->pos.y + 0.0001);
	point = user->pos.x - cast_x;
	if (field->map[cast_y][cast_x + 1] == '1' && point >= 0.85)
		return (false);
	if (fabs(cast_y - user->pos.y) < 0.0001 && cast_y != 0)
	{
		if (field->map[cast_y - 1][cast_x + 1] == '1' && point >= 0.85)
			return (false);
	}
	return (true);
}
