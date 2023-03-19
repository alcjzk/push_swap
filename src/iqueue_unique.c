/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_unique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:24:37 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 23:27:40 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iqueue.h"

static BOOL	_iqueue_is_unique(t_iqueue *tmp);

BOOL	iqueue_is_unique(t_iqueue *self)
{
	t_iqueue	tmp;
	BOOL		result;

	if (self->length <= 1)
		return (TRUE);
	if (!iqueue_clone(self, &tmp))
		return (FALSE);
	result = _iqueue_is_unique(&tmp);
	iqueue_free(&tmp);
	return (result);
}

static BOOL	_iqueue_is_unique(t_iqueue *tmp)
{
	size_t	idx;
	int		prev;

	iqueue_sort(tmp);
	idx = 1;
	prev = tmp->queue[0];
	while (idx < tmp->length)
	{
		if (tmp->queue[idx] == prev)
			return (FALSE);
		prev = tmp->queue[idx];
		idx++;
	}
	return (TRUE);
}
