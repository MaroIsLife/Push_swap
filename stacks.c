#include "push_swap.h"

void	three_stacks(t_source *src)
{
	init_min_max_a(src);
	while (src->max != 2 || src->min != 0)
	{
		if (src->max == 2 && src->min == 1)
			swap(src->ta, src->length_a, 'a');
		else if (src->max == 0 && src->min == 2)
		{
			swap(src->ta, src->length_a, 'a');
			reverse_rotate_a(src);
		}
		else if (src->max == 0 && src->min == 1)
			rotate_a(src);
		else if (src->max == 1 && src->min == 0)
		{
			swap(src->ta, src->length_a, 'a');
			rotate_a(src);
		}
		else if (src->max == 1 && src->min == 2)
			reverse_rotate_a(src);
		init_min_max_a(src);
	}
}

void	five_stacks(t_source *src)
{
	int	i;
	int	min_one;
	int	min_two;

	i = 0;
	init_min_max_a(src);
	min_two = INT32_MAX;
	min_one = src->ta[src->min];
	while (i < src->length_a)
	{
		if (src->ta[i] < min_two && i != src->min)
			min_two = src->ta[i];
		i++;
	}
	init_min_max_a(src);
	if (src->min < 2)
	{
		while (src->ta[0] != min_one)
			rotate_a(src);
	}
	else
		while (src->ta[0] != min_one)
			reverse_rotate_a(src);
	five_stacks_two(src, min_two);
}

void	find_chunk(int chunk, t_source *src, int *i, int *b)
{
	int	p;

	p = 0;
	while (p < chunk)
	{
		if (src->ta[*i] == src->ta_min[p])
		{
			if (*i < src->length_a / 2)
			{
				while (src->ta[0] != src->ta_min[p])
					rotate_a(src);
			}
			else
			{
				while (src->ta[0] != src->ta_min[p])
					reverse_rotate_a(src);
			}
			push_b(src);
			*b = 1;
		}
		p++;
	}
}

void	sort_chunk_better(int b, int i, int chunk, t_source *src)
{
	int	p;

	while (i < src->length_a)
	{
		find_chunk(chunk, src, &i, &b);
		i++;
		if (b == 1)
		{
			b = 0;
			i = 0;
		}
		if (src->length_a == 0)
			break ;
	}
}

void	sort_chunk_better_two(t_source *src, int i)
{
	init_min_max_b(src);
	while (i < src->length_c)
	{
		if (src->max < src->length_b / 2)
		{
			while (src->tb[0] != src->tb[src->max])
			{
				rotate_b(src);
				init_min_max_b(src);
			}
		}
		else
		{
			while (src->tb[0] != src->tb[src->max])
			{
				reverse_rotate_b(src);
				init_min_max_b(src);
			}
		}
		push_a(src);
		init_min_max_b(src);
		i++;
	}
}
