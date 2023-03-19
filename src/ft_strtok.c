/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:47:47 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:08:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "util.h"

static BOOL	_in_set(char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (TRUE);
		charset++;
	}
	return (FALSE);
}

size_t	ft_strspn(const char *str, const char *charset)
{
	size_t	length;

	length = 0;
	while (str[length] && _in_set(str[length], charset))
		length++;
	return (length);
}

size_t	ft_strcspn(const char *str, const char *charset)
{
	size_t	length;

	length = 0;
	while (str[length] && !_in_set(str[length], charset))
		length++;
	return (length);
}

char	*ft_strtok(char *restrict str, const char *restrict delim)
{
	static char	*head;
	char		*result;

	if (str)
		head = str;
	result = head + ft_strspn(head, delim);
	head = result + ft_strcspn(head, delim);
	if (*head)
	{
		*head = '\0';
		head++;
	}
	if (*result)
		return (result);
	else
		return (NULL);
}
