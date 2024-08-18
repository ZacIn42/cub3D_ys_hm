#include "cub.h"

bool	check_forward(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		check_east(user, field);
	if (user->dir == WEST)
		check_west(user, field);
	if (user->dir == NORTH)
		check_north(user, field);
	if (user->dir == SOUTH)
		check_south(user, field);
}

bool	check_right(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		check_south(user, field);
	if (user->dir == WEST)
		check_north(user, field);
	if (user->dir == NORTH)
		check_east(user, field);
	if (user->dir == SOUTH)
		check_west(user, field);
}

bool	check_back(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		check_west(user, field);
	if (user->dir == WEST)
		check_east(user, field);
	if (user->dir == NORTH)
		check_south(user, field);
	if (user->dir == SOUTH)
		check_north(user, field);
}

bool	check_left(t_user *user, t_field *field)
{
	if (user->dir == EAST)
		check_north(user, field);
	if (user->dir == WEST)
		check_south(user, field);
	if (user->dir == NORTH)
		check_west(user, field);
	if (user->dir == SOUTH)
		check_east(user, field);
}

bool	check_walk(int key_code, t_user *user, t_field *field)
{
	int	cast_x;
	int	cast_y;

	check_current_pos(user, field, &cast_x, &cast_y);
	if (key_code == MOVE_FORWARD_KEY)
		check_forward(user, field);
	else if (key_code == MOVE_RIGHT_KE)
		check_right(user, field);
	else if (key_code == MOVE_BACK_KEY)
		check_back(user, field);
	else if (key_code == MOVE_LEFT_KEY)
		check_left(user, field);
	return (true);
}

