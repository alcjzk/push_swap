/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:34:54 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 15:36:15 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

BOOL	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (TRUE);
	return (FALSE);
}