/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iqueue_lcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:10:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 18:24:01 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "iqueue.h"

static void	free_matrix(size_t **matrix, size_t length)
{
	size_t	idx;

	if (matrix)
	{
		idx = 0;
		while (idx < length)
		{
			if (matrix[idx])
				free(matrix[idx]);
			idx++;
		}
		free(matrix);
	}
}

static size_t	**create_matrix(size_t length)
{
	size_t	**matrix;
	size_t	idx;

	matrix = ft_calloc(length, sizeof(size_t *));
	if (!matrix)
		return (NULL);
	idx = 0;
	matrix[idx] = ft_calloc(length, sizeof(size_t));
	while (matrix[idx] && ++idx < length)
		matrix[idx] = ft_calloc(length, sizeof(size_t));
	if (idx != length)
	{
		free_matrix(matrix, length);
		return (NULL);
	}
	return (matrix);
}

static void	fill_matrix(size_t **matrix, t_iqueue *a, t_iqueue *b)
{
	size_t	r;
	size_t	c;

	r = 1;
	while (r <= a->length)
	{
		c = 1;
		while (c <= a->length)
		{
			if (iqueue_get(a, r - 1) == iqueue_get(b, c - 1))
				matrix[r][c] = matrix[r - 1][c - 1] + 1;
			else
				matrix[r][c] = ft_imax(matrix[r - 1][c], matrix[r][c - 1]);
			c++;
		}
		r++;
	}
}

static BOOL	create_seq(size_t **matrix, t_iqueue *a, t_iqueue *b, t_iqueue *out)
{
	size_t		r;
	size_t		c;

	r = a->length;
	c = a->length;
	while (r > 0 && c > 0)
	{
		if (iqueue_get(a, r - 1) == iqueue_get(b, c - 1))
		{
			iqueue_push_front(out, iqueue_get(a, r - 1));
			r--;
			c--;
		}
		else if (matrix[r][c - 1] > matrix[r - 1][c])
			c--;
		else
			r--;
	}
	return (TRUE);
}

BOOL	iqueue_lcs(t_iqueue *a, t_iqueue *b, t_iqueue *out)
{
	size_t	**matrix;
	BOOL	result;

	result = TRUE;
	matrix = create_matrix(a->length + 1);
	if (!matrix)
		return (FALSE);
	fill_matrix(matrix, a, b);
	if (!iqueue_create_with_capacity(out, matrix[a->length][a->length]))
		result = FALSE;
	if (result && !create_seq(matrix, a, b, out))
		result = FALSE;
	free_matrix(matrix, a->length + 1);
	if (!result)
		iqueue_free(out);
	return (result);
}
