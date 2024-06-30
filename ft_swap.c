/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:34:40 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/25 03:42:47 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int binde)
{
	t_node	*tmp;

	if (stack_size(a) < 2)
		return ;
	tmp = a->top->next;
	a->top->next = tmp->next;
	tmp->next = a->top;
	a->top = tmp;
	if (binde == 1)
		write(1, "sa\n", 3);
	else if (binde == 0)
		return ;
}

void	sb(t_stack *b, int binde)
{
	t_node	*temp;

	if (stack_size(b) < 2)
		return ;
	temp = b->top->next;
	b->top->next = temp->next;
	temp->next = b->top;
	b->top = temp;
	if (binde == 1)
		write(1, "sb\n", 3);
	else if (binde == 0)
		return ;
}

void	ss(t_stack *a, t_stack *b, int binde)
{
	sa(a, 0);
	sb(b, 0);
	if (binde == 1)
		write(1, "ss\n", 3);
	else if (binde == 0)
		return ;
}
