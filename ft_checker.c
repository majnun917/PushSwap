/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:38:08 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/27 03:31:02 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_checker(const char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa(b, a, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		ft_error(a);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		instructions_checker(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && stack_size(b) == 0)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(0);
	a = parse_args(argc - 1, argv + 1);
	if (!parse_args(argc, argv))
		ft_error(a);
	b = initialize_stack();
	checker(a, b);
	ft_free(a);
	ft_free(b);
	return (0);
}
