/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:11:55 by yususato          #+#    #+#             */
/*   Updated: 2024/08/31 11:04:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_file(t_cub *cub, char *filename)
{
	t_field	*field;
	t_parse	parse;

	field = cub->field;
	if (parse_texture(field, filename, &parse) != 0)
		return (1);
	if (read_map(filename, field, &parse) != 0)
		return (1);
	if (check_valid_map(field, &parse) != 0)
		return (1);
	if (init_textures(cub->mlx, field) != 0)
	{
		free_str_array(field->map);
		return (1);
	}
	return (0);
}
