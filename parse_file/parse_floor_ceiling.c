/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:13:01 by yususato          #+#    #+#             */
/*   Updated: 2024/08/22 21:12:31 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_texture_ceiling(char *line)
{
	int		index;
	int		count;
	int		flag;
	char	*file;

	index = 3;
	count = 0;
    flag = 0;
	if (strncmp(line, "C  ", 2) != 0)
		exit(0);
	while (line[index])
	{
		if (!ft_isdigit(line[index]))
			exit(0);
		while (line[index + count] && ft_isdigit(line[index + count]))
			count++;
		file = ft_substr(line, index, index + count);
		if (atoi(file) < 0 || atoi(file) > 255)
			exit(0);
		index += count;
		free(file);
        if (line[index] != ',' && line[index] != '\0')
            exit(0);
		index++;
        count = 0;
        flag++;
	}
	if (flag != 3)
		exit(0);
}

void	check_texture_floor(char *line)
{
	int		index;
	int		count;
	int		flag;
	char	*file;

	index = 3;
	count = 0;
    flag = 0;
	if (strncmp(line, "F ", 2) != 0)
		exit(0);
	while (line[index])
	{
		if (!ft_isdigit(line[index]))
			exit(0);
		while (line[index + count] && ft_isdigit(line[index + count]))
			count++;
		file = ft_substr(line, index, count);
		if (atoi(file) < 0 || atoi(file) > 255)
			exit(0);
		index += count;
		free(file);
        if (line[index] != ',' && line[index] != '\0')
            exit(0);
		index++;
        count = 0;
        flag++;
	}
	if (flag != 3)
		exit(0);
}