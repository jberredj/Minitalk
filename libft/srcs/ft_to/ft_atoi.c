/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:40:58 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:03:01 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"

static void	long_max(unsigned long long *res, int *sign)
{
	if (*res >= 9223372036854775807)
	{
		if (*sign == 1)
		{
			*res = 1;
			*sign = -1;
		}
		else
			*sign = 0;
	}
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					digit;
	int					sign;

	while (ft_isspace((int)*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	digit = 0;
	res = 0;
	while (*str != '\0' && ft_isdigit((int)*str))
	{
		digit = *str - '0';
		res = (res * 10) + digit;
		str++;
	}
	long_max(&res, &sign);
	return (res * sign);
}
