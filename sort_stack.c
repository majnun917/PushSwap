/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:00:00 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/26 15:51:29 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min(a);
	max = get_max(a);
	if (!is_sorted(a) && stack_size(a) == 2)
		sa(a, 1);
	if (stack_size(a) == 3)
		sort_three(a);
	else if (stack_size(a) == 4)
		sort_4(a, b);
	else if (stack_size(a) == 5)
		sort_five(a, b);
	else if (stack_size(a) < 200 && stack_size(a) > 5)
		sort_stack_inferieur(a, b, 0);
	else if (stack_size(a) > 200)
		sort_stack_superieur(a, b, 0);
}

void	push_chunk_b_to_a(t_stack *a, t_stack *b)
{
	int	size;
	int	high;
	int	moitie;
	int	j;

	high = 0;
	size = stack_size(b);
	j = 0;
	while (stack_size(b) > 0)
	{
		high = get_max_position(b);
		moitie = size / 2;
		size--;
		if (high <= moitie)
			while (b->top->data != get_max(b))
				rb(b, 1);
		else
			while (b->top->data != get_max(b))
				rrb(b, 1);
		pa(b, a, 1);
	}
}

void	sort_stack_inferieur(t_stack *a, t_stack *b, int chunk_size)
{
	int	start_chunk;
	int	mid_chunk;
	int	end_chunk;
	int	remainder;

	chunk_size = stack_size(a) / 4;
	remainder = stack_size(a) % 4;
	start_chunk = 0;
	mid_chunk = chunk_size / 2;
	end_chunk = chunk_size;
	while (!is_sorted(a) && stack_size(a) > 0)
	{
		push_b_chunk(a, b, end_chunk, mid_chunk);
		iter_chunk_inf(a, chunk_size, start_chunk, end_chunk);
	}
	push_chunk_b_to_a(a, b);
}

void	sort_stack_superieur(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	start_chunk;
	int	mid_chunk;
	int	end_chunk;
	int	remainder;

	chunk_size = stack_size(a) / 10;
	remainder = stack_size(a) % 10;
	start_chunk = 0;
	mid_chunk = chunk_size / 2;
	end_chunk = chunk_size;
	i = 0;
	init_position(a);
	while (!is_sorted(a) && stack_size(a) > 0)
	{
		push_b_chunk(a, b, end_chunk, mid_chunk);
		iter_chunk_sup(a, chunk_size, start_chunk, end_chunk);
	}
	push_chunk_b_to_a(a, b);
}
