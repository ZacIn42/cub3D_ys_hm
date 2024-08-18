#include "cub.h"

static void	check_line_next(char *line, int *count)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == '\n')
			(*count)++;
		index++;
	}
	return ;
}

void	read_file_height(int fd, int *count)
{
	int		byte_size;
	char	*buf;

	byte_size = 1;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		exit(0);
	while (byte_size > 0)
	{
		byte_size = read(fd, buf, BUFFER_SIZE);
		if (byte_size == -1)
		{
			free(buf);
			buf = NULL;
			return ;
		}
		buf[byte_size] = '\0';
		check_line_next(buf, count);
	}
	free(buf);
	return ;
}

int	count_file_height(int fd)
{
	int		count;

	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		exit(0);
	read_file_height(fd, &count);
	return (count);
}
