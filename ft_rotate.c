/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:02:41 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 23:43:16 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int binde)
{
	t_node	*first;
	t_node	*last;

	if (stack_size(a) < 2)
		return ;
	first = a->top;
	a->top = a->top->next;
	first->next = NULL;
	last = a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	if (binde == 1)
		write(1, "ra\n", 3);
	else if (binde == 0)
		return ;
}

void	rb(t_stack *b, int binde)
{
	t_node	*first;
	t_node	*last;

	if (stack_size(b) < 2)
		return ;
	first = b->top;
	b->top = b->top->next;
	first->next = NULL;
	last = b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	if (binde == 1)
		write(1, "rb\n", 3);
	else if (binde == 0)
		return ;
}

void	rr(t_stack *a, t_stack *b, int binde)
{
	ra(a, 0);
	rb(b, 0);
	if (binde == 1)
		write(1, "rr\n", 3);
	else if (binde == 0)
		return ;
}
