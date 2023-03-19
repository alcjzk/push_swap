/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:09:37 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:44:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"
#include "stacks.h"
#include "bool.h"
#include "libft.h"
#include "get_next_line.h"
#include "iqueue.h"

int		main(int argc, char **argv);
BOOL	execute_rotate(t_stacks *stacks, char *instruction);
BOOL	execute(t_stacks *stacks, char *instruction);
BOOL	run(t_stacks *stacks);
BOOL	init(int argc, char **argv, t_iqueue *queue, t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_iqueue	queue;
	t_stacks	stacks;
	BOOL		result;

	result = TRUE;
	if (argc < 2)
		return (0);
	queue = (t_iqueue){0};
	stacks = (t_stacks){{0}, {0}};
	if (!init(argc, argv, &queue, &stacks))
		result = FALSE;
	if (result && !run(&stacks))
		result = FALSE;
	if (!result)
		write(STDERR_FILENO, "Error\n", 6);
	iqueue_free(&queue);
	stacks_free(&stacks);
	return (!result);
}

BOOL	execute_rotate(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", 4) == 0)
		rotate_a_impl(stacks);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		rotate_b_impl(stacks);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
		rotate_both_impl(stacks);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		rev_rotate_a_impl(stacks);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		rev_rotate_b_impl(stacks);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		rev_rotate_both_impl(stacks);
	else
		return (FALSE);
	return (TRUE);
}

BOOL	execute(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "pa\n", 4) == 0)
		push_a_impl(stacks);
	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
		push_b_impl(stacks);
	else if (ft_strncmp(instruction, "sa\n", 4) == 0)
		swap_a_impl(stacks);
	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
		swap_b_impl(stacks);
	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
		swap_both_impl(stacks);
	else
		return (execute_rotate(stacks, instruction));
	return (TRUE);
}

BOOL	run(t_stacks *stacks)
{
	char	*line;
	BOOL	result;

	result = TRUE;
	line = get_next_line(STDIN_FILENO);
	while (result && line)
	{
		if (!execute(stacks, line))
			result = FALSE;
		free(line);
		if (result)
			line = get_next_line(STDIN_FILENO);
	}
	if (!iqueue_is_sorted(&stacks->a) || !iqueue_is_empty(&stacks->b))
		write(STDOUT_FILENO, "KO\n", 3);
	else if (result)
		write(STDOUT_FILENO, "OK\n", 3);
	return (result);
}

BOOL	init(int argc, char **argv, t_iqueue *queue, t_stacks *stacks)
{
	size_t	capacity;

	capacity = 1;
	if (argc > 2)
		capacity = argc - 1;
	if (!iqueue_create_with_capacity(queue, capacity))
		return (FALSE);
	if (!parse_args(queue, argc, argv))
		return (FALSE);
	if (!stacks_create_from_iqueue(stacks, queue))
		return (FALSE);
	return (TRUE);
}
