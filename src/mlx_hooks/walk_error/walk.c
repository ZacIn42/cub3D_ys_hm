/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:22:27 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/07 09:59:43 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_north(t_user *user, t_field *field);
bool	check_west(t_user *user, t_field *field);
bool	check_south(t_user *user, t_field *field);
bool	check_east(t_user *user, t_field *field);

static bool	check_forward(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		return (check_east(user, field));
	if (user->dir == WEST)
		return (check_west(user, field));
	if (user->dir == NORTH)
		return (check_north(user, field));
	if (user->dir == SOUTH)
		return (check_south(user, field));
	return (true);
}

static bool	check_right(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		return (check_south(user, field));
	if (user->dir == WEST)
		return (check_north(user, field));
	if (user->dir == NORTH)
		return (check_east(user, field));
	if (user->dir == SOUTH)
		return (check_west(user, field));
	return (true);
}

static bool	check_back(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		return (check_west(user, field));
	if (user->dir == WEST)
		return (check_east(user, field));
	if (user->dir == NORTH)
		return (check_south(user, field));
	if (user->dir == SOUTH)
		return (check_north(user, field));
	return (true);
}

static bool	check_left(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		return (check_north(user, field));
	if (user->dir == WEST)
		return (check_south(user, field));
	if (user->dir == NORTH)
		return (check_west(user, field));
	if (user->dir == SOUTH)
		return (check_east(user, field));
	return (true);
}

bool	check_walk(int key_code, t_user *user, t_field *field)
{
	if (key_code == MOVE_FORWARD_KEY)
		return (check_forward(user, field));
	else if (key_code == MOVE_RIGHT_KEY)
		return (check_right(user, field));
	else if (key_code == MOVE_BACK_KEY)
		return (check_back(user, field));
	else if (key_code == MOVE_LEFT_KEY)
		return (check_left(user, field));
	return (true);
}
