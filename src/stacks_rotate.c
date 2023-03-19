/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:10:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:42:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stacks.h"

void	rotate_a(t_stacks *stacks)
{
	rotate_a_impl(stacks);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stacks *stacks)
{
	rotate_b_impl(stacks);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_a_impl(t_stacks *stacks)
{
	if (stacks->a.length <= 1)
		return ;
	iqueue_rotate_left(&stacks->a, 1);
}

void	rotate_b_impl(t_stacks *stacks)
{
	if (stacks->b.length <= 1)
		return ;
	iqueue_rotate_left(&stacks->b, 1);
}
