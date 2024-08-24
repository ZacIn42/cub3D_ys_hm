/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:32:07 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 21:35:19 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_height(t_parse *parse)
{
	if (parse->height < 3)
		exit(0);
	return ;
}

void	check_texture_flag(t_parse *parse)
{
	if (parse->north_flag == true && parse->sorth_flag == true \
		&& parse->west_flag == true && parse->east_flag == true \
		&& parse->ceiling_flag == true && parse->floor_flag == true)
		return ;
	exit(0);
}
