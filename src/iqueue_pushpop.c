/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_pushpop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:34:52 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 23:39:56 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "iqueue.h"

BOOL	iqueue_push_back(t_iqueue *self, int value)
{
	size_t	index;

	if (iqueue_is_full(self) && !iqueue_reserve(self, self->capacity))
		return (FALSE);
	index = wrap_index(self->head + self->length, self->capacity);
	self->queue[index] = value;
	self->length++;
	return (TRUE);
}

int	iqueue_pop_back(t_iqueue *self)
{
	self->length--;
	return (self->queue[wrap_index(self->head + self->length, self->capacity)]);
}

int	iqueue_pop_front(t_iqueue *self)
{
	int	value;

	self->length--;
	value = self->queue[wrap_index(self->head++, self->capacity)];
	self->head = wrap_index(self->head, self->capacity);
	return (value);
}

BOOL	iqueue_push_front(t_iqueue *self, int value)
{
	if (iqueue_is_full(self) && !iqueue_reserve(self, self->capacity))
		return (FALSE);
	if (iqueue_is_empty(self))
		self->head = 0;
	else
		self->head = wrap_index((ssize_t)self->head - 1, self->capacity);
	self->queue[self->head] = value;
	self->length++;
	return (TRUE);
}
