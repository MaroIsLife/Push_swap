#include "push_swap.h"

void	check_argv_two(char **argv, int argc, int i)
{
	int	j;

	j = 0;
	while (argv[i][j] != '\0')
	{		
		if (!ft_isdigit(argv[i][j]))
		{
			if (argv[i][j] == '-' && j != 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			if (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			if (argv[i][j] != '-')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		j++;
	}
	if (argc < 2)
		exit(1);
}

void	check_argv(char **argv, int argc, int i)
{
	int	j;

	j = 1;

	while (argv[i] != NULL)
	{	
		check_argv_two(argv, argc, i);
		j = i + 1;
		if (ft_my_atoi(argv[i]) > INT32_MAX || ft_my_atoi(argv[i]) < INT32_MIN)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (argv[j] != NULL)
		{
			if (ft_my_atoi(argv[i]) == ft_my_atoi(argv[j]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	count_stack(t_source *src)
{
	if (src->length_a == 2)
		swap(src->ta, src->length_a, 'a');
	else if (src->length_a == 3)
		three_stacks(src);
	else if (src->length_a == 5)
		five_stacks(src);
	else if (src->length_a >= 6 && src->length_a < 100)
		sort_big_stacks_one(src);
	else if (src->length_a > 150)
		big_chunks(src, src->length_a / 12);
	else if (src->length_a >= 100)
		big_chunks(src, src->length_a / 6);
	else
		sort_big_stacks_one(src);
}

int	main(int argc, char **argv)
{
	t_source	src;

	check_argv(argv, argc, 1);
	src.ta = malloc(sizeof(int *) * (argc - 1));
	src.tb = malloc(sizeof(int *) * (argc - 1));
	src.ta_sort = malloc(sizeof(int *) * (argc - 1));
	src.length_b = 0;
	src.length_a = argc - 1;
	src.length_c = src.length_a;
	init_sort(&src, argv, argc);
	count_stack(&src);
	free(src.ta);
	free(src.tb);
	free(src.ta_sort);
	return (0);
}
