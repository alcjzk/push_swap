/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rotate_both.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:58:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:44:04 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stacks.h"

void	rev_rotate_both(t_stacks *stacks)
{
	rev_rotate_both_impl(stacks);
	write(STDOUT_FILENO, "rrr\n", 4);
}

void	rotate_both(t_stacks *stacks)
{
	rotate_both_impl(stacks);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	rev_rotate_both_impl(t_stacks *stacks)
{
	rev_rotate_a_impl(stacks);
	rev_rotate_b_impl(stacks);
}

void	rotate_both_impl(t_stacks *stacks)
{
	rotate_a_impl(stacks);
	rotate_b_impl(stacks);
}
