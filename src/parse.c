/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:56:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:15:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h" // TODO: Replace limits
#include <stdlib.h>
#include "util.h"

BOOL	parse_arg(t_iqueue *queue, char *arg)
{
	const char	*errstr;
	char		*token;
	int			value;

	errstr = NULL;
	token = ft_strtok(arg, " ");
	while (token)
	{
		value = ft_strtonum(token, int_min(), int_max(), &errstr);
		if (errstr || !iqueue_push_back(queue, value))
			return (FALSE);
		token = ft_strtok(NULL, " ");
	}
	return (TRUE);
}

BOOL	parse_args(t_iqueue *queue, int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if (!parse_arg(queue, argv[i]))
			return (FALSE);
		i++;
	}
	if (!iqueue_is_unique(queue))
		return (FALSE);
	return (TRUE);
}
