/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:34:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:04:55 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "iqueue.h"

static BOOL	_iqueue_clone(t_iqueue *self, t_iqueue *out);

BOOL	iqueue_create_with_capacity(t_iqueue *self, size_t capacity)
{
	if (!self || capacity == 0)
		return (FALSE);
	*self = (t_iqueue){0};
	self->queue = malloc(sizeof(int) * capacity);
	if (!self->queue)
		return (FALSE);
	self->capacity = capacity;
	self->length = 0;
	return (TRUE);
}

BOOL	iqueue_reserve(t_iqueue *self, size_t additional_capacity)
{
	int		*new_queue;
	size_t	new_capacity;
	size_t	len_back;
	size_t	len_front;

	new_capacity = self->capacity + additional_capacity;
	new_queue = malloc(sizeof(int) * new_capacity);
	if (!new_queue)
		return (FALSE);
	len_front = wrap_index(self->head + self->length, self->capacity);
	len_back = self->length - len_front;
	ft_memcpy(new_queue, &self->queue[self->head], len_back * sizeof(int));
	if (len_front != 0)
		ft_memcpy(&new_queue[len_back], self->queue, len_front * sizeof(int));
	free(self->queue);
	self->capacity = new_capacity;
	self->queue = new_queue;
	self->head = 0;
	return (TRUE);
}

void	iqueue_free(t_iqueue *self)
{
	if (self)
	{
		if (self->queue)
			free(self->queue);
		*self = (t_iqueue){0};
	}
}

BOOL	iqueue_clone(t_iqueue *self, t_iqueue *out)
{
	if (!self)
		return (FALSE);
	if (!iqueue_create_with_capacity(out, self->capacity))
		return (FALSE);
	if (!_iqueue_clone(self, out))
	{
		iqueue_free(out);
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	_iqueue_clone(t_iqueue *self, t_iqueue *out)
{
	size_t	idx;

	idx = 0;
	while (idx < self->length)
	{
		if (!iqueue_push_back(out, self->queue[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}
