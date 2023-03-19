/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:31:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:05:12 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IQUEUE_H
# define IQUEUE_H

# include <sys/types.h>
# include "bool.h"

typedef struct s_iqueue
{
	int		*queue;
	size_t	length;
	size_t	capacity;
	size_t	head;
}	t_iqueue;

typedef struct s_iqueue_iter
{
	t_iqueue	*queue;
	size_t		idx_next;
	int			*item;
}	t_iqueue_iter;

void	iqueue_debug(t_iqueue *self);

///		Creates a queue with the given initial capacity.
BOOL	iqueue_create_with_capacity(t_iqueue *self, size_t capacity);

///		Reserves the given amount of additional capacity for the queue.
BOOL	iqueue_reserve(t_iqueue *self, size_t additional_capacity);

///		Frees the queue.
void	iqueue_free(t_iqueue *self);

///		Creates a clone of the given queue.
BOOL	iqueue_clone(t_iqueue *self, t_iqueue *out);

///		Sorts the queue.
void	iqueue_sort(t_iqueue *self);

///		Returns TRUE if the queue is sorted.
BOOL	iqueue_is_sorted(t_iqueue *self);

///		Returns TRUE if the queue is full.
BOOL	iqueue_is_full(t_iqueue *self);

///		Returns TRUE if the queue is empty.
BOOL	iqueue_is_empty(t_iqueue *self);

///		Returns the value at the given index from the queue.
int		iqueue_get(t_iqueue *self, size_t index);

///		Returns a reference to the value at the given index in the queue.
int		*iqueue_ref(t_iqueue *self, size_t index);

///		Pushes the given value to the back of the queue. Returns FALSE on error.
BOOL	iqueue_push_back(t_iqueue *self, int value);

///		Pushes the given value to the front of the queue. Returns FALSE on
///		error.
BOOL	iqueue_push_front(t_iqueue *self, int value);

///		Pops the value at the back of the queue and returns it.
int		iqueue_pop_back(t_iqueue *self);

///		Pops the value at the front of the queue and returns it.
int		iqueue_pop_front(t_iqueue *self);

///		Returns the index of the smallest value in the queue, OR -1 if empty.
ssize_t	iqueue_position_min(t_iqueue *self);

///		Returns the index of the largest value in the queue, OR -1 if empty.
ssize_t	iqueue_position_max(t_iqueue *self);

///		Returns the largest value in the queue. Or 0 if the queue is empty.
int		iqueue_max(t_iqueue *self);

///		Creates an iterator for the queue.
BOOL	iqueue_iter(t_iqueue *self, t_iqueue_iter *iterator);

///		Returns the next item in the iterator, or NULL.
int		*iqueue_iter_next(t_iqueue_iter *iterator);

/// 	Longest common subsequence.
BOOL	iqueue_lcs(t_iqueue *a, t_iqueue *b, t_iqueue *out);

///		Rotates the queue to the left by offset.
void	iqueue_rotate_left(t_iqueue *self, size_t offset);

///		Rotates the queue to the right by offset.
void	iqueue_rotate_right(t_iqueue *self, size_t offset);

///		Returns TRUE if the queue contains only unique values.
BOOL	iqueue_is_unique(t_iqueue *self);

#endif
