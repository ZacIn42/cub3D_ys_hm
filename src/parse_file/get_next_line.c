/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:29:02 by yususato          #+#    #+#             */
/*   Updated: 2024/09/08 11:56:44 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*line_next(char *buffer, bool *gnl_flag)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!tmp)
	{
		free(buffer);
		return (gnl_error(gnl_flag, "failed to allocate memory\n"), NULL);
	}
	i++;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	free(buffer);
	return (tmp);
}

static char	*output(char *buffer, bool *gnl_flag)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
	{
		free(buffer);
		return (gnl_error(gnl_flag, "failed to allocate memory\n"), NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i] = '\0';
	return (line);
}

static char	*unit(char *buffer, char *buf, bool *gnl_flag)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	if (temp == NULL)
		return (gnl_error(gnl_flag, "failed to allocate memory\n"), NULL);
	free(buffer);
	return (temp);
}

static char	*read_file(int fd, char *buffer, int *flag, bool *gnl_flag)
{
	int		byte_size;
	char	*buf;

	byte_size = 1;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (gnl_error(gnl_flag, "failed to allocate memory\n"), NULL);
	while (byte_size > 0)
	{
		byte_size = read(fd, buf, BUFFER_SIZE);
		if (byte_size == -1)
		{
			free(buf);
			return (*flag = 0, NULL);
		}
		buf[byte_size] = '\0';
		buffer = unit(buffer, buf, gnl_flag);
		if (buffer == NULL)
			return (gnl_error(gnl_flag, "failed to allocate memory\n"), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd, bool *gnl_flag)
{
	static char	*buffer;
	char		*line;
	int			flag;

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (gnl_error(gnl_flag, "Error read\n"), NULL);
	buffer = read_file(fd, buffer, &flag, gnl_flag);
	if (flag == 0)
	{
		free(buffer);
		return (gnl_error(gnl_flag, "Error read\n"), NULL);
	}
	if (!buffer)
		return (NULL);
	line = output(buffer, gnl_flag);
	buffer = line_next(buffer, gnl_flag);
	return (line);
}
