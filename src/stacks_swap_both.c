/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_swap_both.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:07:01 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 19:09:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stacks.h"

void	swap_both(t_stacks *stacks)
{
	swap_both_impl(stacks);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	swap_both_impl(t_stacks *stacks)
{
	swap_a_impl(stacks);
	swap_b_impl(stacks);
}
