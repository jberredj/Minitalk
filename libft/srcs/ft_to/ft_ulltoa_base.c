/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:32 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:59:32 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	size_t			str_len;
	int				base_len;
	char			*str;

	base_len = check_base(base);
	if (base_len < 2)
		return (NULL);
	str_len = ft_ulllen_base(n, base_len);
	str = (char *)ft_calloc(sizeof(char), (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	while (str_len > 0)
	{
		str[--str_len] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}
