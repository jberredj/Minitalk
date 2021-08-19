/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:11:36 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:57:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uchar_s1;
	unsigned char	*uchar_s2;

	uchar_s1 = (unsigned char *)s1;
	uchar_s2 = (unsigned char *)s2;
	while (n-- > 0)
		if (*uchar_s1++ != *uchar_s2++)
			return (*--uchar_s1 - *--uchar_s2);
	return (0);
}
