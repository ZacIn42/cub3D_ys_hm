/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:32:22 by yususato          #+#    #+#             */
/*   Updated: 2024/09/08 14:21:25 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_valid_ft_atoi(char *color_value)
{
	int	index;

	index = 0;
	while (color_value[index])
	{
		if (ft_isdigit(color_value[index]))
			break ;
		index++;
	}
	if (color_value[index] && color_value[index] == '0')
	{
		if (color_value[index + 1] && ft_isdigit(color_value[index]))
			return (1);
	}
	if (ft_atoi(color_value) < 0 || ft_atoi(color_value) > 255)
		return (1);
	return (0);
}

int	check_gnl_error(char *line, bool gnl_flag, char *message)
{
	if (line == NULL && gnl_flag == true)
		return (1);
	if (line == NULL && message != NULL)
		return (perror_return_one(message));
	return (0);
}

void	gnl_error(bool *gnl_flag, char *error_message)
{
	*gnl_flag = true;
	perror(error_message);
	return ;
}

char	*init_error(int number)
{
	if (number == 1)
		return ("failed to allocate memory\n");
	else if (number == 2)
		return ("missing texture and color\n");
	return (NULL);
}
