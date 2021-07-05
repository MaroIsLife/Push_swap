#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_source
{
	int		length_b;
	int		length_a;
	int		length_c;
	int		length_min;
	int		*ta;
	int		*tb;
	int		*ta_min;
	int		*ta_sort;
	int		min;
	int		max;
	int		chunk;
	int		group;
}	t_source;

void		init_sort(t_source *src, char **argv, int argc);
//Instructions
int			swap(int *arr, int n, char c);
int			push_a(t_source *src);
int			push_b(t_source *src);
int			rotate_a(t_source *src);
int			rotate_b(t_source *src);
int			reverse_rotate_a(t_source *src);
int			reverse_rotate_b(t_source *src);
//Stack Sorting
void		three_stacks(t_source *src);
void		five_stacks(t_source *src);
void		five_stacks_two(t_source *src, int min_two);
void		sort_big_stacks_one(t_source *src);
void		sort_big_stacks_two(t_source *src);
void		sort_chunk_better(int b, int i, int chunk, t_source *src);
void		sort_chunk_better_two(t_source *src, int i);
void		big_chunks(t_source *src, int chunk);
//Utils
int			get_min(int *arr, int n);
int			get_max(int *arr, int n);
void		init_min_max_a(t_source *src);
void		init_min_max_b(t_source *src);
void		init_min_max_c(t_source *src);
long long	ft_my_atoi(const char *str);
#endif