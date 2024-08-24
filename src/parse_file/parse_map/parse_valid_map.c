#include "cub.h"

bool	check_space(t_field *field, t_parse *parse)
{
	if (field->map[parse->yi][parse->xi] == '0')
		return (true);
	return (false);
}

bool	check_first_pos(t_field *field, int yi, int xi)
{
	if (field->map[yi][xi] == 'N' \
		|| field->map[yi][xi] == 'S' \
		|| field->map[yi][xi] == 'W' \
		|| field->map[yi][xi] == 'E')
		return (true);
	return (false);
}

bool	check_wall(t_field *field, t_parse *parse)
{
	if (field->map[parse->yi][parse->xi - 1] != '1' \
		&& field->map[parse->yi][parse->xi - 1] != '0' \
		&& check_first_pos(field, parse->yi, parse->xi - 1) == false)
		return (false);
	if (field->map[parse->yi + 1][parse->xi] != '1' \
		&& field->map[parse->yi + 1][parse->xi] != '0'\
		&& check_first_pos(field, parse->yi + 1, parse->xi) == false)
		return (false);
	if (field->map[parse->yi][parse->xi + 1] != '1' \
		&& field->map[parse->yi][parse->xi + 1] != '0' \
		&& check_first_pos(field, parse->yi, parse->xi + 1) == false)
		return (false);
	if (field->map[parse->yi - 1][parse->xi] != '1' \
			&& field->map[parse->yi - 1][parse->xi] != '0' \
			&& check_first_pos(field, parse->yi - 1, parse->xi) == false)
			return (false);
	return (true);
}

void	can_pass(t_field *field, t_parse *parse, t_vec *stack, bool visited[MAX_SIZE][MAX_SIZE])
{
	t_vec	next;

	next.x = parse->xi;
	next.y = parse->yi;
	if (visited[parse->yi][parse->xi] == false
		&& check_space(field, parse))
	{
		if (parse->yi == 0 || parse->yi == parse->height - 1\
			|| parse->xi == 0 || parse->xi == (int)ft_strlen(field->map[parse->yi -1]) - 1)
				exit(0);
		if (check_wall(field, parse) == false)
			exit(0);
		parse->top++;
		visited[parse->yi][parse->xi] = true;
		stack[parse->top] = next;
	}
	return ;
}

bool	pass_find(t_field *field, t_parse *parse, t_vec *stack, bool visited[MAX_SIZE][MAX_SIZE])
{
	int			i;
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	t_vec		cur;

	while (parse->top >= 0)
	{
		i = 0;
		cur = stack[parse->top];
		parse->top--;
		while (i < 4)
		{
			parse->xi = cur.x + dx[i];
			parse->yi = cur.y + dy[i];
			can_pass(field, parse, stack, visited);
			i++;
		}
	}
	return (true);
}

void	check_map(t_field *field, t_parse *parse)
{
	t_vec	stack[MAX_SIZE];
	t_vec	node;
	bool	visited[MAX_SIZE][MAX_SIZE];
	int		index;

	index = 0;
	parse->top = 0;
	while (visited[index] == NULL)
	{
		ft_memset(visited, false, sizeof(visited));
		index++;
	}
	node.x = parse->pos_x;
	node.y = parse->pos_y;
	stack[parse->top] = node;
	visited[parse->pos_y][parse->pos_x] = true;
	if (!pass_find(field, parse, stack, visited))
		exit(0);
}

void	check_valid_map(t_field *field, t_parse *parse)
{
	int	height;
	int width;
	int pos_count;

	height = 0;
	width = 0;
	pos_count = 0;
	while (field->map[height])
	{
		while (field->map[height][width] && field->map[height][width] != '\0')
		{
			if (field->map[height][width] == 'N' \
				|| field->map[height][width] == 'S' \
				|| field->map[height][width] == 'W' \
				|| field->map[height][width] == 'E')
			{
				pos_count++;
				parse->pos_x = width;
				parse->pos_y = height;
			}
			else if (field->map[height][width] != '1' \
				&& field->map[height][width] != '0' \
				&& field->map[height][width] != ' ')
			{
				printf("Error map\n");
				exit(0);
			}
			width++;
		}
		width = 0;
		height++;
	}
	if (pos_count != 1)
		exit(0);
	check_map(field, parse);
}