/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:18:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 19:09:53 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"
#include "stacks.h"

void	swap_a(t_stacks *stacks)
{
	swap_a_impl(stacks);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stacks *stacks)
{
	swap_b_impl(stacks);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_a_impl(t_stacks *stacks)
{
	int	*a;
	int	*b;

	if (stacks->a.length <= 1)
		return ;
	a = iqueue_ref(&stacks->a, 0);
	b = iqueue_ref(&stacks->a, 1);
	iswap(a, b);
}

void	swap_b_impl(t_stacks *stacks)
{
	int	*a;
	int	*b;

	if (stacks->b.length <= 1)
		return ;
	a = iqueue_ref(&stacks->b, 0);
	b = iqueue_ref(&stacks->b, 1);
	iswap(a, b);
}
