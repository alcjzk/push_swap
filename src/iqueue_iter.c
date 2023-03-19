/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:30:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:09:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "util.h"
#include "iqueue.h"

BOOL	iqueue_iter(t_iqueue *self, t_iqueue_iter *iterator)
{
	if (!self || !iterator)
		return (FALSE);
	iterator->queue = self;
	iterator->idx_next = 0;
	return (TRUE);
}

int	*iqueue_iter_next(t_iqueue_iter *self)
{
	size_t	idx;

	if (!self || self->idx_next >= self->queue->length)
		return (NULL);
	idx = self->queue->head + self->idx_next++;
	idx = wrap_index(idx, self->queue->capacity);
	self->item = &self->queue->queue[idx];
	return (self->item);
}
