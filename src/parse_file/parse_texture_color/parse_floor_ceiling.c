/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:13:01 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 22:27:01 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	is_valid_ceiling_extension(char *line, int *index, int *count, int *flag)
{
	while (line[*index])
	{
		if (!ft_isdigit(line[*index]))
			exit(perror_return_one("ceiling argument is invalid\n"));
		while (line[*index + count] && ft_isdigit(line[*index + count]))
			count++;
		file = ft_substr(line, *index, *index + count);
		if (atoi(file) < 0 || atoi(file) > 255)
			exit(perror_return_one("ceiling argument is invalid\n"));
		*index += count;
		free(file);
		if (line[*index] != ',' && line[*index] != '\0')
			exit(perror_return_one("ceiling argument is invalid\n"));
		*index++;
		count = 0;
		flag++;
	}
}

static void	is_valid_ceiling_extension(char *line, int *index, int *count, int *flag)
{
	while (line[*index])
	{
		if (!ft_isdigit(line[*index]))
			exit(perror_return_one("floor argument is invalid\n"));
		while (line[*index + count] && ft_isdigit(line[*index + count]))
			count++;
		file = ft_substr(line, *index, *index + count);
		if (atoi(file) < 0 || atoi(file) > 255)
			exit(perror_return_one("floor argument is invalid\n"));
		*index += count;
		free(file);
		if (line[*index] != ',' && line[*index] != '\0')
			exit(perror_return_one("floor argument is invalid\n"));
		*index++;
		count = 0;
		flag++;
	}
}

void	check_texture_ceiling(char *line, t_parse *parse)
{
	int		index;
	int		count;
	int		flag;
	char	*file;

	index = 3;
	count = 0;
	flag = 0;
	if (strncmp(line, "C ", 1) != 0)
		exit(perror_return_one("ceiling argument is invalid\n"));
	index++;
	while (line[index] && line[index] == ' ')
		index++;
	is_valid_extension(line, &index, &count, &flag);
	if (flag != 3)
		exit(perror_return_one("ceiling argument is invalid\n"));
	parse->ceiling_flag = true;
}

void	check_texture_floor(char *line, t_parse *parse)
{
	int		index;
	int		count;
	int		flag;
	char	*file;

	index = 3;
	count = 0;
	flag = 0;
	if (strncmp(line, "F", 1) != 0)
		exit(perror_return_one("floor argument is invalid\n"));
	index++;
	while (line[index] && line[index] == ' ')
		index++;
	is_valid_extension(line, &index, &count, &flag);
	if (flag != 3)
		exit(perror_return_one("floor argument is invalid\n"));
	parse->floor_flag = true;
}
