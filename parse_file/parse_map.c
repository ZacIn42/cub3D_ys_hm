/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:02:48 by yususato          #+#    #+#             */
/*   Updated: 2024/08/22 14:36:44 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_height(t_parse *parse)
{
	if (parse->height < 3)
		exit(0);
	return ;
}

static void	insert_map_tmp(t_field *field, char *new_line, int *index)
{
	field->map[*index] = ft_strdup(new_line);
	(*index)++;
	return ;
}

static char	*ft_strdup_new(char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (src == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(src));
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

void	read_map(char *map, t_field *field)
{
	int		index;
	int		fd;
	char	*line;
	char	*new_line;
	t_parse	parse;

	index = 0;
	parse.height = 1;
	fd = open(map, O_RDONLY);
	parse.height += count_file_height(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	check_height(&parse);
	field->map = (char **)ft_calloc(sizeof(char *), parse.height + 1);
	line = get_next_line(fd);
	new_line = ft_strdup_new(line);
	if (new_line == NULL)
		exit(0);
	insert_map_tmp(field, new_line, &index);
	free(line);
	while (new_line)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		insert_map_tmp(field, new_line, &index);
		free(new_line);
	}
	close(fd);
	check_valid_map(field, &parse);
}
