/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:51:41 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 17:42:35 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	if (!s1)
	new = (char *) ft_calloc((ft_strlen(s2) + 1), sizeof(char));
	else
	new = (char *) ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (!s1)
		ft_strlcpy(new, s2, ft_strlen(s2) + 2);
	else
	{
		ft_strlcpy(new, s1, ft_strlen(s1) + 1);
		ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 2);
	}
	return (new);
}
