/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:46:04 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 19:14:58 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	look_left(t_user *user);
static int	look_right(t_user *user);

int	look_around(int key_code, t_user *user)
{
	if (key_code == LOOK_LEFT_KEY)
		return (look_left(user));
	else if (key_code == LOOK_RIGHT_KEY)
		return (look_right(user));
	else
		return (1);
}

//ATTENTION! the order of the DIRECTION (t_dir) must be N -> E -> S -> W here.
static int	look_right(t_user *user)
{
	if (user == NULL)
		return (1);
	user->dir = (user->dir + 1) % 4;
	return (0);
}

static int	look_left(t_user *user)
{
	if (user == NULL)
		return (1);
	user->dir = (user->dir - 1 + 4) % 4;
	return (0);
}
