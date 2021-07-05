#include "push_swap.h"

int	get_min(int *arr, int n)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = INT32_MAX;
	index = 0;
	while (i < n)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_max(int *arr, int n)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = arr[0];
	index = 0;
	while (i < n)
	{
		if (arr[i] > min)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	init_min_max_a(t_source *src)
{
	src->min = get_min(src->ta, src->length_a);
	src->max = get_max(src->ta, src->length_a);
}

void	init_min_max_b(t_source *src)
{
	src->min = get_min(src->tb, src->length_b);
	src->max = get_max(src->tb, src->length_b);
}

void	init_min_max_c(t_source *src)
{
	src->min = get_min(src->ta_sort, src->length_a);
	src->max = get_max(src->ta_sort, src->length_a);
}
