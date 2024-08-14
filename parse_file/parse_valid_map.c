#include "cub.h"

bool	check_space(t_field *field)
{
				// printf("rrr%d,%d\n",field->yi,field->xi);
				// printf("rrr%p\n",field->map);

				// printf("rrr%s\n",field->map[field->yi]);

	if (field->map[field->yi][field->xi] == '0')
	{
		return (true);
	}
	return (false);
}

bool	check_first_pos(t_field *field, int yi, int xi)
{
	if (field->map[yi][xi] == 'N' \
		|| field->map[yi][xi] == 'S' \
		|| field->map[yi][xi] == 'W' \
		|| field->map[yi][xi] == 'E')
		return (true);
	write(1,"x\n",2);
	return (false);
}

bool	check_wall(t_field *field)
{
	if (field->map[field->yi][field->xi - 1] != '1' \
		&& field->map[field->yi][field->xi - 1] != '0' \
		&& check_first_pos(field, field->yi, field->xi - 1) == false)
		{
			printf("%d,%d\n", field->xi, field->yi);
			write(1,"a\n",2);
		return (false);
		}
	if (field->map[field->yi + 1][field->xi] != '1' \
		&& field->map[field->yi + 1][field->xi] != '0'\
		&& check_first_pos(field, field->yi + 1, field->xi) == false)
		return (false);
	if (field->map[field->yi][field->xi + 1] != '1' \
		&& field->map[field->yi][field->xi + 1] != '0' \
		&& check_first_pos(field, field->yi, field->xi + 1) == false)
		return (false);
	if (field->map[field->yi - 1][field->xi] != '1' \
			&& field->map[field->yi - 1][field->xi] != '0' \
			&& check_first_pos(field, field->yi - 1, field->xi) == false)
			return (false);
	return (true);
}

void	can_pass(t_field *field, t_vec *stack, bool visited[MAX_SIZE][MAX_SIZE])
{
	t_vec	next;

	next.x = field->xi;
	next.y = field->yi;
	if (visited[field->yi][field->xi] == false
		&& check_space(field))
	{
		if (field->yi == 0 || field->yi == field->height_count - 1\
			|| field->xi == 0 || field->xi == (int)ft_strlen(field->map[field->yi -1]) - 1)
				exit(0);
		if (check_wall(field) == false)
			exit(0);
		field->top++;
		visited[field->yi][field->xi] = true;
		stack[field->top] = next;
	}
	return ;
}

bool	pass_find(t_field *field, t_vec *stack, bool visited[MAX_SIZE][MAX_SIZE])
{
	int			i;
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	t_vec		cur;

	while (field->top >= 0)
	{
		i = 0;
		cur = stack[field->top];
		field->top--;
		while (i < 4)
		{
			field->xi = cur.x + dx[i];
			field->yi = cur.y + dy[i];
			can_pass(field, stack, visited);
			i++;
		}
	}
	return (true);
}

void	check_map(t_field *field)
{
	t_vec	stack[MAX_SIZE];
	t_vec	node;
	bool	visited[MAX_SIZE][MAX_SIZE];
	int		index;

	index = 0;
	field->top = 0;
	while (visited[index] == NULL)
	{
		ft_memset(visited, false, sizeof(visited));
		index++;
	}
	node.x = field->pos_x;
	node.y = field->pos_y;
	// printf("rrr%d,%d\n",field->pos_y,field->pos_x);
	stack[field->top] = node;
	visited[field->pos_y][field->pos_x] = true;
	if (!pass_find(field, stack, visited))
		exit(0);
}
