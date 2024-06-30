/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:50:41 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/26 15:37:04 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(0);
	a = parse_args(argc - 1, argv + 1);
	b = initialize_stack();
	sort_stack(a, b);
	ft_free(a);
	ft_free(b);
	return (0);
}
