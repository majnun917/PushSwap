/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:07:24 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 23:41:38 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int binde)
{
	t_node	*current;
	t_node	*prev;
	int		valuea;

	if (stack_size(a) < 2)
		return ;
	current = a->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	valuea = current->data;
	free(current);
	if (prev != NULL)
		prev->next = NULL;
	else
		a->top = NULL;
	push(a, valuea);
	if (binde == 1)
		write(1, "rra\n", 4);
	else if (binde == 0)
		return ;
}

void	rrb(t_stack *b, int binde)
{
	t_node	*current;
	t_node	*prev;
	int		valueb;

	if (stack_size(b) < 2)
		return ;
	current = b->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	valueb = current->data;
	free(current);
	if (prev != NULL)
		prev->next = NULL;
	else
		b->top = NULL;
	push(b, valueb);
	if (binde == 1)
		write(1, "rrb\n", 4);
	else if (binde == 0)
		return ;
}

void	rrr(t_stack *a, t_stack *b, int binde)
{
	rra(a, 0);
	rrb(b, 0);
	if (binde == 1)
		write(1, "rrr\n", 4);
	else if (binde == 0)
		return ;
}
