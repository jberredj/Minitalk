/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:14:24 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/14 18:03:11 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	str = NULL;
	len = ft_strlen(s);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s, len + 1);
	return (str);
}
