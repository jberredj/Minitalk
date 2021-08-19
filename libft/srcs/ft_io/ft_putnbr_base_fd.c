/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:05:48 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:53:19 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static int	print_base(long long n, char *str, size_t len, int fd)
{
	unsigned long long	ull_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ull_n = (unsigned long long)n;
		ull_n = -ull_n;
	}
	else
		ull_n = (unsigned long long)(n);
	if (ull_n >= len)
	{
		print_base(ull_n / len, str, len, fd);
	}
	ft_putchar_fd(str[ull_n % len], fd);
	return (0);
}

void	ft_putnbr_base_fd(long long n, char *str, int fd)
{
	size_t			len;

	len = check_base(str);
	if (len < 2)
		return ;
	print_base(n, str, len, fd);
}
