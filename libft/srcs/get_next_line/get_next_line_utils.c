/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:13:44 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:04:24 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnljoin(char **s1, char *s2)
{
	char	*str;
	size_t	str_len;

	if (*s1 == NULL)
	{
		*s1 = (char *)malloc(sizeof(char));
		if (*s1 == NULL)
			return (-1);
		ft_bzero(s1, 1);
	}
	str_len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * str_len);
	if (str == NULL)
		return (-1);
	ft_strlcpy(str, *s1, str_len);
	ft_strlcat(str, s2, str_len);
	if (*s1 != NULL)
		free(*s1);
	*s1 = str;
	return (0);
}
