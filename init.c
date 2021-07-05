#	include "push_swap.h"

void	myswap(int *arr1, int *arr2)
{
	int	*tmp;

	*tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = *tmp;
}

void	mybubblesort(int *arr, int n)
{
	int	i;
	int	j;
	int	k;

	k = n - 1;
	i = 0;
	while (i < k)
	{
		j = 0;
		while (j < k - i)
		{
			if (arr[j] > arr[j + 1])
				myswap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	init(t_source *src, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		src->ta[j++] = ft_my_atoi(argv[i++]);
	}
}

void	init_sort(t_source *src, char **argv, int argc)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	init(src, argv);
	while (argv[i] != NULL)
		src->ta_sort[j++] = ft_my_atoi(argv[i++]);
	mybubblesort(src->ta_sort, argc - 1);
	i = 0;
	while (src->ta[i] == src->ta_sort[i] && i < argc - 1)
		i++;
	if (i == argc - 1)
	{
		free(src->ta);
		free(src->ta_sort);
		exit(1);
	}
}
