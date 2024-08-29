/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:11:55 by yususato          #+#    #+#             */
/*   Updated: 2024/08/29 17:21:42 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_file(t_field *field, char *filename)
{
	t_parse	parse;

	parse_texture(field, filename, &parse);
	read_map(filename, field, &parse);
	check_valid_map(field, &parse);
	return ;
}
