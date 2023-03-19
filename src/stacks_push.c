/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:23:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:33:02 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stacks.h"

void	push_a(t_stacks *stacks)
{
	push_a_impl(stacks);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_stacks *stacks)
{
	push_b_impl(stacks);
	write(STDOUT_FILENO, "pb\n", 3);
}

void	push_a_impl(t_stacks *stacks)
{
	int	value;

	if (iqueue_is_empty(&stacks->b))
		return ;
	value = iqueue_pop_front(&stacks->b);
	iqueue_push_front(&stacks->a, value);
}

void	push_b_impl(t_stacks *stacks)
{
	int	value;

	if (iqueue_is_empty(&stacks->a))
		return ;
	value = iqueue_pop_front(&stacks->a);
	iqueue_push_front(&stacks->b, value);
}
