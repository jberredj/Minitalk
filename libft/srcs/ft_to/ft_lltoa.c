/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:32 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:00:54 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"

char	*ft_lltoa(long long n)
{
	unsigned long long	us_n;
	int					str_len;
	char				*str;
	short				sign;

	str_len = (int)ft_lllen(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	us_n = (unsigned long long)n;
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
