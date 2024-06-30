/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:59:40 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 06:03:54 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_sort(t_stack *a, t_stack *b)
{
	if (a->top->data == get_min(a))
		pb(a, b, 1);
	else if (a->top->next->data == get_min(a))
	{
		sa(a, 1);
		pb(a, b, 1);
	}
	else if (a->top->next->next->data == get_min(a))
	{
		ra(a, 1);
		ra(a, 1);
		pb(a, b, 1);
	}
	else if (a->top->next->next->next->data == get_min(a))
	{
		rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
	else if (a->top->next->next->next->next->data == get_min(a))
	{
		rra(a, 1);
		pb(a, b, 1);
	}
}

int	stack_size(t_stack *tmp)
{
	int		i;
	t_node	*a;

	i = 0;
	a = tmp->top;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	get_max_position(t_stack *stack)
{
	int		max;
	int		position;
	int		max_pos;
	t_node	*temp;

	max = INT_MIN;
	position = 0;
	max_pos = -1;
	temp = stack->top;
	while (temp != NULL)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_pos = position;
		}
		temp = temp->next;
		position++;
	}
	return (max_pos);
}

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	init_position(t_stack *a)
{
	int		i;
	int		j;
	int		cmp;
	t_node	*head;
	t_node	*tmp;

	head = a->top;
	i = 0;
	j = 0;
	while (head)
	{
		tmp = a->top;
		cmp = head->data;
		head->pos = 0;
		while (tmp)
		{
			if ((tmp->data < cmp) && (i != j))
				head->pos++;
			tmp = tmp->next;
			j++;
		}
		i++;
		head = head->next;
	}
}
