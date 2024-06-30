/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:24:15 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 23:34:45 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(stack);
}

void	ft_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	ft_free(stack);
	exit(1);
}
