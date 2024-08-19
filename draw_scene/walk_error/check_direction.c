#include "cub.h"

static bool	check_north(t_user *user, t_field *field)
{
	int		pos_y;
	double	point;

	*cast_y = (int)user->pos.y;
	point = user->pos.y - *cast_y;
	if (map[*cast_y + 1][*cast_x + 1] == '1' && point >= 0.9)
		return (false);
	return (true);
}

static bool	check_west(t_user *user, t_field *field)
{
	int		pos_x;
	double	point;

	*cast_x = (int)user->pos.x;
	point = user->pos.x - *cast_x;
	if (map[*cast_y - 1][*cast_x - 1] == '1' && point <= 0.1)
		return (false);
	return (true);
}

static bool	check_south(t_user *user, t_field *field)
{
	int		pos_y;
	double	point;

	*cast_y = (int)user->pos.y;
	point = user->pos.y - *cast_y;
	if (map[*cast_y - 1][*cast_x - 1] == '1' && point <= 0.1)
		return (false);
	return (true);
}

static bool	check_east(t_user *user, t_field *field)
{
	int		pos_x;
	double	point;

	*cast_x = (int)user->pos.x;
	point = user->pos.x - *cast_x;
	if (map[*cast_y + 1][*cast_x + 1] == '1' && point >= 0.9)
		return (false);
	return (true);
}