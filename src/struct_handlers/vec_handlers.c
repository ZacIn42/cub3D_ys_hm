/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:52:34 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 20:52:40 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vec_init(t_vec *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}

void	vec_add(t_vec *ans, t_vec *lhs, t_vec *rhs)
{
	ans->x = lhs->x + rhs->x;
	ans->y = lhs->y + rhs->y;
}

void	vec_sub(t_vec *ans, t_vec *lhs, t_vec *rhs)
{
	ans->x = lhs->x - rhs->x;
	ans->y = lhs->y - rhs->y;
}
