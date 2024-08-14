#include "cub.h"

bool	check_space(t_field *field)
{
	if (field->map[field->yi][field->xi] == '0')
		return (true);
	return (false);
}

bool	check_wall(t_field *field)
{
	if (field->map[field->yi - 1][field->xi] \
		|| field->map[field->yi - 1][field->xi] == 1 \
		|| field->map[field->yi - 1][field->xi] == 0)
		return (true);
	else if (field->map[field->yi + 1][field->xi] \
		|| field->map[field->yi + 1][field->xi] == 1 \
		|| field->map[field->yi + 1][field->xi] == 0)
		return (true);
	else if (field->map[field->yi][field->xi - 1] \
		|| field->map[field->yi][field->xi - 1] == 1 \
		|| field->map[field->yi][field->xi - 1] == 0)
		return (true);
	else if (field->map[field->yi][field->xi + 1] \
		|| field->map[field->yi][field->xi + 1] == 1 \
		|| field->map[field->yi][field->xi + 1] == 0)
		return (true);
	return (false);
}

void	can_pass(t_field *field, t_vec *stack, bool visited[MAX_SIZE][MAX_SIZE])
{
	t_vec	next;

	next.x = field->xi;
	next.y = field->yi;
	if (visited[field->yi][field->xi] == false
		&& check_space(field))
	{
		if (check_wall(field) == false)
			exit(0);
		field->top++;
		field->map[field->yi][field->xi] = true;
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
	return (false);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
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
	stack[field->top] = node;
	visited[field->pos_y][field->pos_x] = true;
	if (!pass_find(field, stack, visited))
		exit(0);
}
