/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:05:46 by yususato          #+#    #+#             */
/*   Updated: 2024/08/27 11:42:32 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_texture_north(t_field *field, char *line, t_parse *parse)
{
	int		index;
	char	*file;
	int		path_start_index;

	index = 0;
	if (ft_strncmp(line, "NO", 2) != 0)
		return (perror_return_one("north argument is invalid\n"));
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	path_start_index = index;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		return (perror_return_one("north argument is invalid\n"));
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		return (perror_return_one("north argument is invalid\n"));
	ft_strlcpy(field->texture_paths[NORTH], &line[path_start_index] \
				, ft_strlen(&line[path_start_index]) + 1);
	parse->north_flag = true;
	return (0);
}

int	check_texture_sorth(t_field *field, char *line, t_parse *parse)
{
	int		index;
	char	*file;
	int		path_start_index;

	index = 0;
	if (ft_strncmp(line, "SO", 2) != 0)
		return (perror_return_one("south argument is invalid\n"));
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	path_start_index = index;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		return (perror_return_one("south argument is invalid\n"));
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		return (perror_return_one("south argument is invalid\n"));
	ft_strlcpy(field->texture_paths[SOUTH], &line[path_start_index] \
				, ft_strlen(&line[path_start_index]) + 1);
	parse->sorth_flag = true;
	return (0);
}

int	check_texture_west(t_field *field, char *line, t_parse *parse)
{
	int		index;
	char	*file;
	int		path_start_index;

	index = 0;
	if (ft_strncmp(line, "WE", 2) != 0)
		return (perror_return_one("west argument is invalid\n"));
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	path_start_index = index;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		return (perror_return_one("west argument is invalid\n"));
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		return (perror_return_one("west argument is invalid\n"));
	ft_strlcpy(field->texture_paths[WEST], &line[path_start_index] \
				, ft_strlen(&line[path_start_index]) + 1);
	parse->west_flag = true;
	return (0);
}

int	check_texture_east(t_field *field, char *line, t_parse *parse)
{
	int		index;
	char	*file;
	int		path_start_index;

	index = 0;
	if (ft_strncmp(line, "EA", 2) != 0)
		return (perror_return_one("east argument is invalid\n"));
	while (index < 2)
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	path_start_index = index;
	if (ft_strncmp(&line[index], "./", 2) != 0)
		return (perror_return_one("east argument is invalid\n"));
	index += 2;
	file = strchr(&line[index], '.');
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		return (perror_return_one("east argument is invalid\n"));
	ft_strlcpy(field->texture_paths[EAST], &line[path_start_index] \
				, ft_strlen(&line[path_start_index]) + 1);
	parse->east_flag = true;
	return (0);
}
