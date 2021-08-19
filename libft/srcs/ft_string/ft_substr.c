/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:16:21 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/14 18:04:43 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	start_len;
	char	*str;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		start_len = ft_strlen(&s[start]);
		if (start_len < len)
			len = start_len;
		str = ft_calloc(sizeof(char), len + 1);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s[start], len + 1);
	}
	else
	{
		str = ft_calloc(sizeof(char), 1);
		*str = '\0';
	}
	return (str);
}
