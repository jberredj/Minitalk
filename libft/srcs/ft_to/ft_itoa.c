/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:32 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:59:53 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"

char	*ft_itoa(int n)
{
	unsigned int	us_n;
	int				str_len;
	char			*str;
	short			sign;

	str_len = ft_intlen(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	us_n = (unsigned int)n;
	us_n *= sign;
	str = (char *)ft_calloc(sizeof(char), (str_len + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, str_len + 1);
	str_len--;
	while (str_len >= 0)
	{
		str[str_len] = us_n % 10 + '0';
		us_n = us_n / 10;
		str_len--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
