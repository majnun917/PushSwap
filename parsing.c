/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:06:28 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/25 03:33:49 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_arg(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	duplicate(t_stack *stack, int num)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->data == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	parse_num(t_stack *stack, char **args)
{
	int		j;

	j = len_arg(args) - 1;
	while (j >= 0)
	{
		if (ft_atoi(args[j]) == 0 && args[j][0] != '0')
			ft_error(stack);
		if (ft_atoi(args[j]) < -2147483646 || ft_atoi(args[j]) > 2147483647)
			ft_error(stack);
		if (duplicate(stack, ft_atoi(args[j])))
			ft_error(stack);
		push(stack, ft_atoi(args[j]));
		j--;
	}
}

void	ft_free_split(char **args)
{
	char	**tmp;

	tmp = args;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(args);
}

t_stack	*parse_args(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	char	**args;

	stack = initialize_stack();
	args = NULL;
	i = argc - 1;
	while (i >= 0)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			ft_error(stack);
		parse_num(stack, args);
		ft_free_split(args);
		i--;
	}
	return (stack);
}
