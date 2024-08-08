#include "cub.h"

void	can_pass(t_field *field, t_stack *stack, bool *visited)
{
	t_stack	next;

	next.x = field->xi;
	next.y = field->yi;
	if (visited[field->xi + (field->yi * field->width)] == false
		&& check(field))
	{
		field->top++;
		visited[field->xi + (field->yi * field->width)] = true;
		stack[field->top] = next;
	}
}

bool	pass_find(t_field *field, t_stack *stack, bool visited[])
{
	int			i;
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	t_stack		cur;

	while (field->top >= 0)
	{
		i = 0;
		cur = stack[field->top];
		field->top--;
		if (check_end(field, &cur) == true)
			return (true);
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

void	wall_check(t_field *field)
{
	
}

void	check_map(t_field *field, char **map)
{
	t_stack	stack[MAX_SIZE];
	t_stack	node;
	bool	visited[MAX_SIZE * MAX_SIZE];

	wall_check(field);
	ft_memset(visited, false, sizeof(visited));
	serch_p(field, &node);
	stack[field->top] = node;
	visited[node.x + (node.y * field->width)] = true;
	if (!pass_find(field, stack, visited))
		ft_exit();
	col_check(field);
}