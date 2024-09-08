/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:58:04 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/08 13:40:10 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_str_array(char **str_array)
{
	int	index;

	index = 0;
	if (str_array == NULL)
		return ;
	while (str_array[index])
	{
		free(str_array[index]);
		index++;
	}
	free(str_array);
}
