/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:09:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 20:41:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	put_error(char *error_message);

int	perror_return_one(char *error_message)
{
	if (error_message != NULL)
		put_error(error_message);
	return (1);
}

static void	put_error(char *error_message)
{
	if (error_message == NULL)
		return ;
	while (*error_message != '\0')
	{
		if (write(2, error_message, 1) < 0)
			return ;
		error_message += 1;
	}
}
