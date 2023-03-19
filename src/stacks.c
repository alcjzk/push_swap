/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:53:48 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:07:45 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

BOOL	stacks_create_from_iqueue(t_stacks *self, t_iqueue *queue)
{
	if (!iqueue_create_with_capacity(&self->b, queue->capacity))
		return (FALSE);
	self->a = *queue;
	*queue = (t_iqueue){0};
	return (TRUE);
}

void	stacks_free(t_stacks *self)
{
	if (self)
	{
		iqueue_free(&self->a);
		iqueue_free(&self->b);
	}
}
