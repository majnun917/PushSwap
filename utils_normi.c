/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_normi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 04:45:36 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/26 15:45:50 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_chunk(t_stack *a, t_stack *b, int end_chunk, int mid_chunk)
{
	int	i;

	i = 0;
	init_position(a);
	while (i < end_chunk)
	{
		if (a->top->pos < end_chunk)
		{
			pb(a, b, 1);
			if (b->top->pos <= mid_chunk)
				rb(b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}

void	iter_chunk_inf(t_stack *a, int start_chunk, int chunk_size,
		int end_chunk)
{
	int	remainder;
	int	mid_chunk;

	mid_chunk = chunk_size / 2;
	remainder = stack_size(a) % 4;
	start_chunk += chunk_size;
	mid_chunk += chunk_size;
	if (start_chunk == chunk_size * 3 && remainder != 0)
		end_chunk += (chunk_size + remainder);
	else
		end_chunk += chunk_size;
}

void	iter_chunk_sup(t_stack *a, int start_chunk, int chunk_size,
		int end_chunk)
{
	int	remainder;
	int	mid_chunk;

	mid_chunk = chunk_size / 2;
	remainder = stack_size(a) % 10;
	start_chunk += chunk_size;
	mid_chunk += chunk_size;
	if (start_chunk == chunk_size * 9 && remainder != 0)
		end_chunk += (chunk_size + remainder);
	else
		end_chunk += chunk_size;
}
