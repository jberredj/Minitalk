/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:37:53 by jberredj          #+#    #+#             */
/*   Updated: 2021/01/26 10:41:13 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *str)
{
	int	i;
	int	j;

	if (*str == '\0' || str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (-1);
		j = 0;
		while (str[j])
		{
			if (str[j] == str[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}
