/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:17:51 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/05 19:46:27 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include <libc.h>

//void	signal_handler()
//{

//}

void	send_char(const pid_t pid, char c)
{
	unsigned int	digit;
	char			*bit;

	digit = 7;
	bit = 0b00000000;

	while (digit >= 0)
	{
		if (1 & (c >> digit))
			kill(pid, SIGUSR1);
		else if (0 & (c >> digit))
			kill(pid, SIGUSR2);
		digit--;
		usleep(50);
	}
}

void	send_string(const pid_t pid, char *str)
{
	printf("%s\n", "2");
	while (*str)
	{
		printf("%s\n", "2");
		send_char(pid, *str);
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	//(void)ac;

	pid = (pid_t)atoi(av[1]);
	printf("%s\n", "1");
	send_string(pid, av[2]);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return (0);
}
