/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:05:46 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 16:39:08 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_texture_north(char *line, t_parse *parse)
{
	int		index;
	char	*file;

	index = 0;
	if (ft_strncmp(line, "NO", 2) != 0)
		exit(0);
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		exit(0);
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
	parse->north_flag = true;
}

void	check_texture_sorth(char *line, t_parse *parse)
{
	int		index;
	char	*file;

	index = 0;
	if (ft_strncmp(line, "SO", 2) != 0)
		exit(0);
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		exit(0);
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
	parse->sorth_flag = true;
}

void	check_texture_west(char *line, t_parse *parse)
{
	int		index;
	char	*file;

	index = 0;
	if (ft_strncmp(line, "WE", 2) != 0)
		exit(0);
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		exit(0);
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
	parse->west_flag = true;
}

void	check_texture_east(char *line, t_parse *parse)
{
	int		index;
	char	*file;

	index = 0;
	if (ft_strncmp(line, "EA", 2) != 0)
		exit(0);
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		exit(0);
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
	parse->east_flag = true;
}
