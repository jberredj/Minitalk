/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cw_sep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:29:48 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/14 18:02:20 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_cw_sep(char const *s, char sep)
{
	size_t	count;
	short	word;

	if (s == NULL || *s == '\0')
		return (0);
	count = 0;
	word = 0;
	while (*s != '\0')
	{
		if (*s != sep)
		{
			if (word == 0)
				count++;
			word = 1;
		}
		else
			word = 0;
		s++;
	}
	return (count);
}
