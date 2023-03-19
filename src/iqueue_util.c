/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:50:42 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:43:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "iqueue.h"

BOOL	iqueue_is_full(t_iqueue *self)
{
	if (self->length == self->capacity)
		return (TRUE);
	return (FALSE);
}

BOOL	iqueue_is_empty(t_iqueue *self)
{
	if (self->length == 0)
		return (TRUE);
	return (FALSE);
}

int	iqueue_get(t_iqueue *self, size_t index)
{
	return (self->queue[wrap_index(self->head + index, self->capacity)]);
}

int	*iqueue_ref(t_iqueue *self, size_t index)
{
	return (&self->queue[wrap_index(self->head + index, self->capacity)]);
}
