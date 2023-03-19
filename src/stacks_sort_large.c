/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sort_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:20:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:58:22 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "stacks.h"

static BOOL	_sort_large(t_stacks *stacks, t_iqueue *sorted, t_iqueue *common);

void	partition(t_stacks *stacks, t_iqueue *common)
{
	size_t	length;
	int		a;
	int		b;

	length = stacks->a.length;
	while (!iqueue_is_empty(common))
	{
		a = iqueue_get(&stacks->a, 0);
		b = iqueue_get(common, 0);
		if (a == b)
		{
			iqueue_pop_front(common);
			rotate_a(stacks);
		}
		else
			push_b(stacks);
		length--;
	}
	while (length-- > 0)
		push_b(stacks);
}

static BOOL	_sort_large(t_stacks *stacks, t_iqueue *sorted, t_iqueue *common)
{
	size_t	min_idx;

	if (!iqueue_clone(&stacks->a, sorted))
		return (FALSE);
	iqueue_sort(sorted);
	min_idx = iqueue_position_min(&stacks->a);
	iqueue_rotate_right(sorted, min_idx);
	if (!iqueue_lcs(&stacks->a, sorted, common))
		return (FALSE);
	partition(stacks, common);
	while (!iqueue_is_empty(&stacks->b))
		move(stacks);
	align_a(stacks);
	return (TRUE);
}

BOOL	sort_large(t_stacks *stacks)
{
	t_iqueue	sorted;
	t_iqueue	common;
	BOOL		error;

	error = FALSE;
	sorted = (t_iqueue){0};
	common = (t_iqueue){0};
	if (iqueue_is_sorted(&stacks->a))
		return (TRUE);
	if (!_sort_large(stacks, &sorted, &common))
		error = TRUE;
	iqueue_free(&sorted);
	iqueue_free(&common);
	return (!error);
}
