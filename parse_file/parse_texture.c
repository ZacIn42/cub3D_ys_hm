/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:32:52 by yususato          #+#    #+#             */
/*   Updated: 2024/08/22 22:36:27 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_height(t_parse *parse)
{
	if (parse->height < 3)
		exit(0);
	return ;
}

void	check_valid_texture(char *line)
{
	if (line[0] == 'N')
		check_texture_north(line);
	else if (line[0] == 'S')
		check_texture_sorth(line);
	else if (line[0] == 'W')
		check_texture_west(line);
	else if (line[0] == 'E')
		check_texture_east(line);
	else if (line[0] == 'F')
		check_texture_floor(line);
	else if (line[0] == 'C')
		check_texture_ceiling(line);
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

void	parse_texture(char *map, t_parse *parse)
{
	int		count;
	int		fd;
	char	*line;
	char	*new_line;

	count = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	new_line = ft_strdup_new(line);
	if (new_line == NULL)
		exit(0);
	free(line);
	parse->texture_height = 0;
	while (new_line)
	{
		printf("%s\n",new_line);
		parse->texture_height++;
		if (*new_line == '\0')
		{
			free(new_line);
			new_line = get_next_line(fd);
			continue ;
		}
		count++;
		check_valid_texture(new_line);
		free(new_line);
		if (count == 6)
			break ;
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
	}
	parse->height = 1;
	parse->height += count_file_height(fd);
	printf("%d\n",parse->height);
	check_height(parse);
	close(fd);
}
