/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:02:38 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 05:27:29 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *b, t_stack *a, int binde)
{
	t_node	*temp;

	if (stack_size(b) == 0)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->next = a->top;
	a->top = temp;
	if (binde == 1)
		write(1, "pa\n", 3);
	else if (binde == 0)
		return ;
}

void	pb(t_stack *a, t_stack *b, int binde)
{
	t_node	*temp;

	if (stack_size(a) == 0)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->next = b->top;
	b->top = temp;
	if (binde == 1)
		write(1, "pb\n", 3);
	else if (binde == 0)
		return ;
}
