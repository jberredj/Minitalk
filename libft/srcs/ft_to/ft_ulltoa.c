/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:32 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:00:30 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"

char	*ft_ulltoa(unsigned long long n)
{
	size_t			str_len;
	char			*str;

	str_len = ft_ulllen(n);
	str = (char *)ft_calloc(sizeof(char), (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	while (str_len > 0)
	{
		str[--str_len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
