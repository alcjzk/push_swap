/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:53:45 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 23:56:12 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "iqueue.h"

BOOL	iqueue_is_sorted(t_iqueue *self)
{
	size_t	i;
	int		head;
	int		prev;

	i = 1;
	while (i < self->length)
	{
		head = self->queue[wrap_index(self->head + i, self->capacity)];
		prev = self->queue[wrap_index(self->head + i - 1, self->capacity)];
		if (head < prev)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	iqueue_sort(t_iqueue *self)
{
	size_t	idx;
	size_t	head;

	if (self->length <= 1)
		return ;
	idx = 1;
	while (idx < self->length)
	{
		if (self->queue[idx] < self->queue[idx - 1])
		{
			head = idx;
			iswap(&self->queue[idx], &self->queue[idx - 1]);
			idx--;
			while (idx >= 1 && self->queue[idx] < self->queue[idx - 1])
			{
				iswap(&self->queue[idx], &self->queue[idx - 1]);
				idx--;
			}
			idx = head;
		}
		idx++;
	}
}
