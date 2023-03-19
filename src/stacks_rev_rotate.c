/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rev_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:15:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:43:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stacks.h"

void	rev_rotate_a(t_stacks *stacks)
{
	rev_rotate_a_impl(stacks);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rev_rotate_b(t_stacks *stacks)
{
	rev_rotate_b_impl(stacks);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rev_rotate_a_impl(t_stacks *stacks)
{
	if (stacks->a.length <= 1)
		return ;
	iqueue_rotate_right(&stacks->a, 1);
}

void	rev_rotate_b_impl(t_stacks *stacks)
{
	if (stacks->a.length <= 1)
		return ;
	iqueue_rotate_right(&stacks->b, 1);
}
