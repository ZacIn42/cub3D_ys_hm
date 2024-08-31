/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_return_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:37:09 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/31 11:20:13 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	put_error(char *error_message);

int	perror_return_one(char *error_message)
{
	if (error_message != NULL)
	{
		put_error("ERROR: ");
		put_error(error_message);
	}
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
