/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:05:46 by yususato          #+#    #+#             */
/*   Updated: 2024/08/22 22:19:12 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_texture_north(char *line)
{
	char	*file;

	if (strncmp(line, "NO ", 3) != 0)
		exit(0);
	file = strchr(line, '.');
	if (file == NULL)
		exit(0);
	if (ft_strncmp(file, "./", 2) != 0)
		exit(0);
	file++;
	while (file != NULL && *file != '\0' && *file != '.')
		file++;
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
}

void	check_texture_sorth(char *line)
{
	char	*file;

	if (strncmp(line, "SO ", 2) != 0)
		exit(0);
	file = strchr(line, '.');
	if (file == NULL)
		exit(0);
	if (ft_strncmp(file, "./", 2) != 0)
		exit(0);
	file++;
	while (file && *file != '.')
		file++;
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
}
void	check_texture_west(char *line)
{
	char	*file;

	if (strncmp(line, "WE ", 2) != 0)
		exit(0);
	file = strchr(line, '.');
	if (file == NULL)
		exit(0);
	if (ft_strncmp(file, "./", 2) != 0)
		exit(0);
	file++;
	while (file && *file != '.')
		file++;
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
}
void	check_texture_east(char *line)
{
	char	*file;

	if (strncmp(line, "EA ", 2) != 0)
		exit(0);
	file = strchr(line, '.');
	if (file == NULL)
		exit(0);
	if (ft_strncmp(file, "./", 2) != 0)
		exit(0);
	file++;
	while (file && *file != '.')
		file++;
	if (ft_strncmp(file, ".xpm\0", 5) != 0)
		exit(0);
}
