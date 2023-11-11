/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:03:44 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/11 18:09:27 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(void)
{
	ft_putstr_fd("\nERROR : fail to send signal\n", 1);
	exit(1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int				digit = 7;
	static unsigned char	c = 0b00000000;
	int						res;

	(void)context;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		if (signum == SIGUSR1)
			c = (1 << digit) | c;
		if (digit == 0)
		{
			write(1, &c, 1);
			digit = 7;
			c = 0b00000000;
			res = kill(info->si_pid, SIGUSR1);
			if (res == -1)
				error_exit();
		}
		else
			digit--;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd((int)pid, 1);
	ft_putchar_fd('\n', 1);
	ft_memset(&act, 0, sizeof(struct sigaction));
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
