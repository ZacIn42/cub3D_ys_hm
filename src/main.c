/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 20:09:35 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_filename(int argument_count, char *filename)
{
	char	*extension;

	if (argument_count != 2)
		exit(0);
	extension = strrchr(filename, '.');
	if (extension == NULL)
		exit(0);
	if (strncmp(extension, ".cub\0", 5) != 0)
		exit(0);
}

int	main(void)
{
	return (0);
}
