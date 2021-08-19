/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:50:45 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:57:59 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*uchar_dest;
	unsigned char	*uchar_src;
	size_t			i;

	uchar_dest = (unsigned char *)dest;
	uchar_src = (unsigned char *)src;
	i = 0;
	while (n-- > 0)
	{
		uchar_dest[i] = uchar_src[i];
		if (uchar_src[i] == (unsigned char)c)
			return (&uchar_dest[i + 1]);
		i++;
	}
	return (NULL);
}
