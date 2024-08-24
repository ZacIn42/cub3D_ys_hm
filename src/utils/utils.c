/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:09:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 18:12:29 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	put_error(char *error_message);

void	put_error_exit(char *error_message)
{
	if (error_message != NULL)
		put_error(error_message);
	exit(1);
}

static void	put_error(char *error_message)
{
	if (error_message == NULL)
		return ;
	while (*error_message != '\0')
	{
		write(2, error_message, 1);
		error_message += 1;
	}
}
