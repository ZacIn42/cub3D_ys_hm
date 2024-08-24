/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:58:04 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 20:35:09 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_str_array(char **str_array)
{
	int	index;

	index = 0;
	if (str_array == NULL)
		return ;
	while (str_array[index] != NULL)
	{
		free(str_array[index]);
		index++;
	}
	free(str_array);
}
