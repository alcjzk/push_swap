/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sort_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:15:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:42:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "stacks.h"

void	align_a(t_stacks *stacks)
{
	size_t	idx_min;
	size_t	n_moves;

	idx_min = (size_t)iqueue_position_min(&stacks->a);
	if (idx_min > stacks->a.length / 2)
	{
		n_moves = stacks->a.length - idx_min;
		while (n_moves-- > 0)
			rev_rotate_a(stacks);
	}
	else
	{
		while (idx_min-- > 0)
			rotate_a(stacks);
	}
}

//	Returns the index of the smallest value on the given stack, that is larger
//	than the given value OR the index of the smallest value.
size_t	smallest_greater_than(t_iqueue *self, int value)
{
	int				min;
	size_t			idx_min;
	t_iqueue_iter	iter;

	iqueue_iter(self, &iter);
	min = iqueue_get(self, 0);
	idx_min = 0;
	while (iqueue_iter_next(&iter))
	{
		if (min < value && *(iter.item) < min)
		{
			idx_min = iter.idx_next - 1;
			min = *(iter.item);
		}
		else if (*(iter.item) > value && (min < value || *(iter.item) < min))
		{
			idx_min = iter.idx_next - 1;
			min = *(iter.item);
		}
	}
	return (idx_min);
}

ssize_t	to_top(t_iqueue *self, size_t idx)
{
	if (idx > self->length / 2)
		return (-(ssize_t)(self->length - idx));
	return (idx);
}

void	count_moves(t_moves *self, t_stacks *stacks, size_t tgt, size_t item)
{
	self->a = to_top(&stacks->a, tgt);
	self->b = to_top(&stacks->b, item);
	self->total = ziabs(self->a) + ziabs(self->b) + 1;
	if (zi_is_same_sign(self->a, self->b))
		self->total -= zumin(ziabs(self->a), ziabs(self->b));
}

void	move(t_stacks *stacks)
{
	t_iqueue_iter	iterator;
	t_moves			moves;
	t_moves			min_moves;
	size_t			idx_target;

	iqueue_iter(&stacks->b, &iterator);
	min_moves.total = (size_t)-1;
	while (iqueue_iter_next(&iterator))
	{
		idx_target = smallest_greater_than(&stacks->a, *(iterator.item));
		count_moves(&moves, stacks, idx_target, iterator.idx_next - 1);
		if (moves.total < min_moves.total)
			min_moves = moves;
	}
	rotate_by(stacks, min_moves.a, min_moves.b);
	push_a(stacks);
}
