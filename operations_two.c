#include "push_swap.h"

int	rotate_a(t_source *src)
{
	int	tmp;
	int	i;

	write(1, "ra\n", 3);
	tmp = src->ta[0];
	i = 0;
	while (i < src->length_a - 1)
	{
		src->ta[i] = src->ta[i + 1];
		i++;
	}
	src->ta[src->length_a - 1] = tmp;
	return (0);
}

int	rotate_b(t_source *src)
{
	int	tmp;
	int	i;

	write(1, "rb\n", 3);
	tmp = src->tb[0];
	i = 0;
	while (i < src->length_b - 1)
	{
		src->tb[i] = src->tb[i + 1];
		i++;
	}
	src->tb[src->length_b - 1] = tmp;
	return (0);
}

int	reverse_rotate_a(t_source *src)
{
	int	tmp;
	int	i;

	write(1, "rra\n", 4);
	i = src->length_a - 1;
	tmp = src->ta[i];
	while (i != 0)
	{
		src->ta[i] = src->ta[i - 1];
		i--;
	}
	src->ta[0] = tmp;
	return (0);
}

int	reverse_rotate_b(t_source *src)
{
	int	tmp;
	int	i;

	write(1, "rrb\n", 4);
	i = src->length_b - 1;
	tmp = src->tb[i];
	while (i != 0)
	{
		src->tb[i] = src->tb[i - 1];
		i--;
	}
	src->tb[0] = tmp;
	return (0);
}
