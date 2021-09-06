/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:38:16 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/19 16:29:09 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	server_all_receive(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)sig;
	(void)info;
	ft_putendl_fd("Server received string", 1);
	exit(0);
}

void	display_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd("client pid : ", 1);
	ft_putendl_fd(pid, 1);
	free(pid);
}

int	send_string(char *str, size_t len, int pid)
{
	int		curr_bit;
	int		curr_char;
	int		error;

	curr_char = -1;
	while (++curr_char <= (int)len)
	{
		curr_bit = -1;
		while (++curr_bit < 8)
		{
			if (str[curr_char] & (0x1 << curr_bit))
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			if (error)
				return (-1);
			usleep(600);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putendl_fd("Usage :\n ./client [PID] [STRING]", 1);
		return (0);
	}
	display_pid();
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = server_all_receive;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	if (send_string(argv[2], ft_strlen(argv[2]), ft_atoi(argv[1])))
	{
		ft_putendl_fd("Error.\nWrong PID.", 1);
		return (-1);
	}
	while (1)
		sleep(1);
	return (0);
}
