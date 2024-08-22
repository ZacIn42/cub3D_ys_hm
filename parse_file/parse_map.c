/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:02:48 by yususato          #+#    #+#             */
/*   Updated: 2024/08/22 21:11:06 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	read_map(char *map, t_field *field, t_parse *parse)
{
	int		count;
	int		index;
	int		fd;
	char	*line;
	char	*new_line;

	index = 0;
	count = 0;
	fd = open(map, O_RDONLY);
	field->map = (char **)ft_calloc(sizeof(char *), parse->height + 1);
	while (count < parse->texture_height && new_line)
	{
		line = get_next_line(fd);
		if (!new_line)
			break ;
		free(line);
		count++;
	}
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
	check_valid_map(field, parse);
}
