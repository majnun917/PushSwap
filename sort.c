/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:27:49 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/26 02:47:34 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	min;
	int	max;

	min = get_min(a);
	max = get_max(a);
	while (!is_sorted(a) && stack_size(a) == 3)
	{
		if (a->top->data < max && a->top->next->data == min)
			sa(a, 1);
		else if (a->top->data == max && a->top->next->data > min)
		{
			sa(a, 1);
			rra(a, 1);
		}
		else if (a->top->data == max && a->top->next->data == min)
			ra(a, 1);
		else if (a->top->data == min && a->top->next->data == max)
		{
			sa(a, 1);
			ra(a, 1);
		}
		else if (a->top->data > min && a->top->next->data == max)
			rra(a, 1);
	}
}

void	help_sort_4(t_stack *a, int size)
{
	if (!is_sorted(a))
	{
		if (a->top->data == get_min(a))
			size--;
		else if (a->top->next->next->data == get_min(a))
		{
			rra(a, 1);
			rra(a, 1);
		}
		else if (a->top->next->next->next->data == get_min(a))
			rra(a, 1);
		else
			sa(a, 1);
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	size;
	int	sizeb;

	size = stack_size(a);
	while (!is_sorted(a) && size > 3 && size == 4)
	{
		help_sort_4(a, size);
		pb(a, b, 1);
		size--;
	}
	sort_three(a);
	sizeb = stack_size(b);
	while (sizeb > 0)
	{
		pa(b, a, 1);
		sizeb--;
		size++;
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min(a);
	max = get_max(a);
	while (!is_sorted(a) && stack_size(a) == 5)
		help_sort(a, b);
	while (!is_sorted(a) && stack_size(a) == 4)
		sort_4(a, b);
	while (!is_sorted(a) && stack_size(a) == 3)
		sort_three(a);
	pa(b, a, 1);
}
