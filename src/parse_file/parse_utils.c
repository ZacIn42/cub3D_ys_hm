#include "cub.h"

int	check_gnl_error(char *line, bool gnl_flag, char *message)
{
	if (line == NULL && gnl_flag == true)
		return (1);
	if (message != NULL)
		return (perror_return_one(message));
	return (0);
}

void	gnl_error(bool gnl_flag, char *error_message)
{
	gnl_flag = true;
	(void)gnl_flag;
	perror(error_message);
	return ;
}