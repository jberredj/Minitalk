/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:55:16 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/24 15:24:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_char;
	char	*curr_char;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	curr_char = ft_strchr(s, c);
	last_char = curr_char;
	while (curr_char != NULL)
	{
		curr_char = ft_strchr(curr_char + 1, c);
		if (curr_char == NULL)
			break ;
		last_char = curr_char;
	}
	return (last_char);
}
