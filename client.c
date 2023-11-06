/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:17:51 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/07 05:32:06 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_received = 0;

void	send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		usleep(100);
		if (1 & (c >> digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
	}
	if (g_received == 1)
		g_received = 0;
}

void	send_string(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		g_received = 1;
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		exit(0);
	(void)ac;
	pid = (pid_t)ft_atoi(av[1]);
	if (pid < 100 || pid > 99998)
		exit(0);
	send_string(pid, av[2]);
	return (0);
}
