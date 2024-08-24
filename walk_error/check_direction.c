#include "cub.h"

bool	check_north(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)user->pos.x;
	cast_y = (int)user->pos.y;
	point = user->pos.y - cast_y;
	if (field->map[cast_y + 1][cast_x] == '1' && point >= 0.9)
		return (false);
	return (true);
}

bool	check_west(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)user->pos.x;
	cast_y = (int)user->pos.y;
	point = user->pos.x - cast_x;
	if (field->map[cast_y][cast_x - 1] == '1' && point <= 0.1)
		return (false);
	return (true);
}

bool	check_south(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)user->pos.x;
	cast_y = (int)user->pos.y;
	point = user->pos.y - cast_y;
	if (field->map[cast_y - 1][cast_x] == '1' && point <= 0.1)
		return (false);
	return (true);
}

bool	check_east(t_user *user, t_field *field)
{
	int		cast_x;
	int		cast_y;
	double	point;

	cast_x = (int)user->pos.x;
	cast_y = (int)user->pos.y;
	point = user->pos.x - cast_x;
	if (field->map[cast_y][cast_x + 1] == '1' && point >= 0.9)
		return (false);
	return (true);
}