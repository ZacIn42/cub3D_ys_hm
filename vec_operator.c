/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:17:13 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/01 17:17:34 by hmiyazak         ###   ########.fr       */
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
