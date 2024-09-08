/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:11:55 by yususato          #+#    #+#             */
/*   Updated: 2024/09/08 13:03:01 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	parse_init(t_parse *parse)
{
	parse->north_flag = false;
	parse->sorth_flag = false;
	parse->west_flag = false;
	parse->east_flag = false;
	parse->ceiling_flag = false;
	parse->floor_flag = false;
	parse->gnl_flag = false;
	return ;
}

int	parse_file(t_cub *cub, char *filename)
{
	t_field	*field;
	t_parse	parse;

	field = cub->field;
	parse_init(&parse);
	if (parse_texture(field, filename, &parse) != 0)
		return (1);
	if (read_map(filename, field, &parse) != 0)
		return (1);
	if (check_valid_map(field, &parse) != 0)
		return (free_str_array(field->map), 1);
	if (init_textures(cub->mlx, field) != 0)
	{
		free_str_array(field->map);
		return (1);
	}
	return (0);
}
