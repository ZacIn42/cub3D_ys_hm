/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:11:55 by yususato          #+#    #+#             */
/*   Updated: 2024/08/26 17:30:15 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_file(t_field *field, char *filename)
{
	t_parse	parse;

	parse_texture(filename, &parse);
	read_map(filename, field, &parse);
	check_valid_map(field, &parse);
	return ;
}