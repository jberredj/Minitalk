/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:44:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:56:52 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*uchar_dest;
	unsigned char	*uchar_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	uchar_dest = (unsigned char *)dest;
	uchar_src = (unsigned char *)src;
	if (uchar_dest < uchar_src)
		return (ft_memcpy(uchar_dest, uchar_src, n));
	else
		while (n--)
			uchar_dest[n] = uchar_src[n];
	return (dest);
}
