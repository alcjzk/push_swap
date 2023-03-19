/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_minmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:32:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:40:37 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "iqueue.h"

ssize_t	iqueue_position_min(t_iqueue *self)
{
	int		min;
	size_t	min_idx;
	size_t	idx;

	if (self->length <= 0)
		return (-1);
	idx = 1;
	min_idx = 0;
	min = iqueue_get(self, 0);
	while (idx < self->length)
	{
		if (iqueue_get(self, idx) < min)
		{
			min = iqueue_get(self, idx);
			min_idx = idx;
		}
		idx++;
	}
	return (min_idx);
}

ssize_t	iqueue_position_max(t_iqueue *self)
{
	int		max;
	size_t	max_idx;
	size_t	idx;

	if (self->length <= 0)
		return (-1);
	idx = 1;
	max_idx = 0;
	max = iqueue_get(self, 0);
	while (idx < self->length)
	{
		if (iqueue_get(self, idx) > max)
		{
			max = iqueue_get(self, idx);
			max_idx = idx;
		}
		idx++;
	}
	return (max_idx);
}

int	iqueue_max(t_iqueue *self)
{
	int		max;
	size_t	index;

	if (self->length == 0)
		return (0);
	index = self->head;
	max = self->queue[wrap_index(index++, self->capacity)];
	while (index < self->length + self->head)
	{
		if (self->queue[wrap_index(index, self->capacity)] > max)
			max = self->queue[wrap_index(index, self->capacity)];
		index++;
	}
	return (max);
}
