/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:31:43 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/21 14:01:00 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_malloc_check(void **p, size_t nmemb, size_t size)
{
	*p = ft_calloc(nmemb, size);
	if (*p != NULL)
		return (nmemb * size);
	else
		return (-1);
}
