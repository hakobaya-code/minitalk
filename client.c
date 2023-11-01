/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:17:51 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/01 18:48:31 by hakobaya         ###   ########.fr       */
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
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(50);
	}
}

void	send_string(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	//(void)ac;

	pid = (pid_t)ft_atoi(av[1]); //av[0]はなに？av[1]はPID, av[2]はコマンドライン引数の文字たち
	write(1, "ohayo", 5);
	kill(pid, av[2]); //SIGUSR1, SIGUSR2にする
	return (0);
}
