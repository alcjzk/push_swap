/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:08:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:08:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

size_t	wrap_index(ssize_t index, size_t capacity)
{
	if (index < 0)
		return (capacity + index);
	return (index % capacity);
}

void	iswap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

size_t	ziabs(ssize_t value)
{
	if (value < 0)
		return (-value);
	return (value);
}

size_t	zumin(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

BOOL	zi_is_same_sign(ssize_t a, ssize_t b)
{
	return ((a < 0) != (b >= 0));
}
