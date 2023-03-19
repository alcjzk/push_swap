/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:50:04 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/07 00:05:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stddef.h>
# include "bool.h"
# include "iqueue.h"

typedef struct s_stacks
{
	t_iqueue	a;
	t_iqueue	b;
}	t_stacks;

typedef struct s_moves
{
	ssize_t	a;
	ssize_t	b;
	size_t	total;
}	t_moves;

///		Constructs the stacks structure from an integer vector, invalidating
///		the original vec.
BOOL	stacks_create_from_iqueue(t_stacks *self, t_iqueue *queue);

///		Destructs the stacks structure.
void	stacks_free(t_stacks *self);

///		Swap the two topmost elements on stack a.
void	swap_a(t_stacks *stacks);

///		Swap the two topmost elements on stack b.
void	swap_b(t_stacks *stacks);

///		Swap the two topmost elements on both stacks.
void	swap_both(t_stacks *stacks);

///		Move the topmost element from stack b to stack a.
void	push_a(t_stacks *stacks);

///		Move the topmost element from stack a to stack b.
void	push_b(t_stacks *stacks);

///		Move the topmost element on stack a to the bottom, shifting all other
///		elements up.
void	rotate_a(t_stacks *stacks);

///		Move the topmost element on stack b to the bottom, shifting all other
///		elements up.
void	rotate_b(t_stacks *stacks);

///		Move the topmost element on each stack to the bottom, shifting all other
///		elements up.
void	rotate_both(t_stacks *stacks);

///		Move the bottom element on stack a to the top, shifting all other
///		elements down.
void	rev_rotate_a(t_stacks *stacks);

///		Move the bottom element on stack b to the top, shifting all other
///		elements down.
void	rev_rotate_b(t_stacks *stacks);

///		Move the bottom element on each stack to the top, shifting all other
///		elements down.
void	rev_rotate_both(t_stacks *stacks);

///		Rotates both stacks to the given offsets, using combined rotations when
///		possible. Negative offsets will have the effect of rotating the
///		corresponding stack in reverse.
void	rotate_by(t_stacks *stacks, ssize_t offset_a, ssize_t offset_b);

///		Rotates stack a to the given offset. A negative offset will have the
///		effect of rotating the stack in reverse.
void	rotate_a_by(t_stacks *stacks, ssize_t offset);

///		Rotates stack b to the given offset. A negative offset will have the
///		effect of rotating the stack in reverse.
void	rotate_b_by(t_stacks *stacks, ssize_t offset);

void	rev_rotate_a_impl(t_stacks *stacks);
void	rev_rotate_b_impl(t_stacks *stacks);
void	rev_rotate_both_impl(t_stacks *stacks);
void	rotate_a_impl(t_stacks *stacks);
void	rotate_b_impl(t_stacks *stacks);
void	rotate_both_impl(t_stacks *stacks);
void	push_a_impl(t_stacks *stacks);
void	push_b_impl(t_stacks *stacks);
void	swap_a_impl(t_stacks *stacks);
void	swap_b_impl(t_stacks *stacks);
void	swap_both_impl(t_stacks *stacks);

void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
BOOL	sort_large(t_stacks *stacks);
size_t	smallest_greater_than(t_iqueue *self, int value);
void	move(t_stacks *stacks);
void	align_a(t_stacks *stacks);

#endif
