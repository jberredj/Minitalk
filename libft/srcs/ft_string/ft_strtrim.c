/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:20:56 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/24 15:29:29 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_len;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && (ft_strchr(set, *(int *)s1) != NULL))
		s1++;
	str_len = ft_strlen(s1);
	while (str_len > 0 && ft_strchr(set, *(int *)(s1 + str_len)))
		str_len--;
	str = ft_substr(s1, 0, str_len + 1);
	return (str);
}
