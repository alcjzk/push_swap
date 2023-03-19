/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sort_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:12:42 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 23:48:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	sort_two(t_stacks *stacks)
{
	if (iqueue_is_sorted(&stacks->a))
		return ;
	swap_a(stacks);
}

void	sort_three(t_stacks *stacks)
{
	ssize_t	position_max;

	if (iqueue_is_sorted(&stacks->a))
		return ;
	position_max = iqueue_position_max(&stacks->a);
	if (position_max == 0)
		rotate_a(stacks);
	else if (position_max == 1)
		rev_rotate_a(stacks);
	if (!iqueue_is_sorted(&stacks->a))
		swap_a(stacks);
}

void	sort_five(t_stacks *stacks)
{
	size_t	min_idx;
	int		head;
	int		next;

	while (!iqueue_is_sorted(&stacks->a) && stacks->a.length > 1)
	{
		min_idx = iqueue_position_min(&stacks->a);
		head = iqueue_get(&stacks->a, 0);
		next = iqueue_get(&stacks->a, 1);
		if (min_idx == 0)
			push_b(stacks);
		else if (head == iqueue_max(&stacks->a))
			rev_rotate_a(stacks);
		else if (head > next)
			swap_a(stacks);
		else
			rev_rotate_a(stacks);
	}
	while (!iqueue_is_empty(&stacks->b))
		push_a(stacks);
}
