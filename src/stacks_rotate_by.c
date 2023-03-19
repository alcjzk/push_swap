/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rotate_by.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:45:13 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 03:28:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	rotate_a_by(t_stacks *stacks, ssize_t offset)
{
	while (offset < 0)
	{
		rev_rotate_a(stacks);
		offset++;
	}
	while (offset > 0)
	{
		rotate_a(stacks);
		offset--;
	}
}

void	rotate_b_by(t_stacks *stacks, ssize_t offset)
{
	while (offset < 0)
	{
		rev_rotate_b(stacks);
		offset++;
	}
	while (offset > 0)
	{
		rotate_b(stacks);
		offset--;
	}
}

void	rotate_by(t_stacks *stacks, ssize_t offset_a, ssize_t offset_b)
{
	while (offset_a < 0 && offset_b < 0)
	{
		rev_rotate_both(stacks);
		offset_a++;
		offset_b++;
	}
	while (offset_a > 0 && offset_b > 0)
	{
		rotate_both(stacks);
		offset_a--;
		offset_b--;
	}
	rotate_a_by(stacks, offset_a);
	rotate_b_by(stacks, offset_b);
}
