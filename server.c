/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:51:54 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/19 16:29:17 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/includes/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	dump_buffer(char *buffer, int *index)
{
	write(1, buffer, *index);
	ft_bzero(buffer, *index);
	*index = 0;
}

void	add_char_to_buffer(char c, char *buffer, int *index)
{
	buffer[*index] = c;
	*index += 1;
	if (*index == BUFFER_SIZE)
		dump_buffer(buffer, index);
}

void	reach_end_of_string(char *buffer, int *index, int pid)
{
	dump_buffer(buffer, index);
	write(1, "\n", 1);
	ft_putstr_fd("reach \\0 from client pid : ", 1);
	ft_putnbr_fd(pid, 1);
	kill(pid, SIGUSR1);
	write(1, "\n", 1);
}

void	receive_char(int sig, siginfo_t *info, void *context)
{
	static int	curr_bit;
	static char	char_to_print;
	static char	buffer[BUFFER_SIZE];
	static int	curr_index;

	(void)context;
	if (sig == SIGUSR1)
		char_to_print |= (0x1 << curr_bit);
	if (curr_bit == 7)
	{
		if (char_to_print == '\0')
			reach_end_of_string(buffer, &curr_index, info->si_pid);
		else
			add_char_to_buffer(char_to_print, buffer, &curr_index);
		char_to_print = 0;
		curr_bit = 0;
	}
	else
		curr_bit++;
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = receive_char;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
