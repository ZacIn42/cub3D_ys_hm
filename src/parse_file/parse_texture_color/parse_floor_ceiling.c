/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:13:01 by yususato          #+#    #+#             */
/*   Updated: 2024/08/27 14:06:15 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_color(unsigned int *color, int color_value, int *flag)
{
	if (*flag >= 3)
		exit(perror_return_one("floor argument is invalid\n"));
	if (*flag == 0)
		*color = color_value << 16;
	else if (*flag == 1)
		*color += color_value << 8;
	else if (*flag == 2)
		*color += color_value;
	return ;
}

static unsigned int	is_valid_ceiling_extension(char *line \
						, int *index, int *count, int *flag)
{
	unsigned int	color;
	char			*color_value;

	color = 0;
	while (line[*index])
	{
		if (!ft_isdigit(line[*index]))
			exit(perror_return_one("ceiling argument is invalid\n"));
		while (line[*index + *count] && ft_isdigit(line[*index + *count]))
			(*count)++;
		color_value = ft_substr(line, *index, *count);
		if (ft_atoi(color_value) < 0 || ft_atoi(color_value) > 255)
			exit(perror_return_one("ceiling argument is invalid\n"));
		set_color(&color, ft_atoi(color_value), flag);
		(*index) += *count;
		free(color_value);
		if (line[*index] != ',' && line[*index] != '\0')
			exit(perror_return_one("ceiling argument is invalid\n"));
		(*index)++;
		*count = 0;
		(*flag)++;
	}
	return (color);
}

static unsigned int	is_valid_floor_extension(char *line \
					, int *index, int *count, int *flag)
{
	unsigned int	color;
	char			*color_value;

	color = 0;
	while (line[*index])
	{
		if (!ft_isdigit(line[*index]))
			exit(perror_return_one("floor argument is invalid\n"));
		while (line[*index + *count] && ft_isdigit(line[*index + *count]))
			(*count)++;
		color_value = ft_substr(line, *index, *count);
		if (ft_atoi(color_value) < 0 || ft_atoi(color_value) > 255)
			exit(perror_return_one("floor argument is invalid\n"));
		set_color(&color, ft_atoi(color_value), flag);
		*index += *count;
		free(color_value);
		if (line[*index] != ',' && line[*index] != '\0')
			exit(perror_return_one("floor argument is invalid\n"));
		(*index)++;
		*count = 0;
		(*flag)++;
	}
	return (color);
}

void	check_texture_ceiling(t_field *field, char *line, t_parse *parse)
{
	int				index;
	int				count;
	int				flag;
	unsigned int	start_color_index;

	index = 0;
	count = 0;
	flag = 0;
	if (strncmp(line, "C ", 1) != 0)
		exit(perror_return_one("ceiling argument is invalid\n"));
	index++;
	while (line[index] && line[index] == ' ')
		index++;
	start_color_index = index;
	field->c_color = is_valid_ceiling_extension(line, &index, &count, &flag);
	if (flag != 3)
		exit(perror_return_one("ceiling argument is invalid\n"));
	parse->ceiling_flag = true;
}

void	check_texture_floor(t_field *field, char *line, t_parse *parse)
{
	int		index;
	int		count;
	int		flag;

	index = 0;
	count = 0;
	flag = 0;
	if (strncmp(line, "F", 1) != 0)
		exit(perror_return_one("floor argument is invalid\n"));
	index++;
	while (line[index] && line[index] == ' ')
		index++;
	field->f_color = is_valid_floor_extension(line, &index, &count, &flag);
	if (flag != 3)
		exit(perror_return_one("floor argument is invalid\n"));
	parse->floor_flag = true;
}
