/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:42:16 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:06:15 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"
#include "stacks.h"
#include "iqueue.h"

BOOL	init(int argc, char **argv, t_iqueue *queue, t_stacks *stacks)
{
	size_t	capacity;
	BOOL	error;

	error = FALSE;
	capacity = 1;
	if (argc > 2)
		capacity = argc - 1;
	if (!iqueue_create_with_capacity(queue, capacity))
		error = TRUE;
	if (!error && !parse_args(queue, argc, argv))
		error = TRUE;
	if (!error && !stacks_create_from_iqueue(stacks, queue))
		error = TRUE;
	return (!error);
}

BOOL	run(t_stacks *stacks)
{
	if (stacks->a.length <= 1)
		return (TRUE);
	else if (stacks->a.length == 2)
		sort_two(stacks);
	else if (stacks->a.length == 3)
		sort_three(stacks);
	else if (stacks->a.length <= 5)
		sort_five(stacks);
	else
		return (!sort_large(stacks));
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_iqueue	queue;
	t_stacks	stacks;
	BOOL		error;

	queue = (t_iqueue){0};
	stacks = (t_stacks){{0}, {0}};
	error = FALSE;
	if (argc == 1)
		return (0);
	if (!init(argc, argv, &queue, &stacks))
		error = TRUE;
	if (!error)
		run(&stacks);
	else
		write(STDERR_FILENO, "Error\n", 6);
	iqueue_free(&queue);
	stacks_free(&stacks);
	return (error);
}
