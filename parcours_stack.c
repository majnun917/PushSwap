/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcours_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:55:10 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/25 03:34:32 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	get_min(t_stack *stack)
{
	int		min;
	t_node	*node;

	node = stack->top;
	min = INT_MAX;
	while (node)
	{
		if (node->data < min)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_node	*node;

	max = INT_MIN;
	node = stack->top;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	long	i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
