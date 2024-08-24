/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:32:52 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 17:04:53 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_height(t_parse *parse)
{
	if (parse->height < 3)
		exit(0);
	return ;
}

void	check_valid_texture(char *line, t_parse *parse)
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

static char	*ft_strdup_new(char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (src == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(src + 1));
	if (new == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	if (ft_strchr(new, '\n') && i != 0)
		new[i - 1] = '\0';
	else
		new[i] = '\0';
	return (new);
}

void	check_texture_flag(t_parse *parse)
{
	if (parse->north_flag == true && parse->sorth_flag == true \
		&& parse->west_flag == true && parse->east_flag == true \
		&& parse->ceiling_flag == true && parse->floor_flag == true)
		return ;
	exit(0);
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
		exit(0);
	parse->texture_height = 0;
	while (new_line)
	{
		parse->texture_height++;
		if (*new_line == '\0')
		{
			free(new_line);
			new_line = get_next_line(fd);
			continue ;
		}
		count++;
		check_valid_texture(new_line, parse);
		free(new_line);
		if (count == 6)
			break ;
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
	}
	check_texture_flag(parse);
	while ((new_line = get_next_line(fd)) != NULL && *new_line == '\0')
		free(new_line);
	if (new_line == NULL)
		exit(0);
	parse->height = 1;
	free(new_line);
	while ((new_line = get_next_line(fd)) != NULL)
	{
		parse->height++;
		if (*new_line == '\0')
			exit(0);
		free(new_line);
	}
	printf("%d\n", parse->texture_height);
	check_height(parse);
	close(fd);
}
