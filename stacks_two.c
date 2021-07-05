#include "push_swap.h"

void	big_chunks(t_source *src, int chunk)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (b < src->length_c)
	{
		src->ta_min = malloc(sizeof(int *) * (src->length_c - 1));
		i = 0;
		while (i < chunk && b < src->length_c)
		{
			src->ta_min[i] = src->ta_sort[b];
			i++;
			b++;
		}
		sort_chunk_better(0, 0, chunk, src);
		free(src->ta_min);
		src->ta_min = NULL;
	}
	sort_chunk_better_two(src, 0);
}

void	loop_rra(int index, t_source *src)
{
	while (index < src->length_a)
	{
		reverse_rotate_a(src);
		index++;
	}
}

void	sort_big_stacks_two(t_source *src)
{
	int	i;
	int	min;
	int	size;

	i = 0;
	init_min_max_a(src);
	size = src->length_a / 2;
	min = src->ta[src->min];
	if (src->min <= size)
	{
		while (src->min > 0)
		{
			rotate_a(src);
			src->min--;
		}
	}
	else if (src->min > size)
		loop_rra(src->min, src);
	push_b(src);
}

void	sort_big_stacks_one(t_source *src)
{
	int	i;
	int	b;

	i = src->length_a;
	while (i)
	{
		sort_big_stacks_two(src);
		i--;
	}
	b = src->length_b;
	while (b > 0)
	{
		push_a(src);
		b--;
	}
}

void	five_stacks_two(t_source *src, int min_two)
{
	push_b(src);
	while (src->ta[0] != min_two)
		rotate_a(src);
	push_b(src);
	three_stacks(src);
	push_a(src);
	push_a(src);
}
