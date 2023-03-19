/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:28:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/06 23:30:03 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iqueue.h"

void	iqueue_rotate_left(t_iqueue *self, size_t offset)
{
	int	value;

	if (iqueue_is_empty(self))
		return ;
	while (offset > 0)
	{
		value = iqueue_pop_front(self);
		iqueue_push_back(self, value);
		offset--;
	}
}

void	iqueue_rotate_right(t_iqueue *self, size_t offset)
{
	int	value;

	if (iqueue_is_empty(self))
		return ;
	while (offset > 0)
	{
		value = iqueue_pop_back(self);
		iqueue_push_front(self, value);
		offset--;
	}
}
