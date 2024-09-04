/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:20:08 by yususato          #+#    #+#             */
/*   Updated: 2024/09/03 21:03:30 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_space(t_field *field, t_parse *parse)
{
	if (field->map[parse->yi][parse->xi] == '0')
		return (true);
	return (false);
}

bool	check_first_pos(t_field *field, int yi, int xi)
{
	if (field->map[yi][xi] == 'E')
		field->user.dir = EAST;
	else if (field->map[yi][xi] == 'S')
		field->user.dir = SOUTH;
	else if (field->map[yi][xi] == 'W')
		field->user.dir = WEST;
	else if (field->map[yi][xi] == 'N')
		field->user.dir = NORTH;
	else
		return (false);
	return (true);
}

bool	check_wall(t_field *field, t_parse *parse)
{
	if (field->map[parse->yi][parse->xi - 1] != '1' \
		&& field->map[parse->yi][parse->xi - 1] != '0' \
		&& check_first_pos(field, parse->yi, parse->xi - 1) == false)
		return (false);
	if (field->map[parse->yi + 1][parse->xi] != '1' \
		&& field->map[parse->yi + 1][parse->xi] != '0'\
		&& check_first_pos(field, parse->yi + 1, parse->xi) == false)
		return (false);
	if (field->map[parse->yi][parse->xi + 1] != '1' \
		&& field->map[parse->yi][parse->xi + 1] != '0' \
		&& check_first_pos(field, parse->yi, parse->xi + 1) == false)
		return (false);
	if (field->map[parse->yi - 1][parse->xi] != '1' \
			&& field->map[parse->yi - 1][parse->xi] != '0' \
			&& check_first_pos(field, parse->yi - 1, parse->xi) == false)
		return (false);
	return (true);
}
