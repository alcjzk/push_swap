/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:07:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/08 17:15:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "bool.h"
# include "iqueue.h"
# include <sys/types.h>

# define ERR_INVALID "The string did not consist solely of digit characters."
# define ERR_TOOSMALL "The result was smaller than the provided minimum value."
# define ERR_TOOLARGE "The result was larger than the provided maximum value."

long long	ft_strtonum(
				const char *str,
				long long min,
				long long max,
				const char **errstr);
char		*ft_strtok(char *restrict str, const char *restrict delim);
BOOL		ft_isspace(char c);
size_t		wrap_index(ssize_t index, size_t capacity);
void		iswap(int *a, int *b);
size_t		ziabs(ssize_t value);
size_t		zumin(size_t a, size_t b);
BOOL		zi_is_same_sign(ssize_t a, ssize_t b);
BOOL		parse_arg(t_iqueue *queue, char *arg);
BOOL		parse_args(t_iqueue *queue, int argc, char **argv);
int			int_max(void);
int			int_min(void);

#endif
