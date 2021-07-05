#include "push_swap.h"

int	swap(int *arr, int n, char c)
{
	int	tmp;

	if (n <= 1)
	{
		printf("One or no elements\n");
		return (0);
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	return (0);
}

int	push_a(t_source *src)
{
	int	i;
	int	o;

	if (src->length_b == 0)
		return (0);
	write(1, "pa\n", 3);
	src->length_b--;
	src->length_a++;
	i = 0;
	o = src->length_a;
	while (i < src->length_a)
	{
		src->ta[o] = src->ta[o - 1];
		i++;
		o--;
	}
	src->ta[0] = src->tb[0];
	i = 0;
	o = 1;
	while (i < src->length_b)
		src->tb[i++] = src->tb[o++];
	return (0);
}

int	push_b(t_source *src)
{
	int	i;
	int	o;

	if (src->length_a == 0)
		return (0);
	write(1, "pb\n", 3);
	src->length_b++;
	src->length_a--;
	i = 0;
	o = src->length_b;
	while (i < src->length_b)
	{
		src->tb[o] = src->tb[o - 1];
		i++;
		o--;
	}
	src->tb[0] = src->ta[0];
	i = 0;
	o = 1;
	while (i < src->length_a)
		src->ta[i++] = src->ta[o++];
	return (0);
}
