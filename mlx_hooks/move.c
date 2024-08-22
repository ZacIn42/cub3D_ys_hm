/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:55:23 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/22 14:38:06 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	move_forward(t_user *user);
static int	move_right(t_user *user);
static int	move_back(t_user *user);
static int	move_left(t_user *user);

int	move(int key_code, t_user *user, t_field *field)
{
	if (user == NULL)
		return (1);
	if (check_walk(key_code, user, field) == false)
		return (1);
	if (key_code == MOVE_FORWARD_KEY)
		return (move_forward(user));
	else if (key_code == MOVE_RIGHT_KEY)
		return (move_right(user));
	else if (key_code == MOVE_BACK_KEY)
		return (move_back(user));
	else if (key_code == MOVE_LEFT_KEY)
		return (move_left(user));
	else
		return (1);
}

static int	move_forward(t_user *user)
{
	if (user->dir == NORTH)
		user->pos.y -= 0.1;
	else if (user->dir == EAST)
		user->pos.x += 0.1;
	else if (user->dir == SOUTH)
		user->pos.y += 0.1;
	else if (user->dir == WEST)
		user->pos.x -= 0.1;
	else
		return (1);
	return (0);
}

static int	move_right(t_user *user)
{
	if (user->dir == NORTH)
		user->pos.x += 0.1;
	else if (user->dir == EAST)
		user->pos.y += 0.1;
	else if (user->dir == SOUTH)
		user->pos.x -= 0.1;
	else if (user->dir == WEST)
		user->pos.y -= 0.1;
	else
		return (1);
	return (0);
}

static int	move_back(t_user *user)
{
	if (user->dir == NORTH)
		user->pos.y += 0.1;
	else if (user->dir == EAST)
		user->pos.x -= 0.1;
	else if (user->dir == SOUTH)
		user->pos.y -= 0.1;
	else if (user->dir == WEST)
		user->pos.x += 0.1;
	else
		return (1);
	return (0);
}

static int	move_left(t_user *user)
{
	if (user->dir == NORTH)
		user->pos.x -= 0.1;
	else if (user->dir == EAST)
		user->pos.y -= 0.1;
	else if (user->dir == SOUTH)
		user->pos.x += 0.1;
	else if (user->dir == WEST)
		user->pos.y += 0.1;
	else
		return (1);
	return (0);
}
