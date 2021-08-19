/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui32_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:40:58 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:02:26 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_to.h"
#include "ft_utils.h"

uint32_t	ft_atoui32_base(const char *str, char *base)
{
	uint32_t	res;
	size_t		base_len;
	int			base_digit;

	base_len = check_base(base);
	if (base_len < 2)
		return (0);
	while (ft_isspace((int)*str))
		str++;
	res = 0;
	while (*str != '\0')
	{
		base_digit = -1;
		while (*str != base[++base_digit] && base_digit < (int)base_len)
		{
		}
		if (!base[base_digit])
			return (0);
		res = (res * base_len) + base_digit;
		str++;
	}
	return (res);
}
