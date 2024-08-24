/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:32:52 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 22:20:52 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	read_texture_content(t_parse *parse, char *new_line, int *fd)
{
	while (new_line)
	{
		parse->texture_height++;
		if (*new_line == '\0')
		{
			free(new_line);
			new_line = get_next_line(*fd);
			continue ;
		}
		count++;
		check_valid_texture(new_line, parse);
		free(new_line);
		if (count == 6)
			break ;
		new_line = get_next_line(*fd);
		if (!new_line)
			exit(perror_return_one("Error: missing texture and color\n"));
	}
	return ;
}

static void	count_map_height(t_parse *parse, char *new_line, int *fd)
{
	while ((new_line = get_next_line(*fd)) != NULL && *new_line == '\0')
		free(new_line);
	if (new_line == NULL)
		exit(perror_return_one("Error: map is empty\n"));
	parse->height = 1;
	free(new_line);
	while ((new_line = get_next_line(*fd)) != NULL)
	{
		parse->height++;
		if (*new_line == '\0')
			exit(perror_return_one("Error: blank in the middle of the map\n"));
		free(new_line);
	}
	return ;
}

static void	check_valid_texture(char *line, t_parse *parse)
{
	if (line[0] == 'N')
		check_texture_north(line, parse);
	else if (line[0] == 'S')
		check_texture_sorth(line, parse);
	else if (line[0] == 'W')
		check_texture_west(line, parse);
	else if (line[0] == 'E')
		check_texture_east(line, parse);
	else if (line[0] == 'F')
		check_texture_floor(line, parse);
	else if (line[0] == 'C')
		check_texture_ceiling(line, parse);
	else if (line[0] == '\n')
		return ;
	return ;
}

void	parse_texture(char *map, t_parse *parse)
{
	int		count;
	int		fd;
	char	*line;
	char	*new_line;

	count = 0;
	fd = open(map, O_RDONLY);
	new_line = get_next_line(fd);
	if (new_line == NULL)
		exit(perror_return_one("Error: file is empty\n"));
	parse->texture_height = 0;
	read_texture_content(parse, new_line, &fd);
	check_texture_flag(parse);
	count_map_height(parse, new_line, &fd);
	check_height(parse);
	close(fd);
}
